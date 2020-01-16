#include "../unit/mage/Wizard.h"
#include "../unit/mage/Healer.h"
#include "catch.hpp"
#include <cstring>

TEST_CASE( "wizard and healer can attack/heal each other", "[wizard][healer]" ) {
    Wizard wizard = Wizard("Simple Wizard", 60, 10, 90);
    Healer healer = Healer("Simple Healer", 40, 8, 100);
    
    REQUIRE( wizard.getHitPoints() == 60 );
    REQUIRE( wizard.getHitPointsLimit() == 60 );
    REQUIRE( wizard.getDamage() == 10 );
    REQUIRE( wizard.getMana() == 90 );
    REQUIRE( std::strcmp(wizard.getActiveSpellName(), "SurgeOfLightning") == 0 );
    REQUIRE( healer.getHitPoints() == 40 );
    REQUIRE( healer.getHitPointsLimit() == 40 );
    REQUIRE( healer.getDamage() == 8 );
    REQUIRE( healer.getMana() == 100 );
    REQUIRE( std::strcmp(healer.getActiveSpellName(), "HealFriend") == 0 );
    
    SECTION( "wizard attacks healer with magic" ) {
        wizard.cast(&healer);
        
        REQUIRE( healer.getHitPoints() == 10 );
        REQUIRE( healer.getMana() == 100 );
        REQUIRE( wizard.getHitPoints() == 56 );
        REQUIRE( wizard.getMana() == 60 );
    }
    SECTION( "wizard attacks healer with magic, and healer then counterattacks with magic" ) {
        healer.changeSpell("SurgeOfLightning");
        
        REQUIRE( std::strcmp(healer.getActiveSpellName(), "SurgeOfLightning") == 0 );
        
        wizard.cast(&healer);
        
        REQUIRE( healer.getHitPoints() == 10 );
        REQUIRE( healer.getMana() == 88 );
        REQUIRE( wizard.getHitPoints() == 54 );
        REQUIRE( wizard.getMana() == 60 );
    }
    SECTION( "wizard attacks healer" ) {
        wizard.attack(&healer);
        
        REQUIRE( healer.getHitPoints() == 30 );
        REQUIRE( healer.getMana() == 100 );
        REQUIRE( wizard.getHitPoints() == 56 );
        REQUIRE( wizard.getMana() == 90 );
    }
    SECTION( "healer attacks wizard with magic, and then wizard counterattacks" ) {
        healer.changeSpell("SurgeOfLightning");
        
        REQUIRE( std::strcmp(healer.getActiveSpellName(), "SurgeOfLightning") == 0 );
        
        wizard.changeSpell("HealFriend");
        
        REQUIRE( std::strcmp(wizard.getActiveSpellName(), "HealFriend") == 0 );
        
        healer.cast(&wizard);
        
        REQUIRE( wizard.getHitPoints() == 48 );
        REQUIRE( wizard.getMana() == 90 );
        REQUIRE( healer.getHitPoints() == 35 );
        REQUIRE( healer.getMana() == 75 );
    }
    SECTION( "healer attacks wizard, and then wizard counterattacks with magic" ) {
        healer.attack(&wizard);
        
        REQUIRE( wizard.getHitPoints() == 52 );
        REQUIRE( wizard.getMana() == 75 );
        REQUIRE( healer.getHitPoints() == 25 );
        REQUIRE( healer.getMana() == 100 );
    }
    SECTION( "healer heals wizard, and refill mana for himself and wizard" ) {
        healer.attack(&wizard);
        
        REQUIRE( wizard.getHitPoints() == 52 );
        REQUIRE( wizard.getMana() == 75 );
        REQUIRE( healer.getHitPoints() == 25 );
        REQUIRE( healer.getMana() == 100 );
        
        healer.cast(&wizard);
        
        REQUIRE( wizard.getHitPoints() == 60 );
        REQUIRE( wizard.getMana() == 75 );
        REQUIRE( healer.getHitPoints() == 25 );
        REQUIRE( healer.getMana() == 80 );
        
        wizard.addMana(16);
        healer.addMana(19);
        
        REQUIRE( wizard.getMana() == 90 );
        REQUIRE( wizard.getManaLimit() == 90 );
        REQUIRE( healer.getMana() == 99 );
        REQUIRE( healer.getManaLimit() == 100 );
    }
}
