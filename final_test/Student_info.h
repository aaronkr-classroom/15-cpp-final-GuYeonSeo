#pragma once
#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include "Core.h"
#include "Grad.h"
#include "Intl.h"

using namespace std;

class Student_info {
private:
    Core* cp;

public:
    Student_info() : cp(0) { }
    Student_info(istream& is) : cp(0) { read(is); }
    Student_info(const Student_info&);
    Student_info& operator=(const Student_info&);
    ~Student_info() { delete cp; }

    string get_name() const {
        if (cp) return cp->getName();
        else throw runtime_error("Uninitialized student!");
    }
    istream& read(istream&);
    double grade() const {
        if (cp) return cp->grade();
        else throw runtime_error("Uninitialized student!");
    }

    static bool compare(const Student_info&, const Student_info&);
};

#endif