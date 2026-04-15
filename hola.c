/*
 * Imprime un saludo por la salida estándar.
 */

#include <stdlib.h> // exit()
#include <stdio.h>

int main(int argc, char *argv[])
{
    char Nombre[50];

    if (argc < 2)
    {
        printf("Uso: %s <nombre>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Hola %s\n", argv[1]);

    exit(EXIT_SUCCESS);
}
