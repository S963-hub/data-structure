all: derle bagla calistir

derle:
	g++ -I ./include/ -c ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -I ./include/ -c ./src/Bagliliste.cpp -o ./lib/Bagliliste.o
	g++ -I ./include/ -c ./src/treeDugum.cpp -o ./lib/treeDugum.o
	g++ -I ./include/ -c ./src/Yigin.cpp -o ./lib/Yigin.o
	g++ -I ./include/ -c ./src/AVLAgaci.cpp -o ./lib/AVLAgaci.o
	g++ -I ./include/ -c ./src/stackDugum.cpp -o ./lib/stackDugum.o
	g++ -I ./include/ -c ./src/main.cpp -o ./lib/main.o

bagla:
	g++ -I ./include/ -o ./bin/program.exe ./lib/Dugum.o ./lib/AVLAgaci.o ./lib/Yigin.o ./lib/Bagliliste.o ./lib/treeDugum.o ./lib/stackDugum.o ./src/main.cpp
calistir:
	./bin/program.exe