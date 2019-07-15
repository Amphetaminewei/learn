#include "Reader.h"

Reader::Reader() {}

void Reader::receiveNewspaper(const QString &name) {
    qDebug() << "received newspaper:" << name;
}
