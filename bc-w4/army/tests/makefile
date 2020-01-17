all: tests.out

tests.out: main.o test_soldierAndRogueFight.o test_wizardAndBerserkerFight.o test_vampireAndWizardFight.o test_wizardAndWerewolfFight.o test_wizardAndHealerFight.o test_priestAndVampireFight.o Unit.o Soldier.o Rogue.o Berserker.o Vampire.o Werewolf.o SpellCaster.o Wizard.o Healer.o Priest.o State.o StateMagic.o Ability.o DefaultAbility.o RogueAbility.o VampireAbility.o PriestAbility.o MagicAbility.o PriestMagicAbility.o Spell.o HealFriend.o SurgeOfLightning.o
	g++ -o tests.out main.o test_soldierAndRogueFight.o test_vampireAndWizardFight.o test_wizardAndBerserkerFight.o test_wizardAndWerewolfFight.o test_wizardAndHealerFight.o test_priestAndVampireFight.o Unit.o Soldier.o Rogue.o Berserker.o Vampire.o Werewolf.o SpellCaster.o Wizard.o Healer.o Priest.o State.o StateMagic.o Ability.o DefaultAbility.o RogueAbility.o VampireAbility.o PriestAbility.o MagicAbility.o PriestMagicAbility.o Spell.o HealFriend.o SurgeOfLightning.o

main.o:
	g++ -c main.cpp

test_soldierAndRogueFight.o:
	g++ -c test_soldierAndRogueFight.cpp

test_wizardAndBerserkerFight.o:
	g++ -c test_wizardAndBerserkerFight.cpp

test_VampireAndWizardFight.o:
	g++ -c test_vampireAndWizardFight.cpp

test_wizardAndWerewolfFight.o:
	g++ -c test_wizardAndWerewolfFight.cpp
	
test_wizardAndHealerFight.o:
	g++ -c test_wizardAndHealerFight.cpp

test_priestAndVampireFight.o:
	g++ -c test_priestAndVampireFight.cpp

Unit.o:
	g++ -c ../unit/Unit.cpp

Soldier.o:
	g++ -c ../unit/Soldier.cpp

Rogue.o:
	g++ -c ../unit/Rogue.cpp

Berserker.o:
	g++ -c ../unit/Berserker.cpp
	
Vampire.o:
	g++ -c ../unit/Vampire.cpp

Werewolf.o:
	g++ -c ../unit/Werewolf.cpp

SpellCaster.o:
	g++ -c ../unit/mage/SpellCaster.cpp

Wizard.o:
	g++ -c ../unit/mage/Wizard.cpp

Healer.o:
	g++ -c ../unit/mage/Healer.cpp

Priest.o:
	g++ -c ../unit/mage/Priest.cpp

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
	
VampireAbility.o:
	g++ -c ../ability/VampireAbility.cpp

PriestAbility.o:
	g++ -c ../ability/PriestAbility.cpp

MagicAbility.o:
	g++ -c ../ability/MagicAbility.cpp

PriestMagicAbility.o:
	g++ -c ../ability/PriestMagicAbility.cpp

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
