#pragma once
#ifndef GUARD_Grad_h
#define GUARD_Grad_h

#include <iostream>
#include "Core.h"

using namespace std;

class Grad : public Core {
public:
    Grad() : thesis(0) { }
    Grad(istream& is) { read(is); }

    double grade() const override;
    istream& read(istream&) override;

protected:
    double thesis;
    Grad* clone() const override { return new Grad(*this); }
};

#endif