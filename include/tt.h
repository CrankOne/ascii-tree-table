# ifndef H_ASCII_TREETABLE__WIDGET_H
# define H_ASCII_TREETABLE__WIDGET_H

# include <ncursesw/curses.h>

# include "settings.h"
# include "tree.h"

struct TT_widget {
    const struct TT_Settings * settings;

    WINDOW * wndParent  /**< parent window, where widget has to be placed */
         , * wndTree    /**< Pointer to the tree window object */
         , * wndTable   /**< Pointer to the table window object */
         ;

    uint16_t wWidth  /**< Width of the parent window. */
           , wHeight  /**< Height of the parent window. */
           ;
};

/** Creates new TT widget on given parent window. */
struct TT_widget *
TT_widget_create( WINDOW * parent
                , struct TT_Settings * );

/** Performs redrawing of an existing widget. */
void
TT_widget_redraw( struct TT_widget *
                , uint16_t newWidth
                , uint16_t newHeight );

/** Performs actual rendering all the stuff. */
void
TT_widget_render( struct TT_widget * w
                , struct TT_TreeLineEntry * tle
                , const char ** columnNames
                , const char ** path );


/** Aux function, drawing borders (used for dev). */
void draw_borders( WINDOW * );

# endif  /* H_ASCII_TREETABLE__WIDGET_H */

