#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	WINDOW *win;
	int ch;

	if ((fp = fopen("a.txt", "r")) == NULL)
		printf("无法打开文件a.txt\n");

	initscr();
	win = getwin(fp);
	box(win, 0, 0);
	refresh();
	wrefresh(win);

	ch = getch();
	delwin(win);

	endwin();
}

