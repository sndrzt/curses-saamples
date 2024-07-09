// cc -o bullseye bullseye.c -lcurses
#include <stdio.h>
#include <curses.h>

int main(int argc, char **argv)
{
	initscr();
	if (start_color() == OK)
	{
		init_pair(1, COLOR_RED, COLOR_GREEN);
		attron(COLOR_PAIR(1));
		if (init_color(COLOR_RED, 0, 0, 1000) == OK)
			addstr("Blue on Green");
		else
			addstr("Red on Grren");

		refresh();
	}

	endwin();
}

