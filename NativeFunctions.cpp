#include "NativeFunctions.h"


QSet<QString> getEthernetInterfaces() {
    QSet<QString> ifNames;
    ifaddrs *ifAddrs;
    if (getifaddrs(&ifAddrs) < 0) throw IOException(errno, "Cannot get ethernet interfaces.");

    auto curr = ifAddrs;
    while(curr) {
        ifNames.insert(QString::fromUtf8(curr->ifa_name));
        curr = curr->ifa_next;
    }
    freeifaddrs(ifAddrs);
    return ifNames;
}

QString getMacAddr(QString eth) {
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    if (sock < 0) throw IOException(errno, "Cannot create socket.");
//    ifconf *conf;
    ifreq req;
    memset(&req, 0, sizeof(ifreq));
    memcpy(req.ifr_ifrn.ifrn_name, qPrintable(eth), IFNAMSIZ-1);
    if (ioctl(sock, SIOCGIFHWADDR, &req) == -1) throw IOException(errno, "Cannot get mac address for " + eth);
    sockaddr &addr = req.ifr_hwaddr;
    close(sock);
    return QString("%1:%2:%3:%4:%5:%6")
            .arg((int)addr.sa_data[0], 2, 16)
            .arg((int)addr.sa_data[1], 0, 16)
            .arg((int)addr.sa_data[2], 0, 16)
            .arg((int)addr.sa_data[3], 0, 16)
            .arg((int)addr.sa_data[4], 0, 16)
            .arg((int)addr.sa_data[5], 0, 16);
}
