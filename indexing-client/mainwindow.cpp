#include <QMessageBox>
#include <QRemoteObjectNode>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , remoteObjectNode_(new QRemoteObjectNode(REMOTE_OBJECT_REGISTRY, this))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_sendButton_clicked()
{
    if (indexingService_.isNull()) {
        indexingService_.reset(remoteObjectNode_->acquire<IndexingServiceReplica>());
        connect(indexingService_.get(), &IndexingServiceReplica::response, this, &MainWindow::updateResults);
    }

//    if (indexingService_->isReplicaValid()) {
        indexingService_->request(ui->urlEdit->text(), ui->depthBox->value());
//    } else {
//        QMessageBox::warning(this, "Error de conexion", "No se pudo conectar con el servicio");
//    }
}

void MainWindow::updateResults (const QUrl& url)
{
    ui->results->append(url.toString() + '\n');
}
