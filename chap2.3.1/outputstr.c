// cc -o bullseye bullseye.c -lcurses
#include <curses.h>

int main(int argc, char **argv)
{
	initscr();
	noecho();
	addch('x');
	waddch(stdscr, 'y' | A_UNDERLINE | A_BOLD);
	mvaddch(2, 1, 'z' | A_BOLD);
	refresh();

	sleep(3);
	clear();

	addstr("Output string sample");
	waddstr(stdscr, "\n 字符串输出使用示例");
	mvwaddstr(stdscr, 2, 1, "字符串使用示例");

	refresh();
	sleep(3);

	clear();
	printw("%s%d %c", "name", 10, 'm');
	refresh();
	endwin();
}

