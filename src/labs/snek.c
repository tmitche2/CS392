#include <ncurses.h>
#include <unistd.h>
#include <sys/select.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WALL_CHAR '+'
int numDeaths=0;
int MAXHEIGHT=30;
int MAXWIDTH=70;
int kbhit (void) {
  struct timeval tv;
  fd_set read_fd;
  tv.tv_sec=0;
  tv.tv_usec=0;
  FD_ZERO(&read_fd);
  FD_SET(0,&read_fd);
  if(select(1, &read_fd, NULL, NULL, &tv) == -1){
    return 0;
  }
  if(FD_ISSET(0,&read_fd)){
    return 1;
  }return 0;
}

int colliding(int *snakeArray) {
  int x = *snakeArray;
  int y = *(snakeArray+1);
  if (x < 1 || x > MAXWIDTH) {
    return 1;
  }
  else if (y < 1 || y > MAXHEIGHT) {
    return 1;
  }
  else if ((mvinch(y, x) & A_CHARTEXT) == '#'||(mvinch(y, x) & A_CHARTEXT) == 'O'){
    return 1;
  }return 0;
}
void moveSnake(int *snakeArray, int dirX, int dirY, int speed, int snakeLength, char* a) {
  int oldX = 0;
  int oldY = 0;
  int curX = *snakeArray;
  int curY = *(snakeArray+1);
  int newX = curX + dirX;
  int newY = curY + dirY;
  *(snakeArray) = newX;
  *(snakeArray+1) = newY;
  mvprintw(newY, newX, "I");
  for (size_t i = 2; i < snakeLength*2; i += 2) {
    oldX = curX;
    oldY = curY;
    curX = *(snakeArray+i);
    curY = *(snakeArray+i+1);
    newX = oldX;
    newY = oldY;
    *(snakeArray+i) = newX;
    *(snakeArray+i+1) = newY;
    mvprintw(newY, newX, a);
  }
  if (dirY != 0) {
    usleep(1000000/speed);
  }usleep(1000000/speed);
}
void spawnPellet(int* pelletX, int* pelletY, int *pelletEaten) {
  if (*pelletEaten) {
    srand(time(0));
    *pelletX = (rand() % MAXWIDTH)+1;
    *pelletY = (rand() % MAXHEIGHT)+1;
    *pelletEaten = 0;
  }
  mvprintw(*pelletY, *pelletX,"*");
}
void drawLevel() {
    for (int i=0; i<MAXHEIGHT+1; i++) {
        mvaddch(i, 0, WALL_CHAR);
        mvaddch(i, MAXWIDTH+1, WALL_CHAR);
    }
    for (int i=1; i<MAXWIDTH+1; i++) {
        mvaddch(0, i, WALL_CHAR);
        mvaddch(MAXHEIGHT+1, i, WALL_CHAR);
    }
}
void eatPellet(int *snakeArray, int pelletX, int pelletY, int *pelletEaten, int *snakeLength) {
  int x = *snakeArray;
  int y = *(snakeArray+1);
  if (x == pelletX && y == pelletY) {
    *pelletEaten = 1;
    *snakeLength += 1;
    int snakeLen = *snakeLength;
    int lastX = *(snakeArray + snakeLen*2-2);
    int lastY = *(snakeArray + snakeLen*2-2+1);
    *(snakeArray + snakeLen*2) = lastX;
    *(snakeArray + snakeLen*2+1) = lastY;
  }
  mvprintw(0,MAXWIDTH+3,"Current Score: %d", *snakeLength-3);
  mvprintw(1,MAXWIDTH+3,"Death Count: %d", *(&numDeaths));
}
int main() {
  //snake 1 variables
  int snakeArray[100][2];
  snakeArray[0][0] = 3;
  snakeArray[0][1] = 3;
  int keyPressed = 0;
  int dirX = 1;
  int dirY = 0;
  int speed = 20;
  int pelletX = 0;
  int pelletY = 0;
  int pelletEaten = 1;
  int snakeLength = 3;
  //snake 2 variables
  /*int snakeArray2[100][2];
  snakeArray2[0][0] = MAXWIDTH-3;
  snakeArray2[0][1] = MAXHEIGHT-3;
  //int keyPressed2=0;
  int dirX2 = -1;
  int dirY2 = 0;
  int pelletX2 = 0;
  int pelletY2 = 0;
  int pelletEaten2 = 1;
  int snakeLength2 = 3;*/

  initscr();
  printf("maxh= %i maxw= %i\n",MAXHEIGHT, MAXWIDTH  );
  curs_set(false);
  noecho();
  while (1) {
    if(colliding(&snakeArray[0][0])){
    erase();
    numDeaths++;
    snakeArray[0][0] = 3;
    snakeArray[0][1] = 3;
    keyPressed = 0;
    dirX = 1;
    dirY = 0;
    snakeLength = 3;
    }
    /*if(colliding(&snakeArray2[0][0])){
    erase();
    numDeaths++;
    snakeArray2[0][0] = MAXWIDTH-3;
    snakeArray2[0][1] = MAXHEIGHT-3;
    //keyPressed2 = 0;
    dirX2 = -1;
    dirY2 = 0;
    snakeLength2 = 3;
    }*/
    erase();
    spawnPellet(&pelletX, &pelletY, &pelletEaten);
    moveSnake(&snakeArray[0][0], dirX, dirY, speed, snakeLength, "+");
    eatPellet(&snakeArray[0][0], pelletX, pelletY, &pelletEaten, &snakeLength);
    //moveSnake(&snakeArray2[0][0], dirX2, dirY2, speed, snakeLength2, "&");
    //eatPellet(&snakeArray2[0][0], pelletX2, pelletY2, &pelletEaten2, &snakeLength2);
    drawLevel();
    refresh();
    if (kbhit()) {
      keyPressed = getch();
      //keyPressed2 = getch();
      if (keyPressed == 'w') {
        dirY = -1;
        dirX = 0;
      }
      if (keyPressed == 's') {
        dirY = 1;
        dirX = 0;
      }
      if (keyPressed == 'a') {
        dirX = -1;
        dirY = 0;
      }
      if (keyPressed == 'd') {
        dirX = 1;
        dirY = 0;
      }
      /*if (keyPressed == KEY_UP) {
        exit(0);
        endwin();
        dirY2 = -1;
        dirX2 = 0;
      }
      if (keyPressed == KEY_DOWN) {
        dirY2 = 1;
        dirX2 = 0;
      }
      if (keyPressed == KEY_LEFT) {
        dirX2 = -1;
        dirY2 = 0;
      }
      if (keyPressed == KEY_RIGHT) {
        dirX2 = 1;
        dirY2 = 0;
      }*/
    }
  }

  refresh();
  getch();
  endwin();

  return 0;
}