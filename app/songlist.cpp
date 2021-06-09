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
    if(player!=NULL)
    {
        if(is_played)
            player->pause();
        delete player;
    }
    player = new QMediaPlayer;        
    player->setMedia(QUrl::fromLocalFile(QDir::toNativeSeparators(dir+"/"+sng->text()+".mp3")));
    player->setVolume(100);    
    is_played = 0;
    active_song = sng;
    QObject::connect(player,&QMediaPlayer::stateChanged,this,&SongList::change);
    player->play();
}
void SongList::pause(QListWidgetItem* sng)
{
    if(active_song!=sng) return;
    if(is_played)
        player->pause();      
    else    
        player->play();       
}
void SongList::change()
{
    if(is_played)
        active_song->setIcon(QIcon(":/play.png"));
    else
        active_song->setIcon(QIcon(":/pause.png"));
    is_played = (is_played)?0:1;
}
