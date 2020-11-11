#include "test_runner.h"                    // отдельная библиотка для тестирования

using namespace std;

class JournalData{
public:
    JournalData();
    JournalData(string fname, string mname, string lname,
                string position, string degree, int influenceMade = 0);
//    JournalData(const JournalData &data);
//    JournalData(JournalData &&data);
//    JournalData& operator=(const JournalData &) = default;
//    JournalData& operator=(JournalData &&) = default;

    // селекторы
    string GetFullName() const;
    string GetPosition() const;
    string GetDegree() const;
    int GetCoffeeAmount() const;

    // модификатор
    void ChangeCoffeAmount(const int madeInfluence);
    void Clear();

private:
    string firstName, middleName, lastName; // Имя, Отчество, Фамилия
    string position, degree;
    int influence = 0;                      // инициализация 0
};

void TestConstructor();
void TestChangeCoffeeAmount();