#include "guimodel.h"
#include <QDebug>
#include "NativeFunctions.h"

GuiModel::GuiModel(QObject *parent) : QObject(parent)
{
    auto res = getEthernetInterfaces();

    for (auto it = res.begin(); it != res.end(); it++) {
        qDebug() << "If " << *it;
    }

    m_macDst = "FF:00:00:00:00:FF";
    m_macSrc = "FF:FF:AA:AA:FF:FF";
    m_devName.append("eth0");
    m_devName.append("eth1");
    m_devName.append("loopback");
}

QString GuiModel::getMacSrc() const
{
    return m_macSrc;
}

void GuiModel::setMacSrc(const QString &macSrc)
{
    if (m_macSrc == macSrc)
        return;

    m_macSrc = macSrc;
    emit macSrcChanged(m_macSrc);
}

QString GuiModel::getMacDst() const
{
    return m_macDst;
}

void GuiModel::setMacDst(const QString &macDst)
{
    if (m_macDst == macDst)
        return;

    m_macDst = macDst;
    emit macDstChanged(m_macDst);
}

QVariantList GuiModel::getDevName() const {
    return m_devName;
}

void GuiModel::open(const QString &devName) {
    qDebug() << "Open device " << devName;
}

void GuiModel::sendData(const QString &macSrc, const QString &macDst, const QString &msg) {
    qDebug() << "Send " << msg << " from " << macSrc << " to " << macDst;
}
