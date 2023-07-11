#include <stdio.h>

typedef struct {
    int hora;
    int min;
    int seg;
}horario;

typedef struct {
    int dia;
    int mes;
    int ano;
}data;

typedef struct {
    data d;
    horario h;
    char texto[200];
}compromisso;

int main (){
    compromisso c1;

    printf("Insira a data deste compromisso: ");
    scanf("%i %i %i", &c1.d.dia, &c1.d.mes, &c1.d.ano);

    printf("Insira o horario deste compromisso: ");
    scanf("%i %i %i", &c1.h.hora, &c1.h.min, &c1.h.seg);

    getchar();

    printf("Insira um texto descrevendo o compromisso: ");
    fgets(c1.texto, sizeof(c1.texto), stdin);

    printf("\n\t Compromisso \n\n");
    printf("Será dia:\t%2i/%2i/%4i\n", c1.d.dia, c1.d.mes, c1.d.ano);
    printf("Ás:\t\t%2ih %2imin %2iseg\n", c1.h.hora, c1.h.min, c1.h.seg);
    printf("Descricao:\t%s", c1.texto);
}