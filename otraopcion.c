#include <stdio.h>
#include <string.h>
#define datos 100

    struct paciente {
    char nombre[100];
    char ciudad[80];
    char provincia[80];
    char region[80];
   };
   
 
   int main() {
       
    FILE *archivo;
    char caracter;
    struct paciente pacientes[datos];
    int personas;

    printf("\nIngrese el número de personas con Covid:\n ");
    scanf("%d", &personas);


        for (int i = 0; i < personas; i++) {    
        printf("\n Nombre:\n  ");
        fgets(pacientes[i].nombre, sizeof(pacientes[i].nombre), stdin);

        printf("\n Ciudad: \n");
       fgets(pacientes[i].ciudad, sizeof(pacientes[i].ciudad), stdin);
         printf("\n Provincia: \n");
       fgets(pacientes[i].provincia, sizeof(pacientes[i].provincia), stdin);

        printf("\n Región:\n");
       fgets(pacientes[i].region, sizeof(pacientes[i].region), stdin);
    }
 
      archivo = fopen("Datos Pacientes.txt", "w");
    fprintf(archivo, "Paciente\n");
    for (int i = 0; i < personas; i++) {
        fprintf(archivo, "%d            %s ; %s ; %s ; %s3", i+1, pacientes[i].nombre, pacientes[i].ciudad, pacientes[i].provincia, pacientes[i].region);
    }
    fclose(archivo);

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
    
   
    return 0;
