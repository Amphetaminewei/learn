#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>

class Newspaper : public QObject
{
    Q_OBJECT
public:
    Newspaper(const QString & name);

    void sendSignals() const;

    signals:
        void newPaper(const QString &name) const;
        void newPaper(const QString &name, const QDate &date);
        //重载一个信号，这时我们的编译器不知道在connect中应该用哪个了
private:
        QString m_name;
};

#endif // NEWSPAPER_H
