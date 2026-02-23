#ifndef CONFIG
#define CONFIG

#define TYPE_INT    1
#define TYPE_CHAR_P 2 // char pointer

// Задаём желаемый тип числом
#define TYPE_FOR_DICT TYPE_CHAR_P

#if TYPE_FOR_DICT == TYPE_INT
    typedef int dict_value_t;
#elif TYPE_FOR_DICT == TYPE_CHAR_P
    typedef char* dict_value_t;
#else
    typedef void* dict_value_t;
#endif

#endif
