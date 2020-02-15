main:   clean
	g++ main.cpp -lSDL2 -o game
	./game

clean:
	rm -f game
