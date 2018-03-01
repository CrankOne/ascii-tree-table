# include <unistd.h>
# include <locale.h>
# include <stdlib.h>
# include <strings.h>

# include "settings.h"
# include "assets.h"
# include "tree.h"
# include "tt.h"

static struct TT_widget * lTT_w;

static struct TT_Settings lTT_settings = {
      .treeWindowWidth  = 39
    , .tableColumnWidth = 10
    /* ... */
};

//void *
//resize_handler( int signalCode ) {
    // ...
//}

static uint32_t mockNodeNo = 0;

/*
 * Testing stuff
 */

static struct TT_TreeLineEntry *
new_leaf_node( const wchar_t * name
             , const wchar_t * type
             , const wchar_t * color
             , const wchar_t * origin
             , const wchar_t * description ) {
    struct TT_TreeLineEntry * node = malloc( sizeof(struct TT_TreeLineEntry) );
    bzero( node, sizeof(struct TT_TreeLineEntry) );
    node->id = mockNodeNo++;
    node->label = wcsdup(name);
    node->columns = malloc( 4*sizeof(wchar_t*) );
    node->columns[0] = wcsdup( type );
    node->columns[1] = wcsdup( color );
    node->columns[2] = wcsdup( origin );
    node->columns[3] = wcsdup( description );
    node->children = NULL;
    return node;
}

static struct TT_TreeLineEntry *
new_branch_node( const wchar_t * name
               , const wchar_t * type
               , const wchar_t * color
               , const wchar_t * origin
               , const wchar_t * description
               , uint16_t nChildren ) {
    struct TT_TreeLineEntry * node = new_leaf_node(
            name, type, color, origin, description );
    node->flags = TT_kIsBranch;
    node->children = malloc(nChildren*sizeof(struct TT_TreeLineEntry *));
    bzero(node->children, nChildren*sizeof(struct TT_TreeLineEntry *));
    return node;
}

static wchar_t *
mutate_strw( wchar_t * ws ) {
    wchar_t c = (rand() % (0x04FF - 0x0400 + 1)) + 0x0400;
    ws[rand()%wcslen(ws)] = c;
    return ws;
}

static struct TT_TreeLineEntry *
generate_mock_tree( struct TT_TreeLineEntry * original
                  , uint16_t nNodes
                  , float branchingFraction ) {
    struct TT_TreeLineEntry * n = original->children
                          , * lastNode = original->children + nNodes
                          ;
    float branching = branchingFraction*(rand()/(float)(RAND_MAX))*nNodes;
    uint16_t nBranches = branching*nNodes,
             i;
    for( i = 0; i < nBranches; ++i, ++n ) {
        wchar_t name[] = L"child-branch";
        n = new_branch_node( mutate_strw( name )
                           , original->columns[0]
                           , original->columns[1]
                           , original->columns[2]
                           , original->columns[3]
                           , nNodes*branchingFraction );
        mutate_strw( n->columns[0] );
        mutate_strw( n->columns[1] );
        mutate_strw( n->columns[2] );
        mutate_strw( n->columns[3] );
        generate_mock_tree( n, nNodes*branchingFraction, branchingFraction );
        n->flags |= rand() ? TT_kIsOpened : 0;
    }
    for( i = 0; i < nBranches; ++i, ++n ) {
        wchar_t name[] = L"terminating-leaf";
        n = new_leaf_node( mutate_strw( name )
                         , original->columns[0]
                         , original->columns[1]
                         , original->columns[2]
                         , original->columns[3] );
        mutate_strw( n->columns[0] );
        mutate_strw( n->columns[1] );
        mutate_strw( n->columns[2] );
        mutate_strw( n->columns[3] );
    }
    return original;
}

/* ......................................................................... */

int
main(int argc, char *argv[]) {
    setlocale(LC_ALL, "");

    const wchar_t columnNames[][32] = { L"type"
                                      , L"color"
                                      , L"origin"
                                      , L"description" };
    struct TT_TreeLineEntry * root = 
        new_branch_node( L"branch7"
                       , L"grapefruit"
                       , L"magenta"
                       , L"neverland"
                       , L"A grapefruit imported from far-far away land."
                       , 6 );
    generate_mock_tree( root, 128, .15 );

    initscr();
    noecho();
    curs_set(FALSE);

    lTT_w = TT_widget_create( stdscr, &lTT_settings );

    draw_borders( lTT_w->wndTree );
    draw_borders( lTT_w->wndTable );

# if 1
    while(1) {
        //getmaxyx( stdscr, newY, newX );

        // draw to our windows
        mvwprintw(lTT_w->wndTree, 1, 1, "Tree");
        mvwprintw(lTT_w->wndTable, 1, 1, "Table");

        // refresh each window
        wrefresh(lTT_w->wndTree);
        wrefresh(lTT_w->wndTable);
    }
# endif
    //signal( SIGWINCH, resizeHandler );

    endwin();

    return 0;
}

