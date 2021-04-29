#ifndef NATIVEFUNCTIONS_H
#define NATIVEFUNCTIONS_H

#include <QException>
#include <QSet>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <unistd.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <net/if.h>

class IOException : public QException {
public:
    QString m_msg;
    int m_code;
    IOException(const int &code, const QString &msg) : m_msg(msg){
        m_code = code;
    }
    QString getMsg() const {
        return m_msg;
    }
    // exception interface
public:
    const char *what() const noexcept  {
        return qPrintable(QString("%1 (code: %2)").arg(m_msg).arg(m_code));
    }
};

QSet<QString> getEthernetInterfaces();
QString getMacAddr(QString eth);

#endif // NATIVEFUNCTIONS_H

