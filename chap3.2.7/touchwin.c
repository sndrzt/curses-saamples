#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int ch, i;
	WINDOW *alertWindow;
	char strArr[7][80];
	strcpy(strArr[0], "##### ");
	strcpy(strArr[1], "##### ");
	strcpy(strArr[2], "##### ");
	strcpy(strArr[3], "##### ");
	strcpy(strArr[4], "##### ");
	strcpy(strArr[5], "##### ");
	strcpy(strArr[6], "##### ");
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	refresh();
	box(stdscr, '|', '-');

	for (i = 0; i < 7; i++)
	{
		mvwaddstr(stdscr, 8 + i, 16, strArr[i]);
	}

	alertWindow = newwin(8, 40, 6, 20);

	while (( ch = getch()) != 'q')
	{
		box(alertWindow, '|', '-');
		mvwaddstr(alertWindow, 2, 8, "这是一个弹出窗口");
		mvwaddstr(alertWindow, 4, 8, "请按任意键继续!");
		wattron(alertWindow, A_REVERSE);
		mvwaddstr(alertWindow, 6, 18, "OK");
		wattroff(alertWindow, A_REVERSE);
		touchwin(alertWindow);
		wrefresh(alertWindow);
		getch();
		touchwin(stdscr);
		wrefresh(stdscr);
	}
	delwin(alertWindow);
	endwin();
}

	
