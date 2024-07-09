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
		addstr("Red on Green");
		refresh();
	}
	else
	{
		printw("Can't support color");
		refresh();
	}

	endwin();
}

