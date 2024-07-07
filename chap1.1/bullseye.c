// cc -o bullseye bullseye.c -lcurses
#include <curses.h>
#include <signal.h>

#if 0
static void finish(int sig)
{
	endwin();
	exit(0);
}
#else
void handler(int signo)
{
	printf(" %d signal captured, handling...\n", signo);
}
#endif

int main(int argc, char **argv)
{
#if 0
	(void)sigaction(SIGINT, finish);
#else
	struct sigaction newact, oldact;
	newact.sa_flags = 0;
	newact.sa_handler = handler;

	sigaction(SIGINT, &newact, &oldact);
#endif
	initscr();
	keypad(stdscr, TRUE);
	(void)nonl();
	(void)cbreak();
	(void)noecho();

	if (has_colors())
	{
		start_color();
		init_pair(0, COLOR_BLACK, COLOR_BLACK);
		init_pair(1, COLOR_GREEN, COLOR_BLACK);
		init_pair(2, COLOR_RED, COLOR_BLACK);
		init_pair(3, COLOR_CYAN, COLOR_BLACK);
		init_pair(4, COLOR_WHITE, COLOR_BLACK);
		init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
		init_pair(6, COLOR_BLUE, COLOR_BLACK);
		init_pair(7, COLOR_YELLOW, COLOR_BLACK);
	}
	attron(A_BLINK | COLOR_PAIR(1));
	move(LINES / 2 + 1, COLS - 4);
	addstr("Eye");
	refresh();
	sleep(2);

	move(LINES / 2 -3, COLS / 2 - 3);
	addstr("Bulls");
	refresh();
	sleep(2);

#if 0
	finish(0);
#else
	endwin();
	exit(0);
#endif
}

