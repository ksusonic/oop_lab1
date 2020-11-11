#include "journal.h"

int main() {
//    TestRunner tr;
//    tr.RunTest(TestConstructor, "Тестирование конструкторов");
//    tr.RunTest(TestChangeCoffeeAmount, "Изменение кол-ва кофе");
    JournalData Monday("Monahov", "Ivan", "Sergeevich", "Worker", "Bachleor");
    JournalData Tuesday(Monday);

    Journal j;

    {
        auto journal = Journal(3);
        std::cout << "test11\n";
    }
    std::cout << "test\n";


    return 0;
}
