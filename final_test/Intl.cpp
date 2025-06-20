#include <algorithm>
#include <vector>
#include "Intl.h"

istream& read_hw(istream& in, vector<double>& hw);

istream& Intl::read(istream& in) {
    Core::read_common(in);
    in >> language_score;
    read_hw(in, homework);
    return in;
}

double Intl::grade() const {
    return min(Core::grade(), language_score);
}