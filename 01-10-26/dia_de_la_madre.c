#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANO_ENTRADA 256

void quitar_salto_linea(char texto[])
{
    texto[strcspn(texto, "\n")] = '\0';
}

int es_mama(const char nombre[])
{
    return strcmp(nombre, "mamá") == 0
        || strcmp(nombre, "Mamá") == 0
        || strcmp(nombre, "MAMÁ") == 0;
}

int main(void)
{
    char nombre[TAMANO_ENTRADA];
    char entrada[TAMANO_ENTRADA];
    char opinion[TAMANO_ENTRADA];
    long opcion;
    double precio;
    double total;
    int descuento;
    FILE *archivo;

    printf("=== Especial Día de la Madre ===\n");
    printf("Por favor, ingresa tu nombre: ");

    if (fgets(nombre, sizeof(nombre), stdin) == NULL) {
        fprintf(stderr, "No se pudo leer el nombre.\n");
        return 1;
    }
    quitar_salto_linea(nombre);

    descuento = es_mama(nombre);
    if (descuento) {
        printf("\n¡Feliz Día de la Madre, mamá! Gracias por todo lo que haces.\n");
        printf("Hoy tienes un descuento especial del 30%%.\n");
    } else {
        printf("\n¡Hola, %s! Te damos la bienvenida.\n", nombre);
    }

    printf("\n--- Menú ---\n");
    printf("1. Desayuno especial - $5000\n");
    printf("2. Almuerzo familiar - $8000\n");
    printf("3. Merienda dulce    - $3000\n");
    printf("Elige una opción (1-3): ");

    if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
        fprintf(stderr, "No se pudo leer la opción del menú.\n");
        return 1;
    }

    char *fin;
    opcion = strtol(entrada, &fin, 10);
    while (*fin == ' ' || *fin == '\t' || *fin == '\n' || *fin == '\r') {
        fin++;
    }
    if (fin == entrada || *fin != '\0' || opcion < 1 || opcion > 3) {
        fprintf(stderr, "Opción inválida. Ejecuta el programa nuevamente y elige del 1 al 3.\n");
        return 1;
    }

    switch (opcion) {
        case 1:
            precio = 5000.0;
            break;
        case 2:
            precio = 8000.0;
            break;
        default:
            precio = 3000.0;
            break;
    }

    total = descuento ? precio * 0.70 : precio;
    printf("Total a pagar: $%.2f\n", total);

    printf("\nCuéntanos tu opinión sobre el menú: ");
    if (fgets(opinion, sizeof(opinion), stdin) == NULL) {
        fprintf(stderr, "No se pudo leer la opinión.\n");
        return 1;
    }
    quitar_salto_linea(opinion);

    archivo = fopen("opiniones.txt", "a");
    if (archivo == NULL) {
        perror("No se pudo abrir opiniones.txt");
        return 1;
    }

    if (fprintf(archivo, "Nombre: %s | Opinión: %s\n", nombre, opinion) < 0) {
        fprintf(stderr, "No se pudo guardar la opinión.\n");
        fclose(archivo);
        return 1;
    }
    if (fclose(archivo) != 0) {
        perror("No se pudo cerrar opiniones.txt");
        return 1;
    }

    printf("¡Gracias! Tu opinión se guardó en opiniones.txt.\n");
    return 0;
}
