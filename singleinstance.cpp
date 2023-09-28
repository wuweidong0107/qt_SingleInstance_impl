#include <QtNetwork/QLocalSocket>
#include "singleinstance.h"

SingleInstance::SingleInstance(const QString &name, QObject *parent)
    : QObject(parent), m_Name(name)
{
    
}

bool SingleInstance::start()
{
    m_Server.removeServer(m_Name);
    return m_Server.listen(m_Name);
}

bool SingleInstance::hasPreviousInstance()
{
    QLocalSocket socket;
    socket.connectToServer(m_Name);
    return socket.waitForConnected();
}

QString SingleInstance::getLastErrorString() const
{
    return m_Server.errorString();
}

void SingleInstance::onNewConnection()
{
    emit newInstanceCreated();
}
