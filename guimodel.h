#ifndef GUIMODEL_H
#define GUIMODEL_H

#include <QObject>
#include <QVariantList>

class GuiModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString macSrc READ getMacSrc WRITE setMacSrc NOTIFY macSrcChanged)
    Q_PROPERTY(QString macDst READ getMacDst WRITE setMacDst NOTIFY macDstChanged)
    Q_PROPERTY(QVariantList devName READ getDevName NOTIFY devNameChanged)

public:
    explicit GuiModel(QObject *parent = nullptr);
    QString getMacSrc() const;
    void setMacSrc(const QString &macSrc);
    QString getMacDst() const;
    void setMacDst(const QString &macDst);
    QVariantList getDevName() const;

signals:
    void macSrcChanged(QString macSrc);
    void macDstChanged(QString macDst);
    void devNameChanged(QVariantList devName);

public slots:
    void sendData(const QString &macSrc, const QString &macDst, const QString &msg);
    void open(const QString &devName);

private:
    QString m_macSrc;
    QString m_macDst;
    QVariantList m_devName;
};

#endif // GUIMODEL_H
