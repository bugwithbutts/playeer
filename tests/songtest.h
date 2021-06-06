#ifndef SONGTEST_H
#define SONGTEST_H
#include <gtest/gtest.h>
#include "songlist.h"
#include <QDebug>
#include <string>
#include <algorithm>
TEST(findsong,songlist)
{
    SongList s;
    QDir dir;
    dir.mkdir("tst");
    QFile f1("tst/1.mp3"),
    f2("tst/2.mp3"),
    f3("tst/3.mp3");
    f1.open(QIODevice::WriteOnly);
    f2.open(QIODevice::WriteOnly);
    f3.open(QIODevice::WriteOnly);
    f1.close();
    f2.close();
    f3.close();
    s.set_dir(QStringList("tst"));
    s.refresh();
    std::string ss = "";
    while(s.hasNext())
    {
        ss += (s.next()).toStdString();
        ss += " ";
    }
    std::string str = "1 2 3 ";
    ASSERT_STREQ(ss.c_str(),str.c_str());
}
TEST(nosong,songlist)
{    
    QDir dir;
    dir.mkdir("tst");
    QFile f1("tst/1.mp3"),
    f2("tst/2.mp3"),
    f3("tst/3.mp3");
    f1.open(QIODevice::WriteOnly);
    f2.open(QIODevice::WriteOnly);
    f3.open(QIODevice::WriteOnly);
    f1.close();
    f2.close();
    f3.close();
    dir.mkdir("tst2");
    SongList s;
    s.set_dir(QStringList("tst"));
    s.refresh();
    s.set_dir(QStringList("tst2"));
    s.refresh();
    std::string ss = "";
    while(s.hasNext())
    {
        ss += (s.next()).toStdString();
        ss += " ";
    }
    std::string str = "";
    ASSERT_STREQ(ss.c_str(),str.c_str());
}
#endif // SONGTEST_H
