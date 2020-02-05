#include "../unit/mage/Necromancer.h"
#include "../unit/mage/Priest.h"
#include "../unit/Soldier.h"
#include "catch.hpp"
#include <cstring>

TEST_CASE( "necromancer and soldier", "[necromancer][soldier][priest]" ) {
    Necromancer necromancer = Necromancer("Simple Necromancer", 90, 12, 100);
    Necromancer necromancer2 = Necromancer("Simple Necromancer2", 90, 12, 100);
    Soldier soldier = Soldier("Very Simple Soldier", 51, 5);
    Priest priest = Priest("Simple Priest", 80, 8, 120);
    
    REQUIRE( necromancer.getHitPoints() == 90 );
    REQUIRE( necromancer.getHitPointsLimit() == 90 );
    REQUIRE( necromancer.getDamage() == 12 );
    REQUIRE( necromancer.getMana() == 100 );
    REQUIRE( std::strcmp(necromancer.getActiveSpellName(), "SurgeOfLightning") == 0 );
    REQUIRE( soldier.getHitPoints() == 51 );
    REQUIRE( soldier.getHitPointsLimit() == 51 );
    REQUIRE( soldier.getDamage() == 5 );
    REQUIRE( priest.getHitPoints() == 80 );
    REQUIRE( priest.getHitPointsLimit() == 80 );
    REQUIRE( priest.getDamage() == 8 );
    REQUIRE( priest.getMana() == 120 );
    REQUIRE( std::strcmp(priest.getActiveSpellName(), "HealFriend") == 0 );
    
    SECTION( "necromancer attacks soldier with magic to the death" ) {
        necromancer.cast(&soldier);
        
        REQUIRE( soldier.getHitPoints() == 26 );
        REQUIRE( necromancer.getHitPoints() == 88 );
        REQUIRE( necromancer.getMana() == 75 );
        
        necromancer.cast(&soldier);
        
        REQUIRE( soldier.getHitPoints() == 1 );
        REQUIRE( necromancer.getHitPoints() == 86 );
        REQUIRE( necromancer.getMana() == 50 );
        
        necromancer.cast(&soldier);
        
        REQUIRE( soldier.getHitPoints() == 0 );
        REQUIRE( necromancer.getHitPoints() == 90 );
        REQUIRE( necromancer.getMana() == 25 );
    }
    SECTION( "necromancer attacks soldier to the death, and then another necromancer kills him" ) {
        necromancer.attack(&soldier);
        
        REQUIRE( soldier.getHitPoints() == 39 );
        REQUIRE( necromancer.getHitPoints() == 88 );
        REQUIRE( necromancer.getMana() == 100 );
        
        necromancer.attack(&soldier);
        
        REQUIRE( soldier.getHitPoints() == 27 );
        REQUIRE( necromancer.getHitPoints() == 86 );
        REQUIRE( necromancer.getMana() == 100 );
        
        necromancer.attack(&soldier);
        
        REQUIRE( soldier.getHitPoints() == 15 );
        REQUIRE( necromancer.getHitPoints() == 84 );
        REQUIRE( necromancer.getMana() == 100 );
        
        necromancer.attack(&soldier);
        
        REQUIRE( soldier.getHitPoints() == 3 );
        REQUIRE( necromancer.getHitPoints() == 82 );
        REQUIRE( necromancer.getMana() == 100 );
        
        necromancer.attack(&soldier);
        
        REQUIRE( soldier.getHitPoints() == 0 );
        REQUIRE( necromancer.getHitPoints() == 90 );
        REQUIRE( necromancer.getMana() == 100 );
        
        necromancer2.cast(&necromancer);
        
        REQUIRE( necromancer.getHitPoints() == 65 );
        REQUIRE( necromancer.getMana() == 88 );
        REQUIRE( necromancer2.getHitPoints() == 78 );
        REQUIRE( necromancer2.getMana() == 75 );
        
        necromancer2.cast(&necromancer);
        
        REQUIRE( necromancer.getHitPoints() == 40 );
        REQUIRE( necromancer.getMana() == 76 );
        REQUIRE( necromancer2.getHitPoints() == 66 );
        REQUIRE( necromancer2.getMana() == 50 );
        
        necromancer2.cast(&necromancer);
        
        REQUIRE( necromancer.getHitPoints() == 15 );
        REQUIRE( necromancer.getMana() == 64 );
        REQUIRE( necromancer2.getHitPoints() == 54 );
        REQUIRE( necromancer2.getMana() == 25 );
        
        necromancer2.attack(&necromancer);
        
        REQUIRE( necromancer.getHitPoints() == 3 );
        REQUIRE( necromancer.getMana() == 52 );
        REQUIRE( necromancer2.getHitPoints() == 42 );
        REQUIRE( necromancer2.getMana() == 25 );
        
        necromancer2.attack(&necromancer);
        
        REQUIRE( necromancer.getHitPoints() == 0 );
        REQUIRE( necromancer.getMana() == 52 );
        REQUIRE( necromancer2.getHitPoints() == 60 );
        REQUIRE( necromancer2.getMana() == 25 );
    }
    SECTION( "priest attacks necromancer with magic" ) {
        priest.changeSpell("SurgeOfLightning");
        
        REQUIRE( std::strcmp(priest.getActiveSpellName(), "SurgeOfLightning") == 0 );
        
        priest.cast(&necromancer);
        
        REQUIRE( necromancer.getHitPoints() == 66 );
        REQUIRE( priest.getHitPoints() == 68 );
        REQUIRE( priest.getMana() == 95 );
    }
    SECTION( "priest attacks necromancer" ) {
        priest.attack(&necromancer);
        
        REQUIRE( necromancer.getHitPoints() == 74 );
        REQUIRE( priest.getHitPoints() == 68 );
        REQUIRE( priest.getMana() == 120 );
    }
    SECTION( "necromancer attacks priest, and priest then counterattacks with magic" ) {
        priest.changeSpell("SurgeOfLightning");
        
        REQUIRE( std::strcmp(priest.getActiveSpellName(), "SurgeOfLightning") == 0 );
        
        necromancer.attack(&priest);
        
        REQUIRE( priest.getHitPoints() == 68 );
        REQUIRE( priest.getMana() == 108 );
        REQUIRE( necromancer.getHitPoints() == 78 );
    }
    SECTION( "necromancer attacks priest" ) {
        necromancer.attack(&priest);
        
        REQUIRE( priest.getHitPoints() == 68 );
        REQUIRE( priest.getMana() == 120 );
        REQUIRE( necromancer.getHitPoints() == 82 );
    }
}
