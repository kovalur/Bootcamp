all: tests.out

tests.out: main.o test_soldierAndRogueFight.o Unit.o Soldier.o Rogue.o SpellCaster.o Wizard.o State.o StateMagic.o Ability.o DefaultAbility.o RogueAbility.o MagicAbility.o Spell.o HealFriend.o SurgeOfLightning.o
	g++ -o tests.out main.o test_soldierAndRogueFight.o Unit.o Soldier.o Rogue.o SpellCaster.o Wizard.o State.o StateMagic.o Ability.o DefaultAbility.o RogueAbility.o MagicAbility.o Spell.o HealFriend.o SurgeOfLightning.o

main.o:
	g++ -c main.cpp

test_soldierAndRogueFight.o:
	g++ -c test_soldierAndRogueFight.cpp

Unit.o:
	g++ -c ../unit/Unit.cpp

Soldier.o:
	g++ -c ../unit/Soldier.cpp

Rogue.o:
	g++ -c ../unit/Rogue.cpp
	
SpellCaster.o:
	g++ -c ../unit/mage/SpellCaster.cpp

Wizard.o:
	g++ -c ../unit/mage/Wizard.cpp

State.o:
	g++ -c ../state/State.cpp

StateMagic.o:
	g++ -c ../state/StateMagic.cpp

Ability.o:
	g++ -c ../ability/Ability.cpp

DefaultAbility.o:
	g++ -c ../ability/DefaultAbility.cpp

RogueAbility.o:
	g++ -c ../ability/RogueAbility.cpp

MagicAbility.o:
	g++ -c ../ability/MagicAbility.cpp

Spell.o:
	g++ -c ../spell/Spell.cpp

HealFriend.o:
	g++ -c ../spell/HealFriend.cpp

SurgeOfLightning.o:
	g++ -c ../spell/SurgeOfLightning.cpp

clean:
	rm -f *.o

run_tests:
	make clean && make && make clean && ./tests.out
