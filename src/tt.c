# include "tt.h"
# include "settings.h"

# include <stdlib.h>  // XXX, for malloc()

struct TT_widget *
TT_widget_create( WINDOW * parent
                , struct TT_Settings * s ) {
    struct TT_widget * w = malloc(sizeof(struct TT_widget));
    getmaxyx( parent, (w->wHeight), (w->wWidth) );
    w->wndTree = newwin( w->wHeight
                       , s->treeWindowWidth
                       , 0
                       , 0 );
    w->wndTable = newwin( w->wHeight
                        , w->wWidth - s->treeWindowWidth
                        , 0
                        , s->treeWindowWidth );
    w->settings = s;
    return w;
}

void TT_redraw( struct TT_widget * w
              , uint16_t newWidth
              , uint16_t newHeight ) {
    w->wWidth = newWidth;
    w->wHeight = newHeight;

    wresize( w->wndTree,  w->wHeight, w->settings->treeWindowWidth);
    wresize( w->wndTable, w->wHeight, w->wWidth - w->settings->treeWindowWidth);
    mvwin(w->wndTable, 0, w->settings->treeWindowWidth);

    wclear(w->wndParent);
    wclear(w->wndTree);
    wclear(w->wndTable);

    draw_borders(w->wndTree);
    draw_borders(w->wndTable);
}

void
draw_borders( WINDOW * screen ) {
    int x, y, i;
    getmaxyx(screen, y, x);

    // 4 corners
    mvwprintw(screen, 0, 0, "+");
    mvwprintw(screen, y - 1, 0, "+");
    mvwprintw(screen, 0, x - 1, "+");
    mvwprintw(screen, y - 1, x - 1, "+");

    // sides
    for (i = 1; i < (y - 1); i++) {
        mvwprintw(screen, i, 0, "|");
        mvwprintw(screen, i, x - 1, "|");
    }

    // top and bottom
    for (i = 1; i < (x - 1); i++) {
        mvwprintw(screen, 0, i, "-");
        mvwprintw(screen, y - 1, i, "-");
    }
}
