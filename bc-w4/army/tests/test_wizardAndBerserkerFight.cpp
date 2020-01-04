#include "../unit/Berserker.h"
#include "../unit/mage/Wizard.h"
#include "catch.hpp"

TEST_CASE( "wizard and berserker can attack each other", "[wizard][berserker]" ) {
    Wizard wizard = Wizard("Simple Wizard", 60, 10, 90);
    Berserker berserker = Berserker("Simple Berserker", 120, 20);
    
    REQUIRE( berserker.getHitPoints() == 120 );
    REQUIRE( berserker.getHitPointsLimit() == 120 );
    REQUIRE( berserker.getDamage() == 20 );
    REQUIRE( wizard.getHitPoints() == 60 );
    REQUIRE( wizard.getHitPointsLimit() == 60 );
    REQUIRE( wizard.getDamage() == 10 );
    REQUIRE( wizard.getMana() == 90 );
    
    SECTION( "wizard attacks berserker with magic" ) {
        try {
            wizard.cast(&berserker);
        } catch ( NoMagicAffectException ) {}
        
        REQUIRE( berserker.getHitPoints() == 120 );
        REQUIRE( wizard.getHitPoints() == 60 );
        REQUIRE( wizard.getMana() == 90 );
    }
    SECTION( "wizard attacks berserker" ) {
        wizard.attack(&berserker);
        
        REQUIRE( berserker.getHitPoints() == 110 );
        REQUIRE( wizard.getHitPoints() == 50 );
        REQUIRE( wizard.getMana() == 90 );
    }
    SECTION( "berserker attacks wizard" ) {
        try {
            berserker.attack(&wizard);  
        } catch ( NoMagicAffectException ) {}
        
        REQUIRE( berserker.getHitPoints() == 120 );
        REQUIRE( wizard.getHitPoints() == 40 );
        REQUIRE( wizard.getMana() == 90 );
    }
}
