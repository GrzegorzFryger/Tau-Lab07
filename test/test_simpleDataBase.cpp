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

