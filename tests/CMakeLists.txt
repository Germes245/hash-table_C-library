cmake_minimum_required(VERSION 3.15)
project(test)
set(CMAKE_BUILD_TYPE Debug)

# Пути к заголовкам (каждая библиотека имеет свою директорию)
set(DYN_ARRAY_INT_INCLUDE "/usr/local/include/dynamic_array_int")
set(DYN_ARRAY_SIZE_T_INCLUDE "/usr/local/include/dynamic_array_size_t")

# Пути к файлам динамических библиотек (уточните имена!)
# Предположим, файлы называются libdynamic_array_int.so и libdynamic_array_size_t.so
set(DYN_ARRAY_INT_LIBRARY "/usr/local/lib/libdynamic_array_int.so")
set(DYN_ARRAY_SIZE_T_LIBRARY "/usr/local/lib/libdynamic_array_size_t.so")

# Импорт библиотеки для int
add_library(dyn_array_int SHARED IMPORTED)
set_target_properties(dyn_array_int PROPERTIES
    IMPORTED_LOCATION "${DYN_ARRAY_INT_LIBRARY}"
    INTERFACE_INCLUDE_DIRECTORIES "${DYN_ARRAY_INT_INCLUDE}"
)

# Импорт библиотеки для size_t (если нужна в test.c)
add_library(dyn_array_size_t SHARED IMPORTED)
set_target_properties(dyn_array_size_t PROPERTIES
    IMPORTED_LOCATION "${DYN_ARRAY_SIZE_T_LIBRARY}"
    INTERFACE_INCLUDE_DIRECTORIES "${DYN_ARRAY_SIZE_T_INCLUDE}"
)

add_executable(myapp test.c)

# Линкуем обе библиотеки (если test.c использует только int, можно только dyn_array_int)
target_link_libraries(myapp PRIVATE dyn_array_int dyn_array_size_t)