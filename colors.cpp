#include <ncurses.h>
#include <cstdlib>
#include <cstring>

void print_in_middle(WINDOW *win, char *string);

int main(int argc, char *argv[]){
    initscr();
    if(has_colors() == FALSE || can_change_color() == FALSE){
        endwin();
        printf("Terminal does not support colors \n ");
        exit(-1);
    }

    start_color();
    int ret = init_color(COLOR_RED, 0, 0, 0); // name, r, g, b (min = 0, max = 1000)
    if(ret == ERR){
        endwin();
        printf("Terminal can't change color value \n ");
        exit(-1);
    }

    init_pair(1,COLOR_RED,COLOR_BLACK);
    curs_set(0); //hide the cursor
    attron(COLOR_PAIR(1));
    print_in_middle(stdscr, "This text should be red");
    attroff(COLOR_PAIR(1));
    getch();
    endwin();
    return 0;
}

void print_in_middle(WINDOW *win,  char *string){
    int length, x, y;
    float tmp;

    if(win == NULL)
        win = stdscr;


    length = strlen(string);

    mvwprintw(win,LINES/2,COLS/2-length/2,"%s",string);
    refresh();
}

