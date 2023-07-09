#include <string.h>

#define datos 100

struct paciente {
    char nombre[100];
    char ciudad[80];
    char provincia[80];
    char region[80];
};

void ingresarPacientes(struct paciente pacientes[], int personas) {
     FILE *archivo;
    archivo = fopen("Datos Pacientes.txt", "w");
    printf("Ingrese el número de personas con Covid:\n");
    scanf("%d", &personas);
    getchar(); 
    for (int i = 0; i < personas; i++) {
        printf("\nIngrese el nombre del paciente:\n");
        fgets(pacientes[i].nombre, sizeof(pacientes[i].nombre), stdin);

        printf("\nIngrese la ciudad del paciente:\n");
        fgets(pacientes[i].ciudad, sizeof(pacientes[i].ciudad), stdin);

        printf("\nIngrese la provincia del paciente:\n");
        fgets(pacientes[i].provincia, sizeof(pacientes[i].provincia), stdin);

        printf("\nIngrese la región del paciente:\n");
        fgets(pacientes[i].region, sizeof(pacientes[i].region), stdin);
         fprintf(archivo, "Paciente:\n");
    
    }
    
     fprintf(archivo, "Paciente:\n");
    for (int i = 0; i < personas; i++) {
        fprintf(archivo, "%d            %s ; %s ; %s ; %s", i + 1, pacientes[i].nombre, pacientes[i].ciudad, pacientes[i].provincia, pacientes[i].region);
    }
    fclose(archivo);

}



void cantidadpacientes(struct paciente pacientes[], int personas) {
    int ciudad[datos] = {0};
    int provincia[datos] = {0};
    int region[datos] = {0};
    

    for (int i = 0; i < personas; i++) {
        for (int j = 0; j < personas; j++) {
            if (strcmp(pacientes[i].ciudad, pacientes[j].ciudad) == 0) {
                ciudad[i]++;
            }
            if (strcmp(pacientes[i].provincia, pacientes[j].provincia) == 0) {
                provincia[i]++;
            }
            if (strcmp(pacientes[i].region, pacientes[j].region) == 0) {
                region[i]++;
            }
        }
    }

    printf("\nPacientes por cada ciudad ingresada:\n");
    for (int i = 0; i < personas; i++) {
        printf("%s: %d\n", pacientes[i].ciudad, ciudad[i]);
    }

    printf("\n Pacientes por cada provincia ingresada:\n");
    for (int i = 0; i < personas; i++) {
        printf("%s: %d\n", pacientes[i].provincia, provincia[i]);
    }

    printf("\nPacientes por cada región ingresada:\n");
    for (int i = 0; i < personas; i++) {
        printf("%s: %d\n", pacientes[i].region, region[i]);
    }
    }
    


int main() {
    struct paciente pacientes[datos];
    int personas;
    int opcion;

    
    printf("\n***************** Bienvenido   *****************\n");
     printf("\nEscoge una opciòn:\n");
    printf("1. Añadir paciente\n");
    printf("2. Mostrar cantidad de pacientes en cada regiòn,provincia y ciudad ingresados\n");
    printf("8. Salir\n");
    printf("\nEscoge una opciòn:\n");
    scanf("%d", &opcion);
    getchar();
    switch (opcion) {
        case 1:
            ingresarPacientes;
            break;
        case 2:
         cantidadpacientes;
            break;
        case 3:
            return 0;
        default:
            printf("Opcion no valida\n");
            break;
    }
    

    

    return 0;
}

