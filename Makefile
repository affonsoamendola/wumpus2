#Copyright Affonso Amendola 2018
#
#Fofonso's Wumpus Hunt 2:
#The Hunt for the Wumpus Wizard

GAMENAME = wumpus2
CC = tcc
RM = rm -f

INCLUDE = include;D:\tc\include
LIB = D:\tc\lib
CCFLAGS = 

all: $(GAMENAME).exe

$(GAMENAME).exe:
	$(CC) "-I$(INCLUDE) -L$(LIB) -e$(GAMENAME) $(CCFLAGS)"  *.c 

run:
	dosbox -conf ~/.dosbox/tcc.conf -c "$(GAMENAME)"

clean:
	$(RM) *.OBJ *.EXE *.LOG *.BAT