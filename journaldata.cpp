#include "journaldata.h"

JournalData::JournalData(string f_name, string m_name, string l_name,
                          string pos, string deg, int influenceMade)
    : firstName(f_name),
      middleName(m_name),
      lastName(l_name),
      position(pos),
      degree(deg),
      influence(influenceMade)
{}

/*JournalData::JournalData(const JournalData &data) :
    firstName(data.firstName),
    middleName(data.middleName),
    lastName(data.lastName),
    position(data.position),
    degree(data.degree),
    influence(data.influence)
{}
// используем списки инициализации

JournalData::JournalData(JournalData &&data) :
        firstName(data.firstName),
        middleName(data.middleName),
        lastName(data.lastName),
        position(data.position),
        degree(data.degree),
        influence(data.influence)
{}*/
// используем списки инициализации

string JournalData::GetFullName() const {
    if (firstName.empty() || middleName.empty() || lastName.empty()) {
    return "No name";
    } else return firstName + ' ' + middleName + ' ' + lastName;
} // не меняет поля имен в классе

string JournalData::GetPosition() const {
    if (position.empty())
        return "No position";
    return position;
}


string JournalData::GetDegree() const {
    if (degree.empty())
        return "No degree";
    return degree;
}

void JournalData::ChangeCoffeAmount(const int madeInfluence) {
    influence += madeInfluence;
}

int JournalData::GetCoffeeAmount() const {
    return influence;
}

void JournalData::Clear() {
    firstName.clear();
    middleName.clear();
    lastName.clear();
    position.clear();
    degree.clear();
    influence = 0;
}
