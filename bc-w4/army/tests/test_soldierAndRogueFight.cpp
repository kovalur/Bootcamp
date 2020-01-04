#include "../unit/Soldier.h"
#include "../unit/Rogue.h"
#include "catch.hpp"

TEST_CASE( "soldier and rogue can attack each other", "[soldier][rogue]" ) {
    Soldier soldier = Soldier("Simple Slodier", 100, 10);
    Rogue rogue = Rogue("Simple Rogue", 80, 15);
    
    REQUIRE( soldier.getHitPoints() == 100 );
    REQUIRE( soldier.getHitPointsLimit() == 100 );
    REQUIRE( soldier.getDamage() == 10 );
    REQUIRE( rogue.getHitPoints() == 80 );
    REQUIRE( rogue.getHitPointsLimit() == 80 );
    REQUIRE( rogue.getDamage() == 15 );
    
    SECTION( "soldier attacks rogue" ) {
        soldier.attack(&rogue);
        
        REQUIRE( rogue.getHitPoints() == 70 );
        REQUIRE( soldier.getHitPoints() == 93 );
    }
    SECTION( "rogue attacks soldier" ) {
        rogue.attack(&soldier);
        
        REQUIRE( soldier.getHitPoints() == 85 );
        REQUIRE( rogue.getHitPoints() == 80 );
    }
}
