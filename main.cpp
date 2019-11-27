#include "Render.h"
#include <ncurses.h>

#ifndef DEBUG
#define DEBUG 0
#endif

int main()
{
    Render r;
    initscr();
    start_color();
    init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
    bkgd(COLOR_PAIR(5));
    printw("test");
    refresh();
    flash();
    r.loop();
    getch();
    return 0;
}
