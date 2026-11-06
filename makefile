
a.exe: 
	g++ FantasyBattle.cpp

clean: rm -f *.o a.exe

cleanRun:
	rm -f *.o a.exe
	g++ FantasyBattle.cpp
	./a

run:
	g++ FantasyBattle.cpp
	./a