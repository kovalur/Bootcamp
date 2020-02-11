#include "../unit/Berserker.h"
#include "../unit/mage/Wizard.h"
#include "../properties.h"

#include "catch.hpp"


TEST_CASE( "wizard and berserker can attack each other", "[wizard][berserker]" ) {
    Wizard wizard = Wizard("Simple Wizard", int(Hp::Wizard), int(Dmg::Wizard), int(Mana::Wizard));
    Berserker berserker = Berserker("Simple Berserker", int(Hp::Berserker), int(Dmg::Berserker));
    
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
