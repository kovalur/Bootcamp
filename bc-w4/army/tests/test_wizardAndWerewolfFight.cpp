#include "../unit/Werewolf.h"
#include "../unit/mage/Wizard.h"
#include "../properties.h"

#include "catch.hpp"


TEST_CASE( "wizard and werewolf can attack each other", "[wizard][werewolf]" ) {
    Wizard wizard = Wizard("Simple Wizard", int(Hp::Wizard), int(Dmg::Wizard), int(Mana::Wizard));
    Werewolf werewolf = Werewolf("Simple Werewolf", int(Hp::Werewolf), int(Dmg::Werewolf));
    
    REQUIRE( wizard.getHitPoints() == 60 );
    REQUIRE( wizard.getHitPointsLimit() == 60 );
    REQUIRE( wizard.getDamage() == 10 );
    REQUIRE( wizard.getMana() == 90 );
    REQUIRE( werewolf.getHitPoints() == 50 );
    REQUIRE( werewolf.getHitPointsLimit() == 50 );
    REQUIRE( werewolf.getDamage() == 10 );
    
    SECTION( "werewolf may become wolf and vice versa" ) {
        werewolf.transform();
        
        REQUIRE( werewolf.getHitPoints() == 65 );
        REQUIRE( werewolf.getHitPointsLimit() == 65 );
        REQUIRE( werewolf.getDamage() == 12 );
        
        werewolf.transform();
        REQUIRE( werewolf.getHitPoints() == 50 );
        REQUIRE( werewolf.getHitPointsLimit() == 50 );
        REQUIRE( werewolf.getDamage() == 10 );
    }
    SECTION( "wizard attacks werewolf with magic" ) {
        wizard.cast(&werewolf);
        
        REQUIRE( werewolf.getHitPoints() == 20 );
        REQUIRE( wizard.getHitPoints() == 55 );
        REQUIRE( wizard.getMana() == 60 );
    }
    SECTION( "wizard attacks wolf with magic" ) {
        werewolf.transform();
        wizard.cast(&werewolf);
        
        REQUIRE( werewolf.getHitPoints() == 29 );
        REQUIRE( wizard.getHitPoints() == 54 );
        REQUIRE( wizard.getMana() == 60 );
    }
    SECTION( "wizard attacks wolf" ) {
        werewolf.transform();
        wizard.attack(&werewolf);
        
        REQUIRE( werewolf.getHitPoints() == 55 );
        REQUIRE( wizard.getHitPoints() == 54 );
        REQUIRE( wizard.getMana() == 90 );
    }
    SECTION( "wolf attacks wizard" ) {
        werewolf.transform();
        werewolf.attack(&wizard);
        
        REQUIRE( wizard.getHitPoints() == 48 );
        REQUIRE( werewolf.getHitPoints() == 47 );
        REQUIRE( wizard.getMana() == 75 );
    }
    SECTION( "werewolf attacks wizard" ) {
        werewolf.attack(&wizard);
        
        REQUIRE( wizard.getHitPoints() == 50 );
        REQUIRE( werewolf.getHitPoints() == 35 );
        REQUIRE( wizard.getMana() == 75 );
    } 
}
