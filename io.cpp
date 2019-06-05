#include <iostream>
#include <ncurses.h>
int main() {
    int ch;

    initscr();			// start cursed mode
    raw();              // Send all keys to the program instantly
    //cbreak(); // Disable terminal buffering, but let terminal handle interrupt keys normally
    noecho();           // don't print user input
    keypad(stdscr,TRUE);           // enable reading of function keys F1,... and arrow keys

    addch('a');
    addch('b' | A_BOLD);
    addch('c' | A_BLINK);
    printw("Print at the cursor \n");
    printw("Print %s at the cursor \n","formatted text");
    mvprintw(10,2,"Print %s at the cursor at coordinates y: %d x: %d \n","formatted text",10,2);
    addstr("Print full string to screen \n");
    addnstr("Print only the first 5 characters...",5);
    mvprintw(20,0,"Type any key \n");
    ch = getch();
    if(ch == KEY_UP)
        printw("Arrow UP pressed");
    else{
        printw("The key pressed is ");
        attron(A_UNDERLINE); // activate attribute
        printw("%c", ch);
        attroff(A_UNDERLINE); // turn attribute off
        printw("\n");
    }
    refresh();			// print buffer to screen
    printw("Type a string \n");
    refresh();
    char str[80];
    getstr(str);
    printw("Your string is: %s \n",str);
    refresh();
    int age = 0;
    printw("How old are you \n");
    refresh();
    scanw("%d",&age);
    printw("You are %d years old \n",age);
    mvprintw(LINES-2,0,"We can print at the bottom with the LINES value");
    refresh();
    getch();


    endwin();
    return 0;
}