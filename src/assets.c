# include "assets.h"

static struct TT_AssetEntry lTT_assets[] = {
    /* Mnemonicals */
    { "TEB",   L'⊞',    "open branch in tree" },
    { "TCB",   L'⊟',    "collapse opened branch in tree" },
    { "tSI",   L'▲',    "sort in ascending order" },
    { "tSD",   L'▼',    "sort in descending order" },
    { "dll",   L'…',    "textual ellipsis" },
    { "vll",   L'⋮',    "vertical ellipsis" },
    { "hll",   L'⋯',    "horizontal ellipsis" },
    { "sal",   L'◀',    "left scroll arrow" },
    { "sar",   L'▶',    "right scroll arrow" },
    { "knb",   L'◆',    "knob" },
    /* Table decorations */
    { "tjf",   L'┃',    "table major filler" },
    { "tnf",   L'│',    "table minor filler" },
    { "ubj",   L'┏',    "table upmost left corner" },
    { "ubn",   L'┯',    "table upmost separator" },
    /* Tree decorations */
    { "Tfl",   L'┃',    "tree verical opened filler" },
    { "Tbf",   L'┣',    "tree branch fork" },
    { "Tlf",   L'┠',    "tree leaf fork" },
    { "Tle",   L'┖',    "tree last leaf fork" },
    { "Tbe",   L'┗',    "tree last leaf fork" },
    { "TlL",   L'╼',    "tree leaf point" },
    { "TbL",   L'━',    "tree branch point" },
};

const struct TT_AssetEntry * gTT_assets = lTT_assets;

