cmake_minimum_required(VERSION 3.10)
project(hash_table VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 1. СОБИРАЕМ БИБЛИОТЕКУ ИЗ ВАШИХ ФАЙЛОВ
# Указываем все исходные файлы библиотеки (кроме main.c)
add_library(hash_table
    src/dict_chain.c
    src/dict_couple.c
    src/hash.c
    src/hash_table_manager.c
)

# 2. СОБИРАЕМ ИСПОЛНЯЕМЫЙ ФАЙЛ ИЗ main.c
add_executable(main_program src/main.c)
target_link_libraries(main_program hash_table)

# 3. ЕСЛИ ЕСТЬ include/ С ЗАГОЛОВКАМИ - добавляем
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/include")
    target_include_directories(hash_table PUBLIC include)
endif()

# 4. ДЛЯ ДЕМОНСТРАЦИИ - показываем что собрали
message(STATUS "Библиотека будет собрана из:")
foreach(src_file src/dict_chain.c src/dict_couple.c src/hash.c src/hash_table_manager.c)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${src_file}")
        message(STATUS "  ✓ ${src_file}")
    else()
        message(WARNING "  ✗ ${src_file} не найден!")
    endif()
endforeach()