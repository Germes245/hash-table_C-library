cmake_minimum_required(VERSION 3.10)
project(hash_table VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 1. СОБИРАЕМ БИБЛИОТЕКУ ИЗ ВСЕХ МОДУЛЕЙ (кроме main.c)
add_library(hash_table
    src/dict_chain.c
    src/dict_couple.c
    src/hash.c
    src/hash_table_manager.c
)

# 2. ДОБАВЛЯЕМ ПУТЬ К ЗАГОЛОВОЧНЫМ ФАЙЛАМ
# hash_table.h находится в корне, поэтому добавляем текущую директорию
target_include_directories(hash_table PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 3. СОЗДАЕМ ИСПОЛНЯЕМУЮ ПРОГРАММУ ДЛЯ ТЕСТОВ (из main.c)
add_executable(hash_table_test src/main.c)
target_link_libraries(hash_table_test hash_table)

# 4. НАСТРОЙКА УСТАНОВКИ (опционально, но полезно для библиотеки)
include(GNUInstallDirs)

install(TARGETS hash_table
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(FILES hash_table.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# 5. ИНФОРМАЦИОННОЕ СООБЩЕНИЕ
message(STATUS "=== Hash Table Build Configuration ===")
message(STATUS "Project: ${PROJECT_NAME} v${PROJECT_VERSION}")
message(STATUS "C Standard: ${CMAKE_C_STANDARD}")
message(STATUS "Install prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "================================")