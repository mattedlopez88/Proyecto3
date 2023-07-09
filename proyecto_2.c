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
    getchar(); // Para borrar '\n' que queda en el buffer.
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
        printf("\n");
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

void leer_base_datos(void){
    FILE *archivo;
    archivo = fopen("datos_pacientes.txt", "r");
    char chx;
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

void editar_paciente(int *i){
    int p_edit;
    for (int j = 0; j < *i; j++){
        printf("%d. %s", j+1, paciente[j].nombre);
    }
    printf("\nIngrese el numero de paciente a editar: ");
    scanf("%d", &p_edit-1);
    // p_edit = p_edit - 1;
        printf("Ingrese el nombre y apellido: ");
        fgets(paciente[p_edit].nombre, sizeof(paciente[p_edit].nombre), stdin);
        printf("Ingrese la edad: ");
        scanf("%d", &paciente[p_edit].edad);
        getchar(); // Para borrar '\n' que queda en el buffer.
        printf("Resultados de Covid p/n: ");
        fgets(paciente[p_edit].covid, sizeof(paciente[p_edit].covid), stdin);
        if (strcmp(paciente[p_edit].covid, "p\n")==0){
            strcpy(paciente[p_edit].covid, "Positivo");
        }else{
            strcpy(paciente[p_edit].covid, "Negativo");
        }
        printf("Ingrese la direccion: ");
        fgets(paciente[p_edit].direccion, sizeof(paciente[p_edit].direccion), stdin);
        printf("Ingrese la provincia: ");
        fgets(paciente[p_edit].provincia, sizeof(paciente[p_edit].provincia), stdin);
        printf("Ingrese la region: ");
        fgets(paciente[p_edit].region, sizeof(paciente[p_edit].region), stdin);
}

void eliminar_paciente(int *i){
    int p_delete;
    for (int j = 0; j < *i; j++){
        printf("%d. %s", j+1, paciente[j].nombre);
    }
    printf("\nIngrese el numero de paciente a editar: ");
    scanf("%d", &p_delete-1);
    for (int j = 0; j < *i; j++){
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
    printf("Paciente no encontrado\n");
}

void guardar(int *i){
char ch, cap;
    FILE *archivo;
    archivo = fopen("datos_pacientes.txt", "r");
    if (archivo == NULL){
        archivo = fopen("datos_pacientes.txt", "w");
        for (int j = 0; j < *i; j++){

            fprintf(archivo, "\n");
            for (int k = 0; k < 50; k++){
                ch = paciente[j].nombre[k];
                cap = toupper(ch);
                fprintf(archivo, "%c", cap);
            }
            fprintf(archivo,"\nCovid: %s\n", paciente[j].covid);
            fprintf(archivo,"Edad: %d\n", paciente[j].edad);
            fprintf(archivo,"Direccion: %s", paciente[j].direccion);
            fprintf(archivo,"Provincia: %s", paciente[j].provincia);
            fprintf(archivo,"Region: %s", paciente[j].region);
        }
    }else{
        archivo = fopen("datos_pacientes.txt", "a");
        for (int j = 0; j < *i; j++){
            fprintf(archivo, "\n");
            for (int k = 0; k < 50; k++){
                ch = paciente[j].nombre[k];
                cap = toupper(ch);
                fprintf(archivo, "%c", cap);
            }
            fprintf(archivo,"\nCovid: %s\n", paciente[j].covid);
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
    printf("2. Ver datos de todos los pacientes recientemente ingresados\n");
    printf("3. Leer base de datos de pacientes\n");
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
        leer_base_datos();
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
