all:testa_grafoND

testa_grafoND: testa_grafoND_matrizadj.o grafoND_matrizadj.o
	gcc -o testa_grafoND testa_grafoND_matrizadj.o grafoND_matrizadj.o

testa_grafoND_matrizadj.o: testa_grafoND_matrizadj.c grafoND_matrizadj.h
	gcc -c testa_grafoND_matrizadj.c

grafoND_matrizadj.o: grafoND_matrizadj.c grafoND_matrizadj.h
	gcc -c grafoND_matrizadj.c

clean:
	rm -f *.o