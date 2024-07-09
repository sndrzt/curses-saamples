#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	WINDOW *win;
	int ch;

	if ((fp = fopen("a.txt", "wr")) == NULL)
		printf("无法打开文件a.txt\n");

	initscr();
	printw("窗口以外的内容");
	win = newwin(10, 30, 5, 20);
	box(win, 0, 0);
	mvwaddstr(win, 2, 5, "putwin()函数示例程序");
	refresh();
	wrefresh(win);

	ch = getch();
	putwin(win, fp);

	endwin();
}

