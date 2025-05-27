# Собрать многофайловый проект
# Подсказка: Опция -I в gcc помогает решить проблему с поиском заголовочных файлов. (#include "" No such file or directory)
# Для использования make его необходимо установить: sudo apt install make

main: background.o pipes.o main.o
	gcc -o main background.o read_pipe.o write_pipe.o main.o


background.o:
	gcc -c background/background.c -o background.o -I./pipes

pipes.o:
	gcc -c pipes/read_pipe.c -o read_pipe.o
	gcc -c pipes/write_pipe.c -o write_pipe.o

main.o:
	gcc -c app/main.c -o main.o -I./background
