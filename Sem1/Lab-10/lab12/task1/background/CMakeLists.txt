# Задание: Создать библиотеку из background.c и слинковать ее с библиотекой pipes
set(SOURCE_LIB background.c)
add_library(MY_LIB ${SOURCE_LIB})