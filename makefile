# Nome do executável
EXEC = tic_tac_toe

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -g

# Arquivos objeto
OBJS = functions.o game.o

# Regra padrão (gera o executável)
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Compilação dos arquivos .o a partir dos .c
functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

game.o: game.c functions.h
	$(CC) $(CFLAGS) -c game.c

# Limpa os arquivos compilados
clean:
	rm -f $(OBJS) $(EXEC)
