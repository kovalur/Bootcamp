all: a.out

a.out: main.o Unit.o Soldier.o Rogue.o Berserker.o Vampire.o Werewolf.o Demon.o SpellCaster.o Wizard.o Healer.o Priest.o Warlock.o Necromancer.o State.o Observer.o Observable.o StateMagic.o Ability.o DefaultAbility.o RogueAbility.o VampireAbility.o PriestAbility.o MagicAbility.o PriestMagicAbility.o Spell.o HealFriend.o SurgeOfLightning.o
	g++ -std=c++11 -o a.out main.o Unit.o Soldier.o Rogue.o Berserker.o Vampire.o Werewolf.o Demon.o SpellCaster.o Wizard.o Healer.o Priest.o Warlock.o Necromancer.o State.o Observer.o Observable.o StateMagic.o Ability.o DefaultAbility.o RogueAbility.o VampireAbility.o PriestAbility.o MagicAbility.o PriestMagicAbility.o Spell.o HealFriend.o SurgeOfLightning.o

main.o:
	g++ -std=c++11 -c main.cpp

Unit.o:
	g++ -std=c++11 -c unit/Unit.cpp

Soldier.o:
	g++ -std=c++11 -c unit/Soldier.cpp

Rogue.o:
	g++ -std=c++11 -c unit/Rogue.cpp

Berserker.o:
	g++ -std=c++11 -c unit/Berserker.cpp

Vampire.o:
	g++ -std=c++11 -c unit/Vampire.cpp

Werewolf.o:
	g++ -std=c++11 -c unit/Werewolf.cpp

Demon.o:
	g++ -std=c++11 -c unit/Demon.cpp

SpellCaster.o:
	g++ -std=c++11 -c unit/mage/SpellCaster.cpp

Wizard.o:
	g++ -std=c++11 -c unit/mage/Wizard.cpp

Healer.o:
	g++ -std=c++11 -c unit/mage/Healer.cpp

Priest.o:
	g++ -std=c++11 -c unit/mage/Priest.cpp

Warlock.o:
	g++ -std=c++11 -c unit/mage/Warlock.cpp

Necromancer.o:
	g++ -std=c++11 -c unit/mage/Necromancer.cpp

State.o:
	g++ -std=c++11 -c state/State.cpp

StateMagic.o:
	g++ -std=c++11 -c state/StateMagic.cpp

Observer.o:
	g++ -std=c++11 -c state/Observer.cpp

Observable.o:
	g++ -std=c++11 -c state/Observable.cpp

Ability.o:
	g++ -std=c++11 -c ability/Ability.cpp

DefaultAbility.o:
	g++ -std=c++11 -c ability/DefaultAbility.cpp

RogueAbility.o:
	g++ -std=c++11 -c ability/RogueAbility.cpp
	
VampireAbility.o:
	g++ -std=c++11 -c ability/VampireAbility.cpp

PriestAbility.o:
	g++ -std=c++11 -c ability/PriestAbility.cpp

MagicAbility.o:
	g++ -std=c++11 -c ability/MagicAbility.cpp

PriestMagicAbility.o:
	g++ -std=c++11 -c ability/PriestMagicAbility.cpp

Spell.o:
	g++ -std=c++11 -c spell/Spell.cpp

HealFriend.o:
	g++ -std=c++11 -c spell/HealFriend.cpp

SurgeOfLightning.o:
	g++ -std=c++11 -c spell/SurgeOfLightning.cpp

clean:
	rm -f *.o

build:
	 make clean && make && ./a.out > output.txt && make clean
