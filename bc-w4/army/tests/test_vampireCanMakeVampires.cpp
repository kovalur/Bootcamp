#include "../unit/Vampire.h"
#include "../unit/Werewolf.h"
#include "../unit/mage/Wizard.h"
#include "../unit/Rogue.h"
#include "../properties.h"

#include "catch.hpp"


TEST_CASE( "vampire can make other vampires", "[vampire][werewolf][wizard][rogue]" ) {
    Vampire* vampire = new Vampire("Simple Vampire", int(Hp::Vampire), int(Dmg::Vampire));
    Unit* werewolf = new Werewolf("Simple Werewolf", int(Hp::Werewolf), int(Dmg::Werewolf));
    Unit* wizard = new Wizard("Simple Wizard", int(Hp::Wizard), int(Dmg::Wizard), int(Mana::Wizard));
    Unit* rogue = new Rogue("Simple Rogue", int(Hp::Rogue), int(Dmg::Rogue));
    
    REQUIRE( vampire->getHitPoints() == 70 );
    REQUIRE( vampire->getHitPointsLimit() == 70 );
    REQUIRE( vampire->getDamage() == 20 );
    REQUIRE( dynamic_cast<Wizard*>(wizard)->getHitPoints() == 60 );
    REQUIRE( dynamic_cast<Wizard*>(wizard)->getHitPointsLimit() == 60 );
    REQUIRE( dynamic_cast<Wizard*>(wizard)->getDamage() == 10 );
    REQUIRE( dynamic_cast<Wizard*>(wizard)->getMana() == 90 );
    REQUIRE( dynamic_cast<Rogue*>(rogue)->getHitPoints() == 80 );
    REQUIRE( dynamic_cast<Rogue*>(rogue)->getHitPointsLimit() == 80 );
    REQUIRE( dynamic_cast<Rogue*>(rogue)->getDamage() == 15 );
    
    SECTION( "vampire makes wizard(a vampire) and they attack each other" ) {
        wizard = vampire->makeVampire(wizard);
        
        wizard->attack(vampire);
        
        REQUIRE( vampire->getHitPoints() == 50 );
        REQUIRE( wizard->getHitPoints() == 58 );
        
        vampire->attack(wizard);
        
        REQUIRE( wizard->getHitPoints() == 38 );
        REQUIRE( vampire->getHitPoints() == 40 );
    }
    SECTION( "vampire makes rogue(a vampire) and they attack each other" ) {
        rogue = vampire->makeVampire(rogue);
        
        rogue->attack(vampire);
        
        REQUIRE( vampire->getHitPoints() == 50 );
        REQUIRE( rogue->getHitPoints() == 58 );
        
        vampire->attack(rogue);
        
        REQUIRE( rogue->getHitPoints() == 38 );
        REQUIRE( vampire->getHitPoints() == 40 );
    }
    SECTION( "vampire can not make vampire(a vampire)" ) {
        Vampire* vampire2 = new Vampire("Simple Vampire", int(Hp::Vampire), int(Dmg::Vampire));
        
        try {
            vampire2 = vampire->makeVampire(vampire2);
        } catch ( NotTurnVampireException ) {
        }
    }
    SECTION( "vampire can not make werewolf(a vampire)" ) {
        try {
            werewolf = vampire->makeVampire(werewolf);
        } catch ( NotTurnVampireException ) {
        }
    }
}
