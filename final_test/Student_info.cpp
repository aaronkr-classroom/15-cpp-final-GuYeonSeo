#include "Student_info.h"
#include <stdexcept>

Student_info::Student_info(const Student_info& s) : cp(0) {
    if (s.cp) cp = s.cp->clone();
}

Student_info& Student_info::operator=(const Student_info& s) {
    if (&s != this) {
        delete cp;
        cp = s.cp ? s.cp->clone() : 0;
    }
    return *this;
}

istream& Student_info::read(istream& is) {
    delete cp;
    cp = nullptr;

    char ch;
    is >> ch;

    if (ch == 'U')
        cp = new Core(is);
    else if (ch == 'G')
        cp = new Grad(is);
    else if (ch == 'I')
        cp = new Intl(is);
    else
        throw runtime_error("Unknown student type");

    return is;
}

bool Student_info::compare(const Student_info& a, const Student_info& b) {
    return a.get_name() < b.get_name();
}
