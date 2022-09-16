#pragma once

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

#define DIODE_DIRECTION COL2ROW

#define MATRIX_ROW_PINS { GP2, GP3, GP4, GP19 }
#define MATRIX_COL_PINS { GP10, GP9, GP8, GP7, GP6, GP5, GP25, GP24, GP23, GP22, GP21, GP20 }

#define DEBOUNCE 5
