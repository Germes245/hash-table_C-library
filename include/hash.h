#include "config.h"
#if TYPE_FOR_DICT == TYPE_CHAR_P
uint hash_func(unsigned char* text);
#elif TYPE_FOR_DICT == TYPE_INT
#define hash_func(number) (number*10)
#endif