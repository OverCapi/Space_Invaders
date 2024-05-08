build:
	gcc -Iinclude/SDL2 -Iinclude/headers -Llib -o main.exe src/*.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

run:
	main.exe

clean:
	del main.exe