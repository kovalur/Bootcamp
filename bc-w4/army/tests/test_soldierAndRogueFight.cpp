#include "../unit/Soldier.h"
#include "../unit/Rogue.h"
#include "catch.hpp"

TEST_CASE( "test : Soldier attacks rogue.", "[Soldier]" ) {
    
    Soldier soldier = Soldier("Сommon Slodier", 100, 10);
    Rogue rogue = Rogue("Сommon Rogue", 80, 15);
    
    soldier.attack(&rogue);
    
    REQUIRE( rogue.getHitPoints() == 70 );
    REQUIRE( soldier.getHitPoints() == 93 );
    
}

TEST_CASE( "test : Rogue attacks soldier.", "[Rogue]" ) {
    
    Rogue rogue = Rogue("Сommon Rogue", 80, 15);
    Soldier soldier = Soldier("Сommon Slodier", 100, 10);
    
    rogue.attack(&soldier);
    
    REQUIRE( soldier.getHitPoints() == 85 );
    REQUIRE( rogue.getHitPoints() == 80 );
}
