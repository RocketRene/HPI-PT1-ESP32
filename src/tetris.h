#ifndef TETRIS_H
#define TETRIS_H
#include "notes.h"

#ifndef MELODY
#  define MELODY {NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A4, _PAUSE_, NOTE_A4,/**/ _PAUSE_, NOTE_D5, NOTE_F5, NOTE_A5, NOTE_C5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_C5, NOTE_E5, NOTE_F5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A4, _PAUSE_, -1}
#  define RHYTHM {      2,       1,       1,       1,       1,       1,       1,       3,       1,       2,       1,       1,       3,       1,       2,       2,       2,       1,       1,       4,/**/       1,       2,       1,       1,        1,      1,       1,       3,       1,       1,       1,       1,       1,       2,       1,       1,       2,       2,       2,       4,       2};
#else
#  error "Do not include more than one melody file!"
#endif /* MELODY */

#endif /* TETRIS */
