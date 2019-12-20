#ifndef BLUETOOTHMANAGER_H
#define BLUETOOTHMANAGER_H

#include <QObject>
#include <QMutex>
#include <QDataStream>
#include <qbluetoothlocaldevice.h>
#include <QBluetoothSocket>
#include <iostream>
#include <thread>

QT_FORWARD_DECLARE_CLASS(QBluetoothDeviceDiscoveryAgent)
QT_FORWARD_DECLARE_CLASS(QBluetoothDeviceInfo)

QT_USE_NAMESPACE


class BluetoothManager : public QObject
{
    Q_OBJECT

public:
    BluetoothManager();
    ~BluetoothManager();

    static BluetoothManager* getInstance();
    QMutex m_mutex{};
    void scan();
    void connectBle(const QBluetoothAddress &);
    void disconnectBle();
    bool isConnected();
    bool send(const QString &);
    QString checkData();
    QString readData(const QString &);

public: signals:
    void dataReceived(QString &);
    void stateChanged(QString &);
    void bleConnected();
    void bleDisconnected();
    void addDeviceToList(const QBluetoothAddress&, const QString&);

public slots:
    void addDevice(const QBluetoothDeviceInfo&);

private slots:
    void scanFinished();
    void connected();
    void disconnected();
    void socketError(QBluetoothSocket::SocketError error);    
    void readyRead();

private:
    bool m_connected{false};  
    QBluetoothSocket* socket{};
    QByteArray byteblock{};
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
    QBluetoothLocalDevice *localDevice;
    pthread_t m_discoveryThread{};
    static void *discoveryThread(void * this_ptr);
    static BluetoothManager* theInstance_;
};

#endif // BLUETOOTHMANAGER_H