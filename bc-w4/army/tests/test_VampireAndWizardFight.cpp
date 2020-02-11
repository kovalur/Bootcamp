#include "../unit/Vampire.h"
#include "../unit/mage/Wizard.h"
#include "../properties.h"

#include "catch.hpp"


TEST_CASE( "vampire and wizard can attack each other", "[vampire][wizard]" ) {
    Vampire vampire = Vampire("Simple Vampire", int(Hp::Vampire), int(Dmg::Vampire));
    Wizard wizard = Wizard("Simple Wizard", int(Hp::Wizard), int(Dmg::Wizard), int(Mana::Wizard));
    
    REQUIRE( vampire.getHitPoints() == 70 );
    REQUIRE( vampire.getHitPointsLimit() == 70 );
    REQUIRE( vampire.getDamage() == 20 );
    REQUIRE( wizard.getHitPoints() == 60 );
    REQUIRE( wizard.getHitPointsLimit() == 60 );
    REQUIRE( wizard.getDamage() == 10 );
    REQUIRE( wizard.getMana() == 90 );
    
    SECTION( "vampire attacks wizard" ) {
        vampire.attack(&wizard);
        
        REQUIRE( vampire.getHitPoints() == 55 );
        REQUIRE( wizard.getHitPoints() == 35 );
        REQUIRE ( wizard.getMana() == 75 );
    }
    SECTION( "wizard attacks vampire with magic" ) {
        wizard.cast(&vampire);
        
        REQUIRE( vampire.getHitPoints() == 40 );
        REQUIRE( wizard.getHitPoints() == 45 );
        REQUIRE( wizard.getMana() == 60 );
    }
    SECTION( "wizard attacks vampire" ) {
        wizard.attack(&vampire);
        
        REQUIRE( vampire.getHitPoints() == 60 );
        REQUIRE( wizard.getHitPoints() == 45 );
        REQUIRE( wizard.getMana() == 90 );
    }
}
