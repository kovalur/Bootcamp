#include "../unit/Vampire.h"
#include "../unit/Werewolf.h"
#include "../unit/mage/Wizard.h"
#include "../unit/Rogue.h"
#include "../properties.h"

#include "catch.hpp"


TEST_CASE( "werewolf can make other werewolves", "[werewolf][vampire][wizard][rogue]" ) {
    Werewolf* werewolf = new Werewolf("Simple Werewolf", int(Hp::Werewolf), int(Dmg::Werewolf));
    Unit* vampire = new Vampire("Simple Vampire", int(Hp::Vampire), int(Dmg::Vampire));
    Unit* wizard = new Wizard("Simple Wizard", int(Hp::Wizard), int(Dmg::Wizard), int(Mana::Wizard));
    Unit* rogue = new Rogue("Simple Rogue", int(Hp::Rogue), int(Dmg::Rogue));
    
    REQUIRE( werewolf->getHitPoints() == 50 );
    REQUIRE( werewolf->getHitPointsLimit() == 50 );
    REQUIRE( werewolf->getDamage() == 10 );
    REQUIRE( dynamic_cast<Wizard*>(wizard)->getHitPoints() == 60 );
    REQUIRE( dynamic_cast<Wizard*>(wizard)->getHitPointsLimit() == 60 );
    REQUIRE( dynamic_cast<Wizard*>(wizard)->getDamage() == 10 );
    REQUIRE( dynamic_cast<Wizard*>(wizard)->getMana() == 90 );
    REQUIRE( dynamic_cast<Rogue*>(rogue)->getHitPoints() == 80 );
    REQUIRE( dynamic_cast<Rogue*>(rogue)->getHitPointsLimit() == 80 );
    REQUIRE( dynamic_cast<Rogue*>(rogue)->getDamage() == 15 );
    
    SECTION( "werewolf makes wizard(a werewolf) and they attack each other" ) {
        wizard = werewolf->makeWerewolf(wizard);
        
        wizard->attack(werewolf);
        
        REQUIRE( werewolf->getHitPoints() == 40 );
        REQUIRE( wizard->getHitPoints() == 45 );
        
        werewolf->attack(wizard);
        
        REQUIRE( wizard->getHitPoints() == 35 );
        REQUIRE( werewolf->getHitPoints() == 35 );
    }
    SECTION( "werewolf makes rogue(a werewolf) and they attack each other" ) {
        rogue = werewolf->makeWerewolf(rogue);
        
        rogue->attack(werewolf);
        
        REQUIRE( werewolf->getHitPoints() == 40 );
        REQUIRE( rogue->getHitPoints() == 45 );
        
        werewolf->attack(rogue);
        
        REQUIRE( rogue->getHitPoints() == 35 );
        REQUIRE( werewolf->getHitPoints() == 35 );
    }
    SECTION( "werewolf can not make werewolf(a vampire)" ) {
        try {
            vampire = werewolf->makeWerewolf(vampire);
        } catch ( NotTurnWerewolfException ) {
        }
    }
    SECTION( "werewolf can not make werewolf(a werewolf)" ) {
        Werewolf* werewolf2 = new Werewolf("Simple Werewolf", int(Hp::Werewolf), int(Dmg::Werewolf));
        
        try {
            werewolf2 = werewolf->makeWerewolf(werewolf2);
        } catch ( NotTurnWerewolfException ) {
        }
    }
}
