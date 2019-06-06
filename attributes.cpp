#include <ncurses.h>
#include <stdlib.h>

/* read and print a c/c++ file, print the comments in bold */
int main(int argc, char *argv[]) {
    int ch, prev, row, col;
    prev = EOF;
    FILE * fp;
    int y, x;
    if(argc != 2){
        printf("Usage: %s <a c file name> \n",argv[0]);
        exit(1);
    }
    fp = fopen(argv[1],"r");
    if(fp == NULL){
        perror("Cannot open input file");
        exit(1);
    }

    initscr(); /* comment to highlight */
    raw();
    noecho();
    getmaxyx(stdscr,row,col);
    while((ch = fgetc(fp)) != EOF){
        getyx(stdscr,y,x); //get current cursor position
        if(y == (row-1)){
            printw("<-Press any key ->");
            getch();
            clear();
            move(0,0);
        }

        if(prev == '/' && ch == '*'){
            attron(A_BOLD | A_REVERSE);
            getyx(stdscr,y,x);
            move(y,x-1);
            printw("%c%c",'/',ch);
        }
        else
            printw("%c",ch);
        refresh();
        if(prev == '*' && ch == '/')
            attroff(A_BOLD | A_REVERSE);
        prev = ch;

    }
    getch(); /* comment to highlight */
    endwin();
    fclose(fp);
    return 0;
}