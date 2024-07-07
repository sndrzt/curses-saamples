// cc -o bullseye bullseye.c -lcurses
#include <curses.h>

int main(int argc, char **argv)
{
	char str[20];
	char *pstr;
	initscr();
	crmode();

	printw("File to Open: ");
	refresh();
	getstr(str);
	printw("You typed is: %s\n", str);
	refresh();
	sleep(3);

	pstr = malloc(sizeof(char) * 20);
	printw("Enter your name: ");
	refresh();
	getnstr(pstr, 20);
	refresh();
	printw("your enter is: %s\n", pstr);
	refresh();
	sleep(1);
	free(pstr);
	endwin();
}

