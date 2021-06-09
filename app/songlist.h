#ifndef SONGLIST_H
#define SONGLIST_H
#include <QDir>
#include <QListWidget>
#include <QMediaPlayer>
#include <QUrl>
#include <QThread>
#include <QFileDialog>
class SongList: public QObject
{
    Q_OBJECT
public slots:
    void change();
public:
    SongList();
    void set_dir(QStringList str);
    void refresh();
    bool hasNext();
    void pause(QListWidgetItem* sng);
    QString next();    
    void play(QListWidgetItem* sng);
    ~SongList(){};
private:
    QString dir;
    QStringList songs;
    int songiter;
    QListWidgetItem* active_song;
    QMediaPlayer *player;
    bool is_played;
};


#endif // SONGLIST_H
