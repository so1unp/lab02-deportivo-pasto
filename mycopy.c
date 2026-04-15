/*
 * Copia un archivo en otro.
 */

#include <stdlib.h> // exit()
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

    if (argc != 4)
    {
        printf("Uso: %s [s|f] origen destino\n", argv[0]);
        exit(1);
    }

    char buffer[100];
    ssize_t n;

    if (argv[1][0] == 's' && argv[1][1] == '\0')
    {
        int fd_origen = open(argv[2], O_RDONLY);

        if (fd_origen == -1)
        {
            perror("Archivo Origen no existe");
            exit(1);
        }

        int fd_destino = open(argv[3], O_WRONLY | O_CREAT | O_EXCL, 0644);

        if (fd_destino == -1)
        {
            perror("Error archivo destino");
            exit(1);
        }

        while ((n = read(fd_origen, buffer, 100)) > 0)
        {
            write(fd_destino, buffer, n);
        }

        close(fd_origen);
        close(fd_destino);
    }
    else if (argv[1][0] == 'f' && argv[1][1] == '\0')
    {
        FILE *origen = fopen(argv[2], "r");
        if (origen == NULL)
        {
            perror("Error al abrir archivo");
            exit(1);
        }

        FILE *destino = fopen(argv[3], "r");

        if (destino != NULL)
        {
            fclose(destino);
            perror("El Archivo existe");
            exit(1);
        }

        destino = fopen(argv[3], "w");
        if (destino == NULL)
        {
            exit(1);
        }

        while ((n = fread(buffer, 1, 100, origen)) > 0)
        {
            fwrite(buffer, 1, n, destino);
        }
        fclose(origen);
        fclose(destino);
    }
    else
    {
        printf("Modo inválido\n");
        exit(1);
    }

    exit(EXIT_SUCCESS);
}
