#include "Newspaper.h"

Newspaper::Newspaper(const QString & name): m_name(name) {}

void Newspaper::sendSignals() const {
    emit newPaper(m_name);
}
