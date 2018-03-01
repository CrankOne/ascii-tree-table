# ifndef H_ASCII_TREETABLE__TREE_STRUCT_H
# define H_ASCII_TREETABLE__TREE_STRUCT_H

# include <wchar.h>

# include "settings.h"

/**@brief Line entry representation.
 *
 * This structure contains only the textual content that is to be displayed
 * (not the actual data).
 * 
 * Entries may be uniquely addresed by their identifier.
 * */
struct TT_TreeLineEntry {
    /** Entry unique identifier. */
    TT_ID id;
    /** Properties. */
    TT_EntryFlag flags;
    /** Entry text label. */
    wchar_t * label;
    /** Entry properties array */
    wchar_t ** columns;
    /** Child entries array */
    struct TT_TreeLineEntry ** children;
};

extern const TT_EntryFlag TT_kIsBranch
                        , TT_kIsOpened
                        /* ... */
                        ;

# endif  /* H_ASCII_TREETABLE__TREE_STRUCT_H */
