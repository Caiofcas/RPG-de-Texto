CC = gcc
CFLAGS = -Wall

DPL = Lista.h Lista.c
DPTS = TabelaSim.h TabelaSim.c Lista.o
DPEl = Elemento.h Elemento.c Lista.o TabelaSim.o
DPF = Elemento.o Funcoes.o

DPTestL = testeLista.o Lista.o
DPTestTS = testeTabSim.o TabelaSim.o

DPJOGO = jogo.o Funcoes.o Elemento.o TabelaSim.o Lista.o

#Regra do programa principal
jogo: $(DPJOGO)
	$(CC) -o jogo $(DPJOGO) $(CFLAGS)

#Regra testes da lista
testeLista: $(DPTestL)
	$(CC) -o testeLista $(DPTestL) $(CFLAGS)

#Regra testes da Tabela
testeTabSim: $(DPTestTS)
	$(CC) -o testeTabSim $(DPTestTS) $(CFLAGS)

#arquivos obj
Lista.o: $(DPL)
	$(CC) -c Lista.c $(CFLAGS)

TabelaSim.o: $(DPTS)
	$(CC) -c TabelaSim.c $(CFLAGS)

Elemento.o: $(DPEl)
	$(CC) -c Elemento.c $(CFLAGS)

Funcoes.o: $(DPF)
	$(CC) -c Funcoes.c $(CFLAGS)

jogo.o: jogo.c
	$(CC) -c jogo.c $(CFLAGS)

testeLista.o: testeLista.c
	$(CC) -c testeLista.c $(CFLAGS)

testeTabSim.o: testeTabSim.c
	$(CC) -c testeTabSim.c $(CFLAGS)

clean:
	rm -f *.o