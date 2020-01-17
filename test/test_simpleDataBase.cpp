#include <catch2/catch.hpp>
#include <simpleDataBase.hpp>

TEST_CASE("simple test to check if a method exists") {
    //given
    SimpleDatabaseHelper database = SimpleDatabaseHelper();

    REQUIRE_NOTHROW(database.getAll());
}

TEST_CASE("simple test, getAll method") {
    //SetUp
    SimpleDatabaseHelper database = SimpleDatabaseHelper();

    SECTION( "fresh class should not have any elements " ) {
        REQUIRE(database.getAll().empty());
    }

    SECTION( "Should return all objects, when map is not empty" ) {
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

TEST_CASE("simple test to check if a create method exists") {
    //given
    SimpleDatabaseHelper database = SimpleDatabaseHelper();
    Card card = Card("test ", 1);

    REQUIRE_NOTHROW(database.createCard(card));
}

TEST_CASE("test create method") {
    //given
    SimpleDatabaseHelper database = SimpleDatabaseHelper();
    Card card = Card("test", 1);

    SECTION( "should return created object" ) {
        //when
        auto  createdCard = database.createCard(card);
        //then
        REQUIRE(createdCard.idUser == 1);
        REQUIRE(createdCard.description == "test");
    }

    SECTION( "should assign id to card" ) {
        //when
        auto  createdCard = database.createCard(card);
        //then
        REQUIRE(createdCard.id == 2);
    }

    SECTION( "should contains 2 elements in map" ) {
        //when
        database.createCard(card);
        database.createCard(card);
        auto  size = database.getReferenceToMap().size();
        //then
        REQUIRE(size == 2);
    }
}






