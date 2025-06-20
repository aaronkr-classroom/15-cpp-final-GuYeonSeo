#pragma once
#ifndef GUARD_Intl_h
#define GUARD_Intl_h

#include <iostream>
#include "Core.h"

using namespace std;

class Intl : public Core {
public:
    Intl() : language_score(0) { }
    Intl(istream& is) { read(is); }

    double grade() const override;
    istream& read(istream&) override;

protected:
    double language_score;
    Intl* clone() const override { return new Intl(*this); }
};

#endif