#ifndef __SIMPLE_DATABASE___
#define __SIMPLE_DATABASE___

#include <map>
#include <vector>

class Card {
public:
    long id{};
    std::string description;
    int idUser{};

    Card();
    Card(std::string description, int idUser);
};

class SimpleDataBase {
public:
    SimpleDataBase();
    std::vector<Card> getAll();
    Card createCard(Card card);
    Card findCard(long id);
protected:
    std::map<int, Card> map;
private:
    unsigned long long int id();

};

class SimpleDatabaseHelper : public SimpleDataBase {
public:
    SimpleDatabaseHelper();

    std::map<int, Card> &getReferenceToMap();
};

#endif
