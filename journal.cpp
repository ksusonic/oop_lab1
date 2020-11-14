#include "journal.h"
#include <fstream>

Journal::Journal(size_t size) :
    collection(SimpleVector<JournalData>(size))
{}

//Journal::Journal(const Journal &oldJournal) :
//    collection(oldJournal.collection) {}
//
//
//Journal::Journal(Journal &&oldJournal) {
//    collection = oldJournal.collection;
//}

void Journal::AddData(const JournalData &data) {
    collection.PushBack(data);
}

void Journal::DeleteData(int index) {
    collection[index].Clear();
}

const JournalData& Journal::GetData(int index) const {
    return collection[index];
}
JournalData& Journal::GetData(int index) {
    return collection[index];
}

void Journal::ClearAll() {
    for (auto i : collection) {
        i.Clear();
    }
}

int Journal::Size() const {
    return collection.Size();
}


void Journal::CheckJournal() const {
    int influence_total = 0;
    for (auto &i : collection) {
        influence_total += i.GetCoffeeAmount();
        if (influence_total < 0) {
            cout << i.GetFullName() << ' ' <<
            "Использовал больше кофе, чем было" << endl;
            return;
        }
    }
    cout << "Все в порядке. Кофе всегда было больше 0." << endl;
}

void Journal::operator=(const Journal &jd) {
    collection = SimpleVector<JournalData>(jd.collection);
}

JournalData Journal::operator[](std::size_t index) {
    return this->collection[index];
}
JournalData Journal::operator[](std::size_t index) const {
    return this->collection[index];
}

void Journal::LoadFromFile(const string &filename) {
    ifstream file;
    try {
        file.open(filename, ios::in);
    } catch (exception& e) {
        cout << "File was not opened, " << e.what();
    }
    string s, fname, mname, lname, position, degree;
    int amount;
    Journal result;
    while (file) {
        getline(file, s, '\n');
        stringstream ss(s);
        getline(ss, fname, '%');
        getline(ss, mname, '%');
        getline(ss, lname, '%');
        getline(ss, position, '%');
        getline(ss, degree, '%');
        ss.ignore();
        ss >> amount;
        result.AddData({fname, mname, lname, position, degree, amount});
    }
}

void Journal::SaveToFile(const string &filename) {
    ofstream file;
    try {
        file.open(filename, ios::out);
    } catch (exception& e) {
        cout << "File was not opened, " << e.what();
    }
    file << this;
}

ostream&operator<<(ostream &os, const Journal&j) {
    for (int i = 0; i < j.Size(); ++i) {
        os << j[i].GetFullName() + '%' +
                j[i].GetDegree() + '%' +
                j[i].GetPosition() + '%' +
                to_string(j[i].GetCoffeeAmount()) + '\n';
    }
    return os;
}