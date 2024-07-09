#include <curses.h>
#include <unistd.h>

int main()
{
	int i, j;
	int w, h;
	char lines[128];
	WINDOW *pad;
	initscr();
	getmaxyx(stdscr, h, w);

	for (i = 0; i < h - 1; i++)
		for (j = 0; j < w; j++)
			mvaddch(i, j, ACS_CKBOARD);

	refresh();
	pad = newpad(80, 128);
	for (i = 0; i < 80; i++)
	{
		sprintf(lines, "This is Lines %d", i);
		mvwprintw(pad, i, 0, "%s", lines);
	}

	prefresh(pad, 0, 0, 5, 5, 15, 45);
	sleep(2);
	i = 1;

	for (i = 0; i < 50; i++)
	{
		prefresh(pad, i++, 0, 5, 5, 15, 45);
		usleep(30000);
	}

	getch();
	delwin(pad);
	endwin();

	return 0;
}
