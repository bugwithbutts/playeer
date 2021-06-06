#include "songlist.h"
#include <QMediaPlayer>
#include <QDir>
#include <QUrl>
#include <QThread>
#include <QFileDialog>
#include <QDirIterator>
SongList::SongList()
{
    dir = "./";
    songiter = -1;
    active_song = NULL;
    player = NULL;
}
void SongList::refresh()
{
    songs.clear();
    QDirIterator go(dir,QDirIterator::NoIteratorFlags);
    while(go.hasNext())
    {
        QFile f(go.next());
        QFileInfo fi(f);
        if(!fi.isFile()) continue;
        QRegExp form("*.mp3");
        form.setPatternSyntax(QRegExp::Wildcard);
        if(form.exactMatch(f.fileName()))
        {
            songs.append(fi.baseName());
        }
    }
    songs.sort();
    songiter = -1;
    if(player!=NULL) delete player;
    player = NULL;
    active_song = NULL;
}
void SongList::set_dir(QStringList str)
{
    dir = str.at(0);
}
bool SongList::hasNext()
{
    songiter++;
    if(songiter==songs.size()) return 0;
    return 1;
}
QString SongList::next()
{
    return songs.at(songiter);
}
void SongList::play(QListWidgetItem* sng)
{
    sng->setIcon(QIcon(":/pause.png"));
    if(player!=NULL) delete player;
    player = new QMediaPlayer;    
    player->setMedia(QUrl::fromLocalFile(QDir::toNativeSeparators(dir+"/"+sng->text()+".mp3")));
    player->setVolume(100);
    player->play();
    is_played = 1;
    if(active_song!=NULL)
        active_song->setIcon(QIcon(":/play.png"));
    active_song = sng;
}
void SongList::pause(QListWidgetItem* sng)
{
    if(active_song!=sng) return;
    if(is_played)
    {
        player->pause();
        sng->setIcon(QIcon(":/play.png"));
        is_played = 0;
    }
    else
    {
        player->play();
        sng->setIcon(QIcon(":/pause.png"));
        is_played = 1;
    }
}
