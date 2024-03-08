all:testa_grafo_matriz

testa_grafo_matriz: testa_grafo_matrizadj.o grafo_matrizadj.o
	gcc -o testa_grafo_matriz testa_grafo_matrizadj.o grafo_matrizadj.o

testa_grafo_matrizadj.o: testa_grafo_matrizadj.c grafo_matrizadj.h
	gcc -c testa_grafo_matrizadj.c

grafo_matrizadj.o: grafo_matrizadj.c grafo_matrizadj.h
	gcc -c grafo_matrizadj.c

clean:
	rm -f *.o