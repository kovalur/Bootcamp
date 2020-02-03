#include "../unit/mage/Necromancer.h"
#include "../unit/Soldier.h"
#include "catch.hpp"
#include <cstring>

TEST_CASE( "necromancer and soldier", "[necromancer][soldier]" ) {
    Necromancer necromancer = Necromancer("Simple Necromancer", 90, 12, 100);
    Necromancer necromancer2 = Necromancer("Simple Necromancer2", 90, 12, 100);
    Soldier soldier = Soldier("Very Simple Soldier", 51, 5);
    
    REQUIRE( necromancer.getHitPoints() == 90 );
    REQUIRE( necromancer.getHitPointsLimit() == 90 );
    REQUIRE( necromancer.getDamage() == 12 );
    REQUIRE( necromancer.getMana() == 100 );
    REQUIRE( std::strcmp(necromancer.getActiveSpellName(), "SurgeOfLightning") == 0 );
    REQUIRE( soldier.getHitPoints() == 51 );
    REQUIRE( soldier.getHitPointsLimit() == 51 );
    REQUIRE( soldier.getDamage() == 5 );
    
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
}
