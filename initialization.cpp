#include <iostream>
#include <ncurses.h>
int main() {
    int ch;

    initscr();			// start cursed mode
    raw();              // Pass the keyboard input directly into the program. raw() for control characters
                        // and cbreak() if the control characters should be handled by the terminal emulator
    noecho();           // don't print user input
    keypad(stdscr,TRUE);           // enable reading of function keys F1,... and arrow keys


    printw("Type any key \n");
    ch = getch();
    if(ch == KEY_UP)
        printw("Arrow UP pressed");
    else{
        printw("The krey pressed is ");
        attron(A_UNDERLINE); // activate attribute
        printw("%c", ch);
        attroff(A_UNDERLINE); // turn attribute off
    }
    refresh();			// print buffer to screen
    getch();			// wait for input
    endwin();
    return 0;
}