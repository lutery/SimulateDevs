#ifndef DEVINIT_H
#define DEVINIT_H

#include <QObject>

class DevInit : public QObject
{
    Q_OBJECT
public:
    explicit DevInit(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DEVINIT_H