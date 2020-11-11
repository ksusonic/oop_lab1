#pragma once
#include "journaldata.h"
#include "SimpleVector.h"
#include "fstream"

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

    void CheckJournal() const;
    JournalData operator=(const JournalData& jd);

private:
    SimpleVector<JournalData> collection;
};
