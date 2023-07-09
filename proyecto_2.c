#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct paciente{
    char covid[10];
    char direccion[50];
    char provincia[50];
    char region[50];
    char nombre[50];
    int edad;
} paciente[100];

void añadir_paciente(int *i){
    printf("\nPaciente %d\n", (*i)+1);
    printf("Ingrese el nombre y apellido: ");
    fgets(paciente[*i].nombre, sizeof(paciente[*i].nombre), stdin);
    printf("Ingrese la edad: ");
    scanf("%d", &paciente[*i].edad);
    getchar(); // To consume '\n' character left by scanf.
    printf("Resultados de Covid p/n: ");
    fgets(paciente[*i].covid, sizeof(paciente[*i].covid), stdin);
    if (strcmp(paciente[*i].covid, "p\n")==0){
        strcpy(paciente[*i].covid, "Positivo");
    }else{
        strcpy(paciente[*i].covid, "Negativo");
    }
    printf("Ingrese la direccion: ");
    fgets(paciente[*i].direccion, sizeof(paciente[*i].direccion), stdin);
    printf("Ingrese la provincia: ");
    fgets(paciente[*i].provincia, sizeof(paciente[*i].provincia), stdin);
    printf("Ingrese la region: ");
    fgets(paciente[*i].region, sizeof(paciente[*i].region), stdin);
    (*i)++;
}

void imprimir_pacientes(int *i){
    char ch;
    for ( int j = 0 ; j < *i; j++){
        for (int k = 0; k < 50; k++){
            ch = paciente[j].nombre[k];
            putchar(toupper(ch));
        }
        printf("Covid: %s\n", paciente[j].covid);
        printf("Edad: %d\n", paciente[j].edad);
        printf("Direccion: %s", paciente[j].direccion);
        printf("Provincia: %s", paciente[j].provincia);
        printf("Region: %s", paciente[j].region);
    }   
}

void exportar_paciente(int *i){
    char nombre[50];
    int p_export=0;
    for (int j = 0; j < *i; j++){
        printf("%d. %s %s\n", j+1, paciente[j].nombre);
    }
    printf("\nIngrese el numero de paciente a exportar: ");
    scanf("%d", &p_export);
    p_export = p_export - 1;
    for (int j = 0; j < *i; j++){
        if (strcmp(nombre, paciente[j].nombre)==0){
            FILE *archivo;
            archivo = fopen("paciente.txt", "w");
            fprintf(archivo, "\n*** %s ***\n", paciente[j].nombre);
            fprintf(archivo, "Covid: %s", paciente[j].covid);
            fprintf(archivo, "Edad: %d\n", paciente[j].edad);
            fprintf(archivo, "Direccion: %s", paciente[j].direccion);
            fprintf(archivo, "Provincia: %s", paciente[j].provincia);
            fprintf(archivo, "Region: %s", paciente[j].region);
            fclose(archivo);
            printf("Datos exportados con exito\n");
            return;
        }
    }
    printf("Paciente no encontrado\n");
}

void editar_paciente(int *i){
    char nombre[50];
    printf("Ingrese el nombre del paciente: ");
    fgets(nombre, sizeof(nombre), stdin);
    for (int j = 0; j < *i; j++){
        if (strcmp(nombre, paciente[j].nombre)==0){
            printf("\n*** %s ***\n", paciente[j].nombre);
            printf("Covid: %s", paciente[j].covid);
            printf("Edad: %d\n", paciente[j].edad);
            printf("Direccion: %s", paciente[j].direccion);
            printf("Provincia: %s", paciente[j].provincia);
            printf("Region: %s", paciente[j].region);
            printf("\nIngrese el nombre y apellido: ");
            fgets(paciente[j].nombre, sizeof(paciente[j].nombre), stdin);
            printf("Ingrese la edad: ");
            scanf("%d", &paciente[j].edad);
            getchar(); // To consume '\n' character left by scanf.
            printf("Resultados de Covid p/n: ");
            fgets(paciente[j].covid, sizeof(paciente[j].covid), stdin);
            if (strcmp(paciente[j].covid, "p\n")==0){
                strcpy(paciente[j].covid, "Positivo");
            }else{
                strcpy(paciente[j].covid, "Negativo");
            }
            printf("Ingrese la direccion: ");
            fgets(paciente[j].direccion, sizeof(paciente[j].direccion), stdin);
            printf("Ingrese la provincia: ");
            fgets(paciente[j].provincia, sizeof(paciente[j].provincia), stdin);
            printf("Ingrese la region: ");
            fgets(paciente[j].region, sizeof(paciente[j].region), stdin);
            printf("Datos editados con exito\n");
            return;
        }
    }
    printf("Paciente no encontrado\n");
}

int menu(int *i){
    int opcion;
    printf("\n***************** MENU *****************\n");
    printf("1. Añadir paciente\n");
    printf("2. Ver datos de todos los pacientes\n");
    printf("3. Exportar datos de un paciente en .txt\n");
    printf("4. Editar datos de paciente\n");
    printf("5. Eliminar paciente\n");
    printf("6. Salir\n");
    printf("\nIngrese una opcion: ");
    scanf("%d", &opcion);
    getchar();
    switch (opcion){
    case 1:
        añadir_paciente(i);
        break;
    case 2:
        imprimir_pacientes(i);
        break;
    case 3:
        exportar_paciente(i);
        break;
    case 4:
        editar_paciente(i);
        break;
    case 5:

        break;
    case 6:
        return 0;
    default:
        printf("Opcion no valida\n");
        break;
    }
    return 1;
}

int main(void) {
    int i = 0;
    printf("\n************ CENTRO MEDICO ************\n");
    while(menu(&i));
    return 0;
}
