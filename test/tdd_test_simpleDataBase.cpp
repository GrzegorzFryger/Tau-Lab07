#include <catch2/catch.hpp>
#include <simpleDataBase.hpp>

TEST_CASE("check if a method exists") {
    //given
    SimpleDatabaseHelper database = SimpleDatabaseHelper();

    REQUIRE_NOTHROW(database.getAll());
}

TEST_CASE("test getAll method") {
    //SetUp
    SimpleDatabaseHelper database = SimpleDatabaseHelper();

    SECTION("fresh class should not have any elements ") {
        REQUIRE(database.getAll().empty());
    }

    SECTION("should return all objects, when map is not empty") {
        //given
        Card card = Card("test ", 1);
        std::map<int, Card> *maps = &database.getReferenceToMap();
        maps->insert(std::pair<int, Card>(1, card));

        //then
        REQUIRE(database.getAll().size() == 1);
        REQUIRE(database.getAll()[0].id == 1);
        REQUIRE(database.getAll()[0].description == card.description);
        REQUIRE(database.getAll()[0].idUser == card.idUser);
    }

}

TEST_CASE("check if create method exists") {
    //given
    SimpleDatabaseHelper database = SimpleDatabaseHelper();
    Card card = Card("test ", 1);

    REQUIRE_NOTHROW(database.createCard(card));
}

TEST_CASE("test create method") {
    //given
    SimpleDatabaseHelper database = SimpleDatabaseHelper();
    Card card = Card("test", 1);

    SECTION("should return created object") {
        //when
        auto createdCard = database.createCard(card);
        //then
        REQUIRE(createdCard.idUser == 1);
        REQUIRE(createdCard.description == "test");
    }

    SECTION("should assign id to card") {
        //when
        auto createdCard = database.createCard(card);
        //then
        REQUIRE(createdCard.id == 2);
    }

    SECTION("should contains 2 elements in map") {
        //when
        database.createCard(card);
        database.createCard(card);
        auto size = database.getReferenceToMap().size();
        //then
        REQUIRE(size == 2);
    }
}

TEST_CASE("test find method") {
    //given
    SimpleDatabaseHelper database = SimpleDatabaseHelper();
    Card card = Card("test", 1);
    card.id = 1;

    SECTION("should throw exception when object with id not found") {
        //then
        REQUIRE_THROWS(database.findCard(2));
    }

    SECTION("should get object with id") {
        Card cardToInsert = Card("test", 1);
        cardToInsert.id = 2;
        std::map<int, Card> *maps = &database.getReferenceToMap();
        maps->insert(std::pair<int, Card>(cardToInsert.id, cardToInsert));

        //when
        auto createdCard = database.findCard(2);
        //then
        REQUIRE(createdCard.id == 2);
        REQUIRE(createdCard.idUser == 1);
        REQUIRE(createdCard.description == "test");
    }
}

TEST_CASE("check if remove method exists") {
    //given
    SimpleDatabaseHelper database = SimpleDatabaseHelper();
    //then
    REQUIRE_NOTHROW(database.removeCard(1));
}

TEST_CASE("should remove card from map") {
    SimpleDatabaseHelper database = SimpleDatabaseHelper();
    Card card = Card("test ", 1);
    card.id = 1;
    std::map<int, Card> *maps = &database.getReferenceToMap();
    maps->insert(std::pair<int, Card>(card.id, card));

    //when
    database.removeCard(1);

    REQUIRE(database.getAll().empty());

}




