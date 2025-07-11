#pragma once
#ifndef GUARD_Core_h
#define GUARD_Core_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Core {
public:
    Core() : midterm(0), final(0) { }
    Core(istream& is) { read(is); }

    string getName() const;
    virtual double grade() const;
    virtual istream& read(istream&);
    virtual ~Core() { }

protected:
    istream& read_common(istream& in);
    double midterm, final;
    vector<double> homework;
    virtual Core* clone() const { return new Core(*this); }

private:
    string name;
    friend class Student_info;
};

bool compare(const Core&, const Core&);
bool compare_grades(const Core&, const Core&);
bool compare_Core_ptrs(const Core*, const Core*);

#endif