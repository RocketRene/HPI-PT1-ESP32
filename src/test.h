#ifndef TETRIS_H
#define TETRIS_H
#include "notes.h"

#ifndef MELODY
#  define MELODY {_PAUSE_, NOTE_A3, -1}
#  define RHYTHM {      2,       1,       1,       1,       1,       1,       1,       3,       1,       2,       1,       1,       3,       1,       2,       2,       2,       1,       1,       4,/**/       1,       2,       1,       1,        1,      1,       1,       3,       1,       1,       1,       1,       1,       2,       1,       1,       2,       2,       2,       4,       2};
#else
#  error "Do not include more than one melody file!"
#endif /* MELODY */

#endif /* TETRIS */
