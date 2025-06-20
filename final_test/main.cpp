#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>

#include "Student_info.h"
#include "Core.h"
#include "Grad.h"
#include "Intl.h"

using namespace std;

int main() {
    vector<Core*> students; 
    Core* record = nullptr;
    char ch;
    string::size_type maxlen = 0;


    while (cin >> ch) {
        if (cin.eof()) break;


        if (ch != 'U' && ch != 'G' && ch != 'I') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            continue;
        }

        if (ch == 'U')
            record = new Core;
        else if (ch == 'G')
            record = new Grad;
        else 
            record = new Intl;


        record->read(cin);

        maxlen = max(maxlen, record->getName().size());

        students.push_back(record);
    }


    sort(students.begin(), students.end(), compare_Core_ptrs);


    for (auto s : students) {
        if (dynamic_cast<Grad*>(s))
            cout << "(G) ";
        else if (dynamic_cast<Intl*>(s))
            cout << "(I) ";
        else
            cout << "(U) ";

        cout << s->getName()
            << string(maxlen + 1 - s->getName().size(), ' ');

        try {
            cout << fixed << setprecision(3) << s->grade() << endl;
        }
        catch (domain_error& e) {
            cout << e.what() << endl;
        }

        delete s;  
    }

    return 0;
}