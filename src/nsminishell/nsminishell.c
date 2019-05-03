#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <strings.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "my.h"
#include "list.h"
//Can use function readline, but not the actual library
char* file;
pid_t child;
int i = 1;
int minX;
int minY;
int maxX= 0;
int maxY=0;
static int w, h, j, wsize;
int trueMaxX;
void prompt(){
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(2));
	printw("NSFMinishell~ ");
	printw(file);
	printw(": ");
	minX = getcurx(stdscr);
	minY=getcury(stdscr);
	attron(COLOR_PAIR(1));
}
void display(){
	struct winsize ws;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	w = ws.ws_col;
	h = ws.ws_row;
}
void controlC(int sig){
	prompt();
}
int table(){
	clear();
	int termCols = 0;
	for(j = 0; j<wsize; j++){
		if(1+getcury(stdscr)>=h){
			int x = getcurx(stdscr);
			if(j!=wsize-1 && x+termCols+2>w){
				return 1;
			}
			move(0,termCols+x+1);
			termCols = 0;
		}
		else{
			move(getcury(stdscr)+1,getcurx(stdscr));
		}
	}
	return 0;
}

int main(){
	//char* filePath;
	//filePath=getcwd(NULL,0);
	file = getcwd(file, 2048);
	char* cmd;
	int length=0;
	char buff[2048];
	char clipboard[2048];
	while(1){
		if (i == 1){
			initscr();
			start_color();
			init_pair(1, COLOR_RED, COLOR_BLACK);
			attron(COLOR_PAIR(1));
			prompt();
			i++;
			maxX = getcurx(stdscr);
			maxY=getcury(stdscr);
			noecho();
		}
		bzero(buff, 2048);
		length=0;
		raw();
		nonl();
		cbreak();
		keypad(stdscr, true);
		scrollok(stdscr, TRUE);
		//curs_set(0);
		if (buff[0] == 1){
			continue;
		}

		signal(SIGINT, controlC);
		//signal(SIGTSTP, SIG_IGN);
		//int cmdIndex = 0;
		while(1){
		int ch = getch();
		if (maxY<getcury(stdscr)){
			maxY=getcury(stdscr);
			maxX=0;
		}
		if (maxX<getcurx(stdscr)&&getcury(stdscr)==maxY){
			maxX=getcurx(stdscr);
		}
		if (trueMaxX<getcurx(stdscr)){
			trueMaxX=getcurx(stdscr);
		}

		signal(SIGINT, controlC);
		//my_char(ch);
		if (ch == 10 || ch == 13){ //RETURN
			//move(getcury(stdscr)+1,0);
			printw("\n");
			i = 1;
			break;
		}
		else if (ch == KEY_BACKSPACE||ch==127){
			if(getcurx(stdscr)>minX){
				printw(" \b\b ");
				fflush(stdout);
				move(getcury(stdscr), getcurx(stdscr)-1);
				length=length-1;
				buff[length]='\0';
			}
			else{
				move(getcury(stdscr), getcurx(stdscr));
				//printw("\b \b\b \b  \b");
			}
		}
		else if (ch == KEY_LEFT){ //if you dont know what key_left and key_right do, you stupid
			if(getcurx(stdscr)>minX || minY != getcury(stdscr)){
				move(getcury(stdscr), getcurx(stdscr)-1);
				if(getcurx(stdscr)==0){
					move(getcury(stdscr)-1, trueMaxX);
				}
			}

		}
		else if (ch == KEY_RIGHT){
			if(maxX>getcurx(stdscr)||getcury(stdscr)!=maxY){
				if(getcurx(stdscr)==trueMaxX){
					move(getcury(stdscr)+1, 0);
				}
				else{
					move(getcury(stdscr), getcurx(stdscr)+1);
				}
			}
		}
		else if (ch == KEY_UP){
			if(getcury(stdscr)!=0){
			//printw("\b \b");
				move(getcury(stdscr)-1, getcurx(stdscr));
			}
		}
		else if (ch == KEY_DOWN){
			//printw("\b \b");
			move(getcury(stdscr)+1, getcurx(stdscr));
			//printw(buff);
		}
		else if (ch == 12){ //CTRL L- Clear screen and print
			clear();
			prompt();
			//printw("Print current command HERE");
			printw(buff);
			maxX = getcurx(stdscr);
			maxY=getcury(stdscr);
			//i = 1;
		}
		else if (ch == 1){ //CTRL A- move to start of current command DONE
			//printw("\b\b  \b");
			move(minY, minX);
			//printw("You pressed ctrl A");
		}
		else if (ch == 5){ //CTRL E - move to end of current command
			//printw("\b\b  \b");
			move(maxY, maxX); //for getcurx, instead use an int max length
			//printw(" End of Current Command");
		}
		else if (ch == 23){ //CTRL W- cut a word into the clipboard
			fflush(stdout);
			move(getcury(stdscr), 0);
			for(int i = 0; i < trueMaxX; i++){
				printw(" ");
			}
			bzero(clipboard, 2048);
			for(int k=0; k<2048;k++){
				if(buff[k]=='\0')
					break;
				else
				clipboard[k]=buff[k];
			}
			move(getcury(stdscr), 0);
			//prompt();
			i = 1;
			break;
		}
		else if (ch == 21){ //CTRL U- cut a line into the clipboard
			fflush(stdout);
			move(getcury(stdscr), 0);
			for(int i = 0; i < trueMaxX; i++){
				printw(" ");
			}
			bzero(clipboard, 2048);
			for(int k=0; k<2048;k++){
				if(buff[k]=='\0')
					break;
				else
				clipboard[k]=buff[k];
			}
			move(getcury(stdscr), 0);
			//prompt();
			i = 1;
			break;
		}
		else if (ch == 25){ //CTRL Y - paste a word into the clipboard
			//printw("\n");
			//move(getcury(stdscr)-1, 0);
			//prompt();
			if(clipboard[0]!='\0')
				addstr(clipboard);
		}
		else if ((ch>1)&&(ch<26)){

		}
		else{
			printw("%c",ch);
			buff[length]=ch;
			length++;
			buff[length]='\0';
		}
	}
		char ** input = my_str2vect(buff);
		int err = 0;
		cmd = input[0];
		//add_node((void*)cmd, &head);
		// if(my_strcmp(cmd, "ls")==0){
		// 	printw("Wouldn't you like to know\n");
		// }
		if(my_strcmp(cmd, "exit")==0){
			endwin();
			exit(1);
		}
		else if(my_strcmp(cmd, "help")==0){
			printw("Welcome to Not so Fucking Minishell!\nYou will not enjoy this assignment and it will make you cry.\nExit using the command exit.\nChange directory using the command cd filepath.\nGet help using the command help.\nThis is my last assignment in this class and I am relieved. No offense.\n");
		}
		else if(my_strcmp(cmd, "cd")==0){
			free(file);
			err=chdir(input[1]);
			file=getcwd(NULL,0);
			if(my_strcmp(input[1], NULL) ==0 || my_strcmp(input[1], "~") == 0){
                    (void)chdir(getenv("HOME"));
                    file=getcwd(NULL,0);
                }
                else if((chdir(input[1]) == 0)){ }
                else if(err !=0){
					//my_str("\n");
					printw(input[1]);
					printw(" does not exist.");
					printw("\n");
				}
            }
        else if(my_strcmp(cmd, "") == 0){}
		else{
			child=fork();
			if(child < 0){
				printw("Fork error\n");
				exit(1);
			}
			if(child>0){
				wait(NULL);
			}
			else{
				//signal(SIGINT,SIG_IGN);
                //signal(SIGUSR1, ex);
				if(execvp(input[0], input)!=0){
					printw("Not a valid input \n");
					exit(0);
				}
			}

		}
	
		/*
		else if(my_strcmp(cmd, "cd") == 0){
			if(my_strcmp(cmd,"cd ")!=0){
			//printw("it got in here biotch");
			free(filePath);
			err = chdir(input[1]);
			filePath = getcwd(NULL, 0);
			if(err != 0){
				//printw("\n");
				printw(input[1]);
				printw(" is not a valid path.\n");
			}
		}
		}*/

	}

}
