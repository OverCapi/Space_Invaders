all:
	g++ -Iinclude/SDL2 -Iinclude/headers -Llib -o main.exe src/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image