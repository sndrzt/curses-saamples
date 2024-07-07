// cc -o bullseye bullseye.c -lcurses
#include <stdio.h>
#include <curses.h>

int main(int argc, char **argv)
{
	FILE *fd;
	int c, c2;
	void exit(), perror();

	if (argc != 2)
	{
		fprintf(stderr, "Usage: highlight file\n");
		exit(1);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		perror(argv[1]);
		exit(0);
	}
	initscr();
	scrollok(stdscr, TRUE);
	nonl();

	while (( c = getc(fd)) != EOF)
	{
		if (c == '\\')
		{
			c2 = getc(fd);
			switch(c2)
			{
			case 'B':
				attrset(A_BOLD);
				continue;
			case 'D':
				attrset(A_DIM);
				continue;
			case 'U':
				attrset(A_UNDERLINE);
				continue;
			case 'L':
				attrset(A_BLINK);
				continue;
			case 'R':
				attrset(A_REVERSE);
				continue;
			case 'N':
				attrset(0);
				continue;
			}
			addch(c);
			addch(c2);
		}
		else
		{
			addch(c);
		}
	}
	fclose(fd);
	refresh();
	endwin();
	exit(0);
}

