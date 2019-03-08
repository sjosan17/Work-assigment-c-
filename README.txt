Compiled in Visuel Studio x64 release build.

Simple program with SDL2 to move a .bmp image around in a 800x600 window. The user moves the image with the arrowkeys. To stop the image use "SPACE" bar.
The exit the program, either hit "esc" or click close in corner.

Warnings/bugs when compiling:
SDL_Rect     m_position; is an int
while position is a double.

Many .dll files that gets: "Cannot find or open the PDB file."

Future:
Started on adding text to window using SDL TTF. Not finish.