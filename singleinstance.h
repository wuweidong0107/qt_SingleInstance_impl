#ifndef SINGLEINSTANCE_H
#define SINGLEINSTANCE_H

#include <QObject>
#include <QtNetwork/QLocalServer>

class SingleInstance : public QObject
{
    Q_OBJECT
public:
    explicit SingleInstance(const QString& name, QObject *parent = nullptr);
    bool start();
    bool hasPreviousInstance();
    QString getLastErrorString() const;
    
Q_SIGNALS:
    void newInstanceCreated();
    
private Q_SLOTS:
    void onNewConnection();
    
private:
    QLocalServer m_Server;
    QString m_Name;
};

#endif // SINGLEINSTANCE_H
