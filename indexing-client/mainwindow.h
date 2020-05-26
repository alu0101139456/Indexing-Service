#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRemoteObjectNode>

#include <rep_indexingservice_replica.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    const QString REMOTE_OBJECT_REGISTRY = QStringLiteral("local:registry");

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sendButton_clicked();
    void updateResults(const QUrl &url);

private:
    Ui::MainWindow *ui;
    QRemoteObjectNode* remoteObjectNode_;
    QScopedPointer<IndexingServiceReplica, QScopedPointerDeleteLater> indexingService_;
};
#endif // MAINWINDOW_H
