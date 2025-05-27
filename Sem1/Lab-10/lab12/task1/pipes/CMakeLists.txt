# Задание: Создать библиотеку pipes из read_pipe.c write_pipe.c
set(SOURCE_LIB read_pipe.c)
add_library(MY ${SOURCE_LIB})

set(SOURCE write_pipe.c)
add_library(NEWMY ${SOURCE})