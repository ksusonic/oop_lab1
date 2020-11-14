#include "journal.h"
#include <fstream>

// Раздел ТЕСТОВ:
void TestConstructor() {
    JournalData jdDefault;
    AssertEqual(jdDefault.GetFullName(), "No name", "пустой конструктор по-умолчанию");
    AssertEqual(jdDefault.GetPosition(), "No position", "позиция пустого");
    AssertEqual(jdDefault.GetDegree(), "No degree", "степень пустого");
    JournalData jdInit("Daniil", "Andreevich", "Moiseev", "Student", "Bachelor");
    AssertEqual(jdInit.GetFullName(), "Daniil Andreevich Moiseev", "конструктор инициализации");
    AssertEqual(jdInit.GetPosition(), "Student", "позиция");
    AssertEqual(jdInit.GetDegree(), "Bachelor", "степень");
    JournalData jdCopy(jdInit);
    AssertEqual(jdCopy.GetFullName(), "Daniil Andreevich Moiseev", "конструктор инициализации");
    AssertEqual(jdCopy.GetPosition(), "Student", "позиция");
    AssertEqual(jdCopy.GetDegree(), "Bachelor", "степень");
}

void TestChangeCoffeeAmount() {
    JournalData jd("Daniil", "Andreevich", "Moiseev", "Student", "Bachelor");
    jd.ChangeCoffeAmount(40);
    AssertEqual(jd.GetCoffeeAmount(), 40, "Прибавили 40");
    jd.ChangeCoffeAmount(-20);
    AssertEqual(jd.GetCoffeeAmount(), 20, "Убавили 20 и получилось 20");
}

void TestJournal() {
    JournalData Monday("Monahov", "Ivan", "Sergeevich", "Worker", "Bachleor");
    JournalData Tuesday(Monday);
    Journal J;
    J.AddData(Monday);
    J.AddData(Tuesday);
    J.SaveToFile("data.txt");

}

int main() {
    TestRunner tr;
    tr.RunTest(TestConstructor, "Тестирование конструкторов");
    tr.RunTest(TestChangeCoffeeAmount, "Изменение кол-ва кофе");
    tr.RunTest(TestJournal, "Тестирование журнала");

    return 0;
}
