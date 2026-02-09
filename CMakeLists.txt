cmake_minimum_required(VERSION 3.10)
project(hash_table_objects)

set(CMAKE_C_STANDARD 11)

# Устанавливаем выходную директорию для объектных файлов
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Добавляем библиотеку (объектные файлы создадутся автоматически)
#file(GLOB SOURCE_FILES "src/*.c")
add_library(hash_table_objects OBJECT
    src/dict_chain.c
    src/dict_couple.c
    src/hash.c
    src/hash_table_manager.c
)

# Если нужен исполняемый файл
#add_executable(main src/main.c)
#target_link_libraries(main hash_table_objects)