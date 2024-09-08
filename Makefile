SRC = main.c tacheOps.c auxillary.c fileOps.c searchOps.c

all: program  run

program: $(SRC)
	gcc -o program $(SRC)

run: program
	./program