#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include <QDir>
#include <QUrl>
#include <QThread>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);   
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_open_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::Directory);
    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();
    songlist.set_dir(fileNames);
    on_refresh_clicked();

}

void MainWindow::on_refresh_clicked()
{
    ui->snglst->clear();
    songlist.refresh();
    QString sng;
    while(songlist.hasNext())
    {
        sng = songlist.next();
        QListWidgetItem* tmp = new QListWidgetItem(QIcon(":/play.png"),sng);
        ui->snglst->addItem(tmp);
    }
}

void MainWindow::on_snglst_itemDoubleClicked(QListWidgetItem *item)
{
    songlist.play(item);
}

void MainWindow::on_snglst_itemClicked(QListWidgetItem *item)
{
    songlist.pause(item);
}
