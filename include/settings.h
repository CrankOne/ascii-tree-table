# ifndef H_ASCII_TREETABLE__SETTINGS_H
# define H_ASCII_TREETABLE__SETTINGS_H

# include <stdint.h>

/** Entry unique identifier type. */
typedef uint32_t TT_ID;

/** Entry properties flag type (expanded, is leaf, etc). */
typedef uint8_t TT_EntryFlag;

/** General TT settings structure. */
struct TT_Settings {
    /** Fixed width of tree window (typically, 39). */
    uint8_t treeWindowWidth
    /** Default width of each property column (typically, 10) */
          , tableColumnWidth
          ;
    /* ... */
};

# endif  /* H_ASCII_TREETABLE__SETTINGS_H */

