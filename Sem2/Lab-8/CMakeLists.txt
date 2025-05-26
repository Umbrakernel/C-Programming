cmake_minimum_required(VERSION 3.10)
project(MathUtilsTests)

# Находим CMocka и математическую библиотеку
find_package(cmocka REQUIRED)

# Добавляем исполняемый файл для тестов
add_executable(test_math_utils 
    test_math_utils.c 
    math_utils.c)

# Связываем с CMocka и математической библиотекой
target_link_libraries(test_math_utils cmocka m)

# Добавляем тесты для CTest
enable_testing()
add_test(NAME MathUtilsTests COMMAND test_math_utils)