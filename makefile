all: compile
	./template.exe

compile:
	g++ $(wildcard src/*.cpp) -o template.exe -I src/headers -IC:/msys64/mingw64/bin/../include -IC:/msys64/mingw64/bin/../include/SDL2 -Dmain=SDL_main -IC:/msys64/mingw64/bin/../include/harfbuzz -IC:/msys64/mingw64/bin/../include/freetype2 -IC:/msys64/mingw64/bin/../include/libpng16 -IC:/msys64/mingw64/bin/../include/glib-2.0 -IC:/msys64/mingw64/bin/../lib/glib-2.0/include -LC:/msys64/mingw64/bin/../lib -lSDL2_ttf -lmingw32 -lSDL2main -lSDL2 -I/usr/include/SDL2 -D_REENTRANT -lSDL2