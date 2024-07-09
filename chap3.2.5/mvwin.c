#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int ch;
	int y, x;
	WINDOW *alertWindow;

	initscr();
	noecho();
	keypad(stdscr, TRUE);
	refresh();
	alertWindow = newwin(8, 40, 6, 20);
	box(alertWindow, '|', '-');
	mvwaddstr(alertWindow, 2, 8, "please move by ← ↑ → ↓ ");
	mvwaddstr(alertWindow, 4, 8, "press any key to exit ");
	wattron(alertWindow, A_REVERSE);
	wrefresh(alertWindow);
	ch = getch();

	while (ch == KEY_RIGHT || ch == KEY_LEFT || ch == KEY_UP || ch == KEY_DOWN)
	{
		clear();
		refresh();
		y = alertWindow->_begy;
		x = alertWindow->_begx;
		switch(ch) {
		case KEY_RIGHT:
			x++;
			mvwin(alertWindow, y, x);
			wrefresh(alertWindow);
			break;
		case KEY_LEFT:
			x--;
			mvwin(alertWindow, y, x); 
			wrefresh(alertWindow);
			break;
		case KEY_UP:
			y--;
			mvwin(alertWindow, y, x);
			wrefresh(alertWindow);
			break;
		case KEY_DOWN:
			y++;
			mvwin(alertWindow, y, x);
			break;
		}
		ch = getch();
	}

	delwin(alertWindow);
	endwin();
}

