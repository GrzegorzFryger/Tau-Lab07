#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <catch2/catch.hpp>
#include <simpleDataBase.hpp>

SCENARIO("Can remove elements from DataBase, but do not remove other") {

    GIVEN("A two cars with id: 1 and 2 ") {
        SimpleDatabaseHelper database = SimpleDatabaseHelper();
        Card card = Card("test1", 1);
        card.id = 1;

        Card card2 = Card("test2", 1);
        card2.id = 2;

        std::map<int, Card> *maps = &database.getReferenceToMap();
        maps->insert(std::pair<int, Card>(card.id, card));
        maps->insert(std::pair<int, Card>(card2.id, card2));

        REQUIRE(maps->size() == 2);

        WHEN("Remove elements with id 1") {
            database.removeCard(1);

            THEN( "Amount elements into database equals 1" ) {

                REQUIRE( database.getAll().size() == 1 );
            }

            THEN( "Second element still is in database" ) {

                REQUIRE( database.findCard(2).id == 2 );
            }
        }

    }
}