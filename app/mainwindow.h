#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "songlist.h"
#include <QListWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_open_clicked();

    void on_refresh_clicked();

    void on_snglst_itemDoubleClicked(QListWidgetItem *item);    

    void on_snglst_itemPressed(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    SongList songlist;
};
#endif // MAINWINDOW_H
