/**
 * @mainpage Библиотека хэш-таблиц для строк
 *
 * @section intro Введение
 * Эта библиотека предоставляет функции для работы с хэш-таблицей,
 * где ключи и значения — строки.
 * @section usage Пример использования
 * @code
 * str_hash_table ht = str_hash_table_init(100);
 * str_hash_table_put(ht, "key", "value");
 * char* val = str_hash_table_get(ht, "key");
 * @endcode
 *
 * @section api API
 * Основные функции описаны в файле @ref hash_table_manager.h.
 *
 * @file hash_table_manager.h
 * @brief объявление главных методов хэш-таблицы
*/

#include <stddef.h>
#include <stdint.h>

typedef struct{
    void *array;
    size_t length;
} str_hash_table;

/**
 * @brief инициализирует хэш-таблицу
 * @param length -- количество бакетов в будущей хэш-таблице
 * @return новая хэш-таблица
*/
str_hash_table str_hash_table_init(size_t length);

/**
 * @brief добавляет пару ключ:значение в хэш-таблицу
 * @param hash_table -- хэш-таблица, в которую будет добавляться пара
 * @return ничего не возвращает
*/
void str_hash_table_put(str_hash_table hash_table, char* key, char* value);

/**
 * @brief получает значение по ключу в хэш-таблице
 * @param hash_table -- хэш-таблица, в которой будет поиск значения, key -- ключ, значение от которого функция ищет
 * @return возвращает указатель на строку из хэш-таблицы
*/
char* str_hash_table_get(str_hash_table hash_table, char* key);

/**
 * @brief удаляет пару по ключу в хэш-таблице
 * @param hash_table -- хэш-таблица, в которой будет удаление пары, key -- ключ, пара от которого будет удалена
 * @return ничего не возвращает
*/
void str_hash_table_delete(str_hash_table *hash_table, char* key);

/**
 * @brief удаляет всё что есть в хэш-таблице неоходимо использовать, когда хэш-таблица больше не нужна.
 * @param hash_table -- хэш-таблица, в которой будет всё удалено
 * @return ничего не возвращает
*/
void str_hash_table_free(str_hash_table *hash_table);
//char** str_hash_table__get_pointers_of_strings(str_hash_table hash_table);

typedef struct{
    char** array;
    size_t length;
} array_of_chars_pointers;

array_of_chars_pointers str_hash_table__get_pointers_of_strings(str_hash_table hash_table);