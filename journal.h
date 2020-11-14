#pragma once
#include "journaldata.h"
#include "SimpleVector.h"

// Коллекция Одномерный массив (Вектор)
class Journal {
public:
    Journal() = default;
    Journal(size_t size);
//    Journal(const Journal &oldJournal);
//    Journal(Journal &&oldJournal);

    void AddData(const JournalData &data);
    void DeleteData(int index);

    const JournalData &GetData(int index) const;    // константная версия ссылки на элемент
    JournalData &GetData(int index);

    void ClearAll();
    int Size() const;
    JournalData operator[](std::size_t index);
    JournalData operator[](std::size_t index) const;

    void SaveToFile(const string &filename);
    void LoadFromFile(const string &filename);

    void CheckJournal() const;
    void operator=(const Journal& jd);

private:
    SimpleVector<JournalData> collection;
};

ostream &operator<<(ostream &os, const Journal&J);
