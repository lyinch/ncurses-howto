#include <ncurses.h>
#include <cstring>

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
void report_choice(int mouse_x, int mouse_y, int *p_choice);

int main(){
    WINDOW *menu_win;
    MEVENT event;

    int highlight = 1;
    int choice = 0;
    int c = 0;

    initscr();
    noecho();
    cbreak();
    curs_set(0);
    startx = (80-WIDTH)/2;
    starty = (24-HEIGHT)/2;

    menu_win = newwin(HEIGHT,WIDTH,starty,startx);
    keypad(menu_win,TRUE);
    mvwprintw(stdscr, 0,0,"Click on EXIT to quit");
    refresh();

    print_menu(menu_win,highlight);
    mousemask(ALL_MOUSE_EVENTS, NULL);

    while(1){
        c = wgetch(menu_win);
        switch (c){
            case KEY_MOUSE:
                if(getmouse(&event) == OK){
                    if(event.bstate & BUTTON1_CLICKED) //left mouse clicked
                    {
                        report_choice(event.x+1,event.y+1,&choice);
                    }
                }
                break;
        }
        print_menu(menu_win,choice);
        if(choice == -1)
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

void report_choice(int mouse_x, int mouse_y, int *p_choice){
    int i, j, choice;
    i = startx + 2;
    j = starty + 3;
    for(choice = 0; choice < n_choices; ++choice){
        if(mouse_y == j + choice && mouse_x >= i && mouse_x <= i + strlen(choices[choice])){
            if(choice == n_choices-1)
                *p_choice = -1;
            else
                *p_choice = choice+1;
            break;
        }
    }
}
