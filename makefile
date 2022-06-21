CC = gcc -Wall -Wextra -std=c99
src= ./src
hear= ./headers
obj= .

all : test

test : $(obj)/main.o $(obj)/faction.o $(obj)/carte.o $(obj)/plateau.o $(obj)/structure.o $(obj)/interface.o 
	$(CC) $(obj)/main.o $(obj)/faction.o $(obj)/carte.o $(obj)/plateau.o $(obj)/structure.o $(obj)/interface.o -o $@


$(obj)%.o: $(src)/%.c $(hear)/%.h
	$(CC) -c $<

$(obj)/main.o : $(src)/main.c
	$(CC) -c $<
	
$(obj)/main.o : $(hear)/carte.h $(hear)/faction.h $(hear)/structure.h $(hear)/plateau.h

$(obj)/carte.o : $(hear)/structure.h

$(obj)/faction.o : $(hear)/carte.h $(hear)/structure.h 

$(obj)/plateau.o : $(hear)/carte.h $(hear)/faction.h $(hear)/interface.h $(hear)/structure.h

$(obj)/structure.o : $(hear)/carte.h $(hear)/faction.h

$(obj)/interface.o : $(hear)/carte.h $(hear)/faction.h $(hear)/plateau.h

