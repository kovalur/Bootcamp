#include "../unit/mage/Priest.h"
#include "../unit/Vampire.h"
#include "../unit/Soldier.h"
#include "catch.hpp"
#include <cstring>

TEST_CASE( "priest and vampire(or other non-undead unit) can attack each other", "[priest][vampire][soldier]" ) {
    Priest priest = Priest("Simple Priest", 80, 8, 120);
    Vampire vampire = Vampire("Simple Vampire", 70, 20);
    Soldier soldier = Soldier("Simple Soldier", 100, 10);
    
    REQUIRE( priest.getHitPoints() == 80 );
    REQUIRE( priest.getHitPointsLimit() == 80 );
    REQUIRE( priest.getDamage() == 8 );
    REQUIRE( priest.getMana() == 120 );
    REQUIRE( std::strcmp(priest.getActiveSpellName(), "HealFriend") == 0 );
    REQUIRE( vampire.getHitPoints() == 70 );
    REQUIRE( vampire.getHitPointsLimit() == 70 );
    REQUIRE( vampire.getDamage() == 20 );
    REQUIRE( soldier.getHitPoints() == 100 );
    REQUIRE( soldier.getHitPointsLimit() == 100 );
    REQUIRE( soldier.getDamage() == 10 );
    
    SECTION( "priest attacks vampire with magic" ) {
        priest.changeSpell("SurgeOfLightning");
        
        REQUIRE( std::strcmp(priest.getActiveSpellName(), "SurgeOfLightning") == 0 );
        
        priest.cast(&vampire);
        
        REQUIRE( vampire.getHitPoints() == 46 );
        REQUIRE( priest.getHitPoints() == 65 );
        REQUIRE( priest.getMana() == 95 );
    }
    SECTION( "priest attacks soldier with magic" ) {
        priest.changeSpell("SurgeOfLightning");
        
        REQUIRE( std::strcmp(priest.getActiveSpellName(), "SurgeOfLightning") == 0 );
        
        priest.cast(&soldier);
        
        REQUIRE( soldier.getHitPoints() == 88 );
        REQUIRE( priest.getHitPoints() == 75 );
        REQUIRE( priest.getMana() == 95 );
    }
    SECTION( "priest attacks vampire" ) {
        priest.attack(&vampire);
        
        REQUIRE( vampire.getHitPoints() == 54 );
        REQUIRE( priest.getHitPoints() == 65 );
        REQUIRE( priest.getMana() == 120 );
    }
    SECTION( "priest attacks soldier" ) {
        priest.attack(&soldier);
        
        REQUIRE( soldier.getHitPoints() == 92 );
        REQUIRE( priest.getHitPoints() == 75 );
        REQUIRE( priest.getMana() == 120 );
    }
    SECTION( "vampire attacks priest, and priest then counterattacks with magic" ) {
        priest.changeSpell("SurgeOfLightning");
        
        REQUIRE( std::strcmp(priest.getActiveSpellName(), "SurgeOfLightning") == 0 );
        
        vampire.attack(&priest);
        
        REQUIRE( priest.getHitPoints() == 55 );
        REQUIRE( priest.getMana() == 108 );
        REQUIRE( vampire.getHitPoints() == 58 );
    }
    SECTION( "soldier attacks priest, and priest then counterattacks with magic" ) {
        priest.changeSpell("SurgeOfLightning");
        
        REQUIRE( std::strcmp(priest.getActiveSpellName(), "SurgeOfLightning") == 0 );
        
        soldier.attack(&priest);
        
        REQUIRE( priest.getHitPoints() == 70 );
        REQUIRE( priest.getMana() == 108 );
        REQUIRE( soldier.getHitPoints() == 94 );
    }
    SECTION( "vampire attacks priest" ) {
        vampire.attack(&priest);
        
        REQUIRE( priest.getHitPoints() == 55 );
        REQUIRE( priest.getMana() == 120 );
        REQUIRE( vampire.getHitPoints() == 62 );
    }
    SECTION( "soldier attacks priest" ) {
        soldier.attack(&priest);
        
        REQUIRE( priest.getHitPoints() == 70 );
        REQUIRE( priest.getMana() == 120 );
        REQUIRE( soldier.getHitPoints() == 96 );
    }
}
