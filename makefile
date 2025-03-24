CC = gcc
CFLAGS = -ansi -pedantic 
SRC= code/
OFILES = $(SRC)tableau.o $(SRC)menu.o $(SRC)player.o $(SRC)main.o 
LIBS = -lgraph -lm
EXE = exe

### DEFAULT GOAL ###

install : $(EXE)

### ESSENTIAL RULES ###

$(EXE) : $(OFILES)
	$(CC) $(CFLAGS) -o $(EXE) $(OFILES) $(LIBS)

main.o :main.h tableau.h menu.h player.h
	$(CC) $(CFLAGS) -c main.c $(LIBS)

menu.o : menu.c menu.h 
	$(CC) $(CFLAGS) -c menu.c $(LIBS)

tableau.o : tableau.c tableau.h 
	$(CC) $(CFLAGS) -c tableau.c $(LIBS)

player.o : player.c player.h 
	$(CC) $(CFLAGS) -c player.c $(LIBS)


### OPTIONAL RULES ###

run : install
		./$(EXE)

clean : 
	rm -r $(SRC)/*.o 

cleanall : clean 
	rm -r $(EXE)

