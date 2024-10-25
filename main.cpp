#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "dbusserver.h"
#include <QtDBus/QDBusConnection>
#include "cluster_adaptor.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    DBusServer* dbusServer = new DBusServer(&app);
    qmlRegisterSingletonInstance("experion.server.dbus", 1, 0, "MyDBusServer", dbusServer);

    new DbusAdaptor(dbusServer);
    QDBusConnection::sessionBus().registerObject("/experion/server/dbus", dbusServer);
    QDBusConnection::sessionBus().registerService("experion.server.dbus");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
