#include <stdlib.h>
#include <ncurses.h>

int main(){
	while(1){
		initscr();
		//int termRows, termCols, x, y;
		//getmaxyx(stdscr, termRows, termCols);
		raw();
		nonl();
		cbreak();
		//noecho();
		curs_set(0);
		start_color();
		init_pair(1, COLOR_RED, COLOR_BLACK);
		attron(COLOR_PAIR(1));
		int ch = getch();
		refresh();
		if (ch == 23){
			endwin();
			return 0;
		}
		else{
			//printf("\n");
			//getch();
			//attron(COLOR_GREEN);
			//noecho();
			if(ch == 10){
				printf("\n");
				//addch('F');
				//refresh();
			}
			noecho();
			if(ch == 127 || ch == 8){
				//noecho();
				printf("here");
				//clear();
				//getyx(stdscr, y, x);
				//move(y, x-1);
				delch();
				//mvdelch(termRows, termCols);
				keypad(stdscr, 1);
				echo();
			}
			echo();

		}
		refresh();
		//getch();
		//endwin();
	}


}