#include "../unit/mage/Warlock.h"
#include "../unit/Werewolf.h"
#include "../unit/Demon.h"
#include "../exceptions.h"
#include "../properties.h"

#include "catch.hpp"
#include <cstring>


TEST_CASE( "warlock and werewolf can attack each other, and warlock can call Demons", "[warlock][werewolf][demon]" ) {
    Warlock warlock = Warlock("Simple Warlock", int(Hp::Warlock), int(Dmg::Warlock), int(Mana::Warlock));
    Werewolf werewolf = Werewolf("Simple Werewolf", int(Hp::Werewolf), int(Dmg::Werewolf));
    int numOfDemons = 5;
    Demon* demons[numOfDemons];
    Demon* extraDemon;
    
    REQUIRE( warlock.getHitPoints() == 90 );
    REQUIRE( warlock.getHitPointsLimit() == 90 );
    REQUIRE( warlock.getDamage() == 11 );
    REQUIRE( warlock.getMana() == 80 );
    REQUIRE( std::strcmp(warlock.getActiveSpellName(), "SurgeOfLightning") == 0 );
    REQUIRE( werewolf.getHitPoints() == 50 );
    REQUIRE( werewolf.getHitPointsLimit() == 50 );
    REQUIRE( werewolf.getDamage() == 10 );
    
    SECTION( "warlock attacks werewolf with magic, and warlock can call one or more demons" ) {
        extraDemon = warlock.callDemons();
        warlock.callDemons(numOfDemons, demons);
        
        warlock.cast(&werewolf);
        
        REQUIRE( werewolf.getHitPoints() == 20 );
        REQUIRE( warlock.getHitPoints() == 85 );
        REQUIRE( warlock.getMana() == 50 );
        
        demons[0]->attack(&werewolf);
        
        REQUIRE( werewolf.getHitPoints() == 18 );
        
        demons[0]->attack(&werewolf);
        demons[2]->attack(&werewolf);
        demons[4]->attack(&werewolf);
        
        REQUIRE( werewolf.getHitPoints() == 12 );
        REQUIRE( demons[0]->getHitPoints() == 0 );
        REQUIRE( demons[2]->getHitPoints() == 4 );
        REQUIRE( demons[4]->getHitPoints() == 4 );
        
        for ( int i = 0; i < numOfDemons; i++ ) {
            delete demons[i];
        }
        
        extraDemon->attack(&werewolf);
        
        REQUIRE( werewolf.getHitPoints() == 10 );
        REQUIRE( extraDemon->getHitPoints() == 4 );
        
        delete extraDemon;
    }
    SECTION( "warlock attacks werewolf and can call Demons" ) {
        warlock.callDemons(numOfDemons, demons);
        
        demons[0]->attack(&werewolf);
        demons[3]->attack(&werewolf);
        warlock.attack(&werewolf);
        
        REQUIRE( werewolf.getHitPoints() == 35 );
        REQUIRE( warlock.getHitPoints() == 85 );
        REQUIRE( warlock.getMana() == 80 );
        REQUIRE( demons[0]->getHitPoints() == 4 );
        REQUIRE( demons[3]->getHitPoints() == 4 );
        
        for ( int i = 0; i < numOfDemons; i++ ) {
            delete demons[i];
        }
    }
    SECTION( "werewolf attacks warlock, and warlock then counterattacks with magic and call just one Demon" ) {
        werewolf.attack(&warlock);
        
        REQUIRE( warlock.getHitPoints() == 80 );
        REQUIRE( warlock.getMana() == 65 );
        REQUIRE( werewolf.getHitPoints() == 35 );
        
        extraDemon = warlock.callDemons();
        
        extraDemon->attack(&werewolf);
        
        REQUIRE( werewolf.getHitPoints() == 33 );
        REQUIRE( extraDemon->getHitPoints() == 4 );
        
        delete extraDemon;
    }
    SECTION( "werewolf attacks warlock, and warlock can call just one Demon" ) {
        warlock.changeSpell("HealFriend");
        
        REQUIRE( std::strcmp(warlock.getActiveSpellName(), "HealFriend") == 0 );
        
        werewolf.attack(&warlock);
        
        REQUIRE( warlock.getHitPoints() == 80 );
        REQUIRE( warlock.getMana() == 80 );
        REQUIRE( werewolf.getHitPoints() == 45 );
        
        extraDemon = warlock.callDemons();
        
        extraDemon->attack(&werewolf);
        
        REQUIRE( werewolf.getHitPoints() == 43 );
        REQUIRE( extraDemon->getHitPoints() == 4 );
        
        delete extraDemon;
    }
    SECTION( "warlock cannot heal demons" ) {
        extraDemon = warlock.callDemons();
        warlock.callDemons(numOfDemons, demons);
        
        warlock.changeSpell("HealFriend");
        
        REQUIRE( std::strcmp(warlock.getActiveSpellName(), "HealFriend") == 0 );
        
        extraDemon->attack(&warlock);
        
        REQUIRE( warlock.getHitPoints() == 88 );
        REQUIRE( extraDemon->getHitPoints() == 4 );
        
        try {
            warlock.cast(demons[3]);
        } catch ( UnitHealNotAllowedException ) {}
        
        try {
            warlock.cast(extraDemon);
        } catch ( UnitHealNotAllowedException ) {}
        
        for ( int i = 0; i < numOfDemons; i++ ) {
            delete demons[i];
        }
        delete extraDemon;
    }
}
