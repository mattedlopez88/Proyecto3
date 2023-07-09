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
    char chx;

    FILE *archivo;
    archivo = fopen("datos_pacientes.txt", "r");

    if (archivo == NULL){
        printf("El archivo no ha sido creado\n");
    }else{
        do {
        chx = fgetc(archivo);
        printf("%c", chx);
        } while (chx != EOF); 
    }     
    fclose(archivo);
    
}

void exportar_paciente(int *i){
    int p_export=0;
    for (int j = 0; j < *i; j++){
        printf("%d. %s", j+1, paciente[j].nombre);
    }
    printf("\nIngrese el codigo del paciente a exportar: ");
    scanf("%d", &p_export);
    p_export = p_export - 1;
    for (int j = 0; j < *i; j++){
        FILE *archivo;
        archivo = fopen("paciente.txt", "w");
        if (archivo == NULL){
            printf("Error al abrir el archivo\n");
        }else{
            printf("Archivo abierto correctamente!\n");
            fprintf(archivo, "*** PACIENTE %d ***\n", p_export+1);
            fprintf(archivo, "Nombre: %s\n", paciente[p_export].nombre);
            fprintf(archivo,"Edad: %d\n", paciente[p_export].edad);
            fprintf(archivo, "Direccion: %s\n", paciente[p_export].direccion);
            fprintf(archivo, "Provincia: %s\n", paciente[p_export].provincia);
            fprintf(archivo,"Region: %s\n", paciente[p_export].region);
            printf("Datos de %s exportados correctamente!\n", paciente[p_export].nombre);
        }
    }
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

void eliminar_paciente(int *i){
    char nombre[50];
    printf("Ingrese el nombre del paciente: ");
    fgets(nombre, sizeof(nombre), stdin);
    for (int j = 0; j < *i; j++){
        if (strcmp(nombre, paciente[j].nombre)==0){
            for (int k = j; k < *i; k++){
                strcpy(paciente[k].nombre, paciente[k+1].nombre);
                strcpy(paciente[k].covid, paciente[k+1].covid);
                paciente[k].edad = paciente[k+1].edad;
                strcpy(paciente[k].direccion, paciente[k+1].direccion);
                strcpy(paciente[k].provincia, paciente[k+1].provincia);
                strcpy(paciente[k].region, paciente[k+1].region);
            }
            (*i)--;
            printf("Paciente eliminado con exito\n");
            return;
        }
    }
    printf("Paciente no encontrado\n");
}

void guardar(int *i){
    FILE *archivo;
    archivo = fopen("datos_pacientes.txt", "r");
    if (archivo == NULL){
        archivo = fopen("datos_pacientes.txt", "w");
        for (int j = 0; j < *i; j++){
            fprintf(archivo, "\n*** PACIENTE %d ***\n", j+1);
            fprintf(archivo, "Nombre: %s", paciente[j].nombre);
            fprintf(archivo,"Edad: %d\n", paciente[j].edad);
            fprintf(archivo, "Direccion: %s", paciente[j].direccion);
            fprintf(archivo, "Provincia: %s", paciente[j].provincia);
            fprintf(archivo,"Region: %s", paciente[j].region);
        }
    }else{
        archivo = fopen("datos_pacientes.txt", "a");
        for (int j = 0; j < *i; j++){
            fprintf(archivo, "\n*** PACIENTE %d ***\n", j+1);
            fprintf(archivo, "Nombre: %s", paciente[j].nombre);
            fprintf(archivo,"Edad: %d\n", paciente[j].edad);
            fprintf(archivo, "Direccion: %s", paciente[j].direccion);
            fprintf(archivo, "Provincia: %s", paciente[j].provincia);
            fprintf(archivo,"Region: %s", paciente[j].region);
        }
    }
    fclose(archivo);
    printf("Datos guardados con exito\n");
}

int menu(int *i){
    int opcion;
    printf("\n***************** MENU *****************\n");
    printf("1. Añadir paciente\n");
    printf("2. Ver datos de todos los pacientes\n");
    printf("3. Exportar datos de un paciente en .txt\n");
    printf("4. Editar datos de paciente\n");
    printf("5. Eliminar paciente\n");
    printf("6. Guardar en base de datos\n");
    printf("7. Salir\n");
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
        eliminar_paciente(i);
        break;
    case 6:
        guardar(i);
        break;
    case 7:
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
