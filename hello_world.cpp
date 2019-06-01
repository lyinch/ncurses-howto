#include <iostream>
#include <ncurses.h>
int main() {
    initscr();			// start cursed mode
    printw("Hello World.");	// let the journey begin
    refresh();			// print buffer to screen
    getch();			// get input
    endwin();
    return 0;
}