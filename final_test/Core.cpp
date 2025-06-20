#include "Core.h"
#include <stdexcept>
#include <algorithm>
#include <numeric>

string Core::getName() const { return name; }

istream& Core::read_common(istream& in) {
    in >> name >> midterm >> final;
    return in;
}

istream& Core::read(istream& in) {
    read_common(in);
    homework.clear();
    double x;
    while (in >> x) {
        homework.push_back(x);
    }
    in.clear(); 
    return in;
}
istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        hw.clear();
        double x;
        while (in >> x)
            hw.push_back(x);

        in.clear(); 
    }
    return in;
}

double Core::grade() const {
    if (homework.empty())
        throw domain_error("No homework grades");

    double hw_avg = accumulate(homework.begin(), homework.end(), 0.0) / homework.size();
    return 0.2 * midterm + 0.4 * final + 0.4 * hw_avg;
}

bool compare(const Core& a, const Core& b) { return a.getName() < b.getName(); }
bool compare_grades(const Core& a, const Core& b) { return a.grade() < b.grade(); }
bool compare_Core_ptrs(const Core* a, const Core* b) { return a->getName() < b->getName(); }