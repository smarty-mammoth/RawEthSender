#include "NativeFunctions.h"


QSet<QString> getEthernetInterfaces() {
    QSet<QString> ifNames;
    ifaddrs *ifAddrs;
    if (getifaddrs(&ifAddrs) < 0) throw IOException("Cannot get ethernet interfaces.");

    auto curr = ifAddrs;
    while(curr) {
        ifNames.insert(QString::fromUtf8(curr->ifa_name));
        curr = curr->ifa_next;
    }
    freeifaddrs(ifAddrs);
    return ifNames;
}
