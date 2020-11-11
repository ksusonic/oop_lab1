#include "journal.h"

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
