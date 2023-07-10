#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct paciente {
    char covid[10];
    char ciudad[50];
    char provincia[50];
    char region[50];
    char nombre[50];
    int edad;
} paciente[100];

int contador_provincia[100] = {0};
int contador_ciudad[100] = {0};
int contador_region[100] = {0};

void añadir_paciente(int *i) {
    printf("\nPaciente %d\n", (*i) + 1);
    printf("Ingrese el nombre y apellido: ");
    fgets(paciente[*i].nombre, sizeof(paciente[*i].nombre), stdin);
    printf("Ingrese la edad: ");
    scanf("%d", &paciente[*i].edad);
    getchar(); // Para borrar '\n' que queda en el buffer.
    printf("Resultados de Covid p/n: ");
    fgets(paciente[*i].covid, sizeof(paciente[*i].covid), stdin);
    if (strcmp(paciente[*i].covid, "p\n") == 0) {
        strcpy(paciente[*i].covid, "Positivo");
    } else {
        strcpy(paciente[*i].covid, "Negativo");
    }
    printf("Ingrese la Ciudad: ");
    fgets(paciente[*i].ciudad, sizeof(paciente[*i].ciudad), stdin);
    printf("Ingrese la provincia: ");
    fgets(paciente[*i].provincia, sizeof(paciente[*i].provincia), stdin);
    printf("Ingrese la region: ");
    fgets(paciente[*i].region, sizeof(paciente[*i].region), stdin);

    // Incrementar el contador de provincia
    contador_provincia[*i]++;

    // Incrementar el contador de ciudad
    contador_ciudad[*i]++;

    // Incrementar el contador de región
    contador_region[*i]++;

    (*i)++;
}

void imprimir_pacientes(int *i) {
    char ch;

    for (int j = 0; j < *i; j++) {
        printf("\n");
        for (int k = 0; k < 50; k++) {
            ch = paciente[j].nombre[k];
            putchar(toupper(ch));
        }
        printf("Covid: %s\n", paciente[j].covid);
        printf("Edad: %d\n", paciente[j].edad);
        printf("Ciudad: %s", paciente[j].ciudad);
        printf("Provincia: %s", paciente[j].provincia);
        printf("Region: %s", paciente[j].region);
    }
}

void leer_base_datos(void) {
    FILE *archivo;
    archivo = fopen("datos_pacientes.txt", "r");
    char chx;
    if (archivo == NULL) {
        printf("El archivo no ha sido creado\n");
    } else {
        do {
            chx = fgetc(archivo);
            printf("%c", chx);
        } while (chx != EOF);
    }
    fclose(archivo);
}

void editar_paciente(int *i) {
    int p_edit;
    for (int j = 0; j < *i; j++) {
        printf("%d. %s", j + 1, paciente[j].nombre);
    }
    printf("\nIngrese el numero de paciente a editar: ");
    scanf("%d", &p_edit - 1);

    printf("Ingrese el nombre y apellido: ");
    fgets(paciente[p_edit].nombre, sizeof(paciente[p_edit].nombre), stdin);
    printf("Ingrese la edad: ");
    scanf("%d", &paciente[p_edit].edad);
    getchar(); 
    printf("Resultados de Covid p/n: ");
    fgets(paciente[p_edit].covid, sizeof(paciente[p_edit].covid), stdin);
    if (strcmp(paciente[p_edit].covid, "p\n") == 0) {
        strcpy(paciente[p_edit].covid, "Positivo");
    } else {
        strcpy(paciente[p_edit].covid, "Negativo");
    }
    printf("Ingrese la ciudaf: ");
    fgets(paciente[p_edit].ciudad, sizeof(paciente[p_edit].ciudad), stdin);
    printf("Ingrese la provincia: ");
    fgets(paciente[p_edit].provincia, sizeof(paciente[p_edit].provincia), stdin);
    printf("Ingrese la region: ");
    fgets(paciente[p_edit].region, sizeof(paciente[p_edit].region), stdin);
}

void eliminar_paciente(int *i) {
    int p_delete;
    for (int j = 0; j < *i; j++) {
        printf("%d. %s", j + 1, paciente[j].nombre);
    }
    printf("\nIngrese el numero de paciente a eliminar: ");
    scanf("%d", &p_delete - 1);

    for (int j = 0; j < *i; j++) {
        for (int k = j; k < *i; k++) {
            strcpy(paciente[k].nombre, paciente[k + 1].nombre);
            strcpy(paciente[k].covid, paciente[k + 1].covid);
            paciente[k].edad = paciente[k + 1].edad;
            strcpy(paciente[k].ciudad, paciente[k + 1].ciudad);
            strcpy(paciente[k].provincia, paciente[k + 1].provincia);
            strcpy(paciente[k].region, paciente[k + 1].region);
        }
        (*i)--;
        printf("Paciente eliminado con exito\n");
        return;
    }
    printf("Paciente no encontrado\n");
}

void guardar(int *i) {
    FILE *archivo;
    archivo = fopen("datos_pacientes.txt", "w");
    if (archivo == NULL) {
        printf("No hay datos registrados\n");
        return;
    }

    for (int j = 0; j < *i; j++) {
        fprintf(archivo, "%d ;%s ; %s ; %d; %s ; %s ; %s\n",j+1, paciente[j].nombre,paciente[j].covid,paciente[j].edad,paciente[j].ciudad,paciente[j].provincia,paciente[j].region);
        
    }

    fclose(archivo);
    printf("Datos guardados.\n");
}


void mostrar_estadisticas(int *i) {
    printf("\nCantidad de personas ingresadas dependiendo de la:\n");
    printf("Provincia:\n");
    for (int j = 0; j < i; j++) {
        printf("%s: %d\n", paciente[j].provincia, contador_provincia[j]);
    }
    
    printf("Ciudad:\n");
    for (int j = 0; j < i; j++) {
        printf("%s: %d\n", paciente[j].ciudad, contador_ciudad[j]);
    }
      printf("Región:\n");
    for (int j = 0; j < i; j++) {
        printf("%s: %d\n", paciente[j].region, contador_region[j]);
    }
}

int menu(int *i) {
    int opcion;
    printf("\n***************** MENU *****************\n");
    printf("1. Añadir paciente\n");
    printf("2. Ver datos de todos los pacientes recientemente ingresados\n");
    printf("3. Leer base de datos de pacientes\n");
    printf("4. Editar datos de paciente\n");
    printf("5. Eliminar paciente\n");
    printf("6. Guardar en base de datos\n");
    printf("7. Mostrar cantidad de pacientes en cada regiòn,provincia y ciudad ingresados\n");
    printf("8. Salir\n");
    printf("\nIngrese una opcion: ");
    scanf("%d", &opcion);
    getchar();
    switch (opcion) {
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
            mostrar_estadisticas(i);
            break;
        case 8:
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
    while (menu(&i));
    return 0;
}
