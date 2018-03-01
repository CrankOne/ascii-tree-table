# ifndef H_ASCII_TREETABLE__ASSETS_H
# define H_ASCII_TREETABLE__ASSETS_H

# include <wchar.h>

/** Assets entry struct. Describes an ASCII decoration character. */
struct TT_AssetEntry {
    char name[4];
    wchar_t facet;
    char description[32];
};

/** Pointer to array of assets. */
extern const struct TT_AssetEntry * gTT_assets;

# endif  /* H_ASCII_TREETABLE__ASSETS_H */

