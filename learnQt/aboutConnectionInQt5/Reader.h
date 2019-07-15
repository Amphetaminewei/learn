#ifndef READER_H
#define READER_H
#include <QObject>
#include <QDebug>
#include <QDate>

class Reader : public QObject
{
    Q_OBJECT
public:
    Reader();
    void receiveNewspaper(const QString &name);
    //void receiveNewspaper(const QString &name, const QDate &date = QDate::currentDate());
};

#endif // READER_H
