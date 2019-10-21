#include "../units/Unit.h"
#include "catch.hpp"

TEST_CASE( "test Unit", "[Unit]" ) {
    
    Unit f1 = Unit(25, 120, "Ordinary Slodier");
    
    REQUIRE( f1.getName() == "Ordinary Slodier" );
    REQUIRE( f1.getDamage() == 25 );
    REQUIRE( f1.getHitPoints() == 120 );
    REQUIRE( f1.getHitPointsLimit() == 120 );
}
