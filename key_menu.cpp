#include <ncurses.h>

#define WIDTH 30
#define HEIGHT 10

int startx = 0;
int starty = 0;

char *choices[] = {
        "Choice 1",
        "Choice 2",
        "Choice 3",
        "Choice 4",
        "Exit",
};

int n_choices = sizeof(choices) / sizeof(char *);
void print_menu(WINDOW *menu_win, int highlight);

int main(){
    WINDOW *menu_win;
    int highlight = 1;
    int choice = 0;
    int c;

    initscr();
    noecho();
    cbreak();
    curs_set(0);
    startx = (80-WIDTH)/2;
    starty = (24-HEIGHT)/2;

    menu_win = newwin(HEIGHT,WIDTH,starty,startx);
    keypad(menu_win,TRUE);
    mvwprintw(stdscr, 0,0,"Use arrow keys to go up and down, Press enter to select a choice");
    refresh();

    print_menu(menu_win,highlight);
    while(1){
        c = wgetch(menu_win);
        switch (c){
            case KEY_UP:
                if(highlight == 1)
                    highlight = n_choices;
                else
                    --highlight;
                break;
            case KEY_DOWN:
                if(highlight == n_choices)
                    highlight = 1;
                else
                    ++highlight;
                break;
            case 10: //KEY_ENTER is the ENTER on the numerical keyboard. The regular ENTER key is handled by the ASCII char for carriage return
                choice = highlight;
                break;
            default:
                mvprintw(24,0, "Character pressed is %3d Hopefully it can be printed as '%c'",c,c);
                refresh();
                break;
        }
        print_menu(menu_win,highlight);
        if(choice != 0)
            break;
    }
    endwin();
    return 0;
}

void print_menu(WINDOW *menu_win, int highlight){
    int x,y,i;
    x = 2;
    y = 2;
    box(menu_win,0,0);
    for(i = 0; i < n_choices; ++i){
        if(highlight == i+1){
            wattr_on(menu_win,A_REVERSE,NULL);
            mvwprintw(menu_win,y,x,"%s",choices[i]);
            wattr_off(menu_win,A_REVERSE,NULL);
        }else
            mvwprintw(menu_win,y,x,"%s",choices[i]);
        ++y;
    }
    wrefresh(menu_win);
}