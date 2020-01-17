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

}


Card::Card() = default;

Card::Card(std::string description, int idUser) : description(std::move(description)), idUser(idUser) {}

SimpleDatabaseHelper::SimpleDatabaseHelper() : SimpleDataBase() {
}

std::map<int, Card> &SimpleDatabaseHelper::getReferenceToMap() {
    return map;
}
