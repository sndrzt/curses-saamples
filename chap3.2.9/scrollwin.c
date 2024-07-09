#include <curses.h>
#include <signal.h>

void finish(int signo)
{
	endwin();
	exit(0);
}

WINDOW *scrwin, *boxwin;
int main()
{
	int i;
	char ch;

	initscr();
	cbreak();
	noecho();
	nonl();

	scrwin = newwin(10, 40, LINES / 2 - 6, COLS / 2 - 25);
	boxwin = newwin(12, 42, LINES / 2 - 7, COLS / 2 - 26);

	scrollok(scrwin, TRUE);

	box(boxwin, '|', '-');
	refresh();
	wrefresh(boxwin);

	struct sigaction newact, oldact;
	newact.sa_flags = 0;
	newact.sa_handler = finish;
	sigaction(SIGINT, &newact, &oldact);
	sigaction(SIGQUIT, &newact, &oldact);

	for (i = 0; ; i++)
	{
		if (i % 20 == 0)
			sleep(1);
		wprintw(scrwin, "output sting %d\n", i % 9);
		wrefresh(scrwin);
	}
}

