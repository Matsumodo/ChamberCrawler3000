XX = g++
CXXFLAGS = -Wall -MMD

OBJECTS = cc3k.o textdisplay.o factory.o mediator.o grid.o chamber.o tile.o gameobject.o vwall.o hwall.o stairway.o ground.o door.o passage.o playercharacter.o enemy.o elves.o dwarf.o human.o orc.o werewolf.o vampire.o phoenix.o troll.o merchant.o goblin.o dragon.o item.o potion.o RH.o PH.o BA.o BD.o WA.o WD.o treasure.o dragonhorde.o smallhorde.o normalgold.o merchanthorde.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = cc3k

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean
clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}
