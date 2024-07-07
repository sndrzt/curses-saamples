// cc -o bullseye bullseye.c -lcurses
#include <curses.h>

int main(int argc, char **argv)
{
	int c;
	initscr();
	addstr("Press '1' to delete from here to the end of the line and on.");
	addstr("\nPress 'b' to delete from here to the end of screen.");
	move(0, 30);
	refresh();

	c = getch();
	if (c == 'b')
		clrtobot();
	else if (c == 'l');
		clrtoeol();

	refresh();
	endwin();
}

