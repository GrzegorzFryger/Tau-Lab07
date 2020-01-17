#include <simpleDataBase.hpp>
#include <algorithm>
#include <utility>

SimpleDataBase::SimpleDataBase() = default;

std::vector<Card> SimpleDataBase::getAll() {
    std::vector<Card> cards;

    std::for_each(map.begin(), map.end(), [&](std::pair<const int, Card> &element) {
        element.second.id = element.first;
        cards.push_back(element.second);
    });

    return cards;
}

Card SimpleDataBase::createCard(Card card) {
    card.id = id();
    map.insert(std::pair<int, Card>(card.id, card));
    return map[card.id];
}

unsigned long long int SimpleDataBase::id() {
    static unsigned long long int n = 0;
    return ++n;
}

Card SimpleDataBase::findCard(long id) {
    std::map<int, Card>::iterator it;
    it = map.find(id);

    if (it == map.end()) {
        throw std::invalid_argument("Not found");
    }

    return map.find(id)->second;
}

void SimpleDataBase::removeCard(long id) {

}


Card::Card() = default;

Card::Card(std::string description, int idUser) : description(std::move(description)), idUser(idUser) {}

SimpleDatabaseHelper::SimpleDatabaseHelper() : SimpleDataBase() {
}

std::map<int, Card> &SimpleDatabaseHelper::getReferenceToMap() {
    return map;
}
