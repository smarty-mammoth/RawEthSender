#ifndef NATIVEFUNCTIONS_H
#define NATIVEFUNCTIONS_H

#include <QException>
#include <QSet>
#include <sys/ioctl.h>
#include <ifaddrs.h>

class IOException : public QException {
public:
    QString m_msg;
    IOException(const QString &msg) : m_msg(msg){}
    QString getMsg() const {
        return m_msg;
    }
    // exception interface
public:
    const char *what() const noexcept  {
        return qPrintable(m_msg);
    }
};

QSet<QString> getEthernetInterfaces();

#endif // NATIVEFUNCTIONS_H

