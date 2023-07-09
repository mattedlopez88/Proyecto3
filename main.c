#include <stdio.h>
#include <ctype.h>
#include <string.h>


struct paciente{
    char covid[10];
    char direccion[50];
    char provincia[50];
    char region[50];
    char nombre[10];
    char apellido[10];
    int edad;
} paciente[100];

void imprimir_pacientes(int i, int n){
    char ch, chx;
    for ( i = 0; i < n; i++){
        printf("\n*** ");
        for (int j = 0; j < 10; j++){
            ch = paciente[i].nombre[j];
            putchar(toupper(ch));
        }
        printf(" ");
        for (int k = 0; k < 10; k++){
            chx = paciente[i].apellido[k]; 
            putchar(toupper(chx));
        }
        printf(" ***\n");
        printf("Covid: %s\n", paciente[i].covid);
        printf("Edad: %d\n", paciente[i].edad);
        printf("Direccion: %s\n", paciente[i].direccion);
        printf("Provincia: %s\n", paciente[i].provincia);
        printf("Region: %s\n", paciente[i].region);
    }   
}

void exportar_paciente(int n){
    int p_export=0;
    FILE *archivo;
    archivo = fopen("Datos de paciente.txt", "w");
    for (int j = 0; j < n; j++){
        printf("%d. %s %s\n", j+1, paciente[j].nombre, paciente[j].apellido);
    }
    printf("\nIngrese el numero de paciente a exportar: ");
    scanf("%d", &p_export);
    p_export = p_export - 1;
    if (archivo == NULL){
        printf("Error al abrir el archivo\n");
    }else{
        printf("Archivo abierto correctamente!\n");
        fprintf(archivo, "*** PACIENTE %d ***\n", p_export+1);
        fprintf(archivo, "Nombre: %s\n", paciente[p_export].nombre);
        fprintf(archivo, "Apellido: %s\n", paciente[p_export].apellido);
        fprintf(archivo,"Edad: %d\n", paciente[p_export].edad);
        fprintf(archivo, "Direccion: %s\n", paciente[p_export].direccion);
        fprintf(archivo, "Provincia: %s\n", paciente[p_export].provincia);
        fprintf(archivo,"Region: %s\n", paciente[p_export].region);
        printf("Datos de %s %s exportados correctamente!\n", paciente[p_export].nombre, paciente[p_export].apellido);
    }
    fclose(archivo);
}

void editar_paciente(int n){
    int p_edit;
    for (int j = 0; j < n; j++){
        printf("%d. %s %s\n", j+1, paciente[j].nombre, paciente[j].apellido);
    }
    printf("Ingrese el numero de paciente a editar: ");
    scanf("%d", &p_edit);
    printf("\nPaciente %d\n", p_edit);
    printf("Ingrese el nombre: ");
    scanf("%s", paciente[p_edit].nombre);
    printf("Ingrese el apellido: ");
    scanf("%s", paciente[p_edit].apellido);
    printf("Ingrese la edad: ");
    scanf("%d", &paciente[p_edit].edad);
    printf("Ingrese la direccion: ");
    scanf("%s", paciente[p_edit].direccion);
    printf("Ingrese la provincia: ");
    scanf("%s", paciente[p_edit].provincia);
    printf("Ingrese la region: ");
    scanf("%s", paciente[p_edit].region);
}

/*void eliminar_paciente(int i){
    printf("Ingrese el numero de paciente a eliminar: ");
    scanf("%d", &i);
    
    paciente[i].nombre = "null";
    paciente[i].apellido = "null";
    paciente[i].edad = 0;
    paciente[i].direccion = "null";
    paciente[i].provincia = "null";
    paciente[i].region = "null";
}*/

int menu(int vflag, int i, int n){
        int opcion;
    printf("\n***************** MENU *****************\n");
    printf("1. Ver datos de todos los pacientes\n");
    printf("2. Exportar datos de paciente en .txt\n");
    printf("3. Editar datos de paciente\n");
    printf("4. Eliminar paciente\n");
    printf("5. Salir\n");
    printf("\nIngrese una opcion: ");
    scanf("%d", &opcion);
    switch (opcion){
    case 1:
        imprimir_pacientes(i,n);
        break;
    
    case 2:
        exportar_paciente(n);
        break;

    case 3:
        editar_paciente(n);
        break;
    /*
    case 4:
        eliminar_paciente(i);
        break;*/
    case 5:
        vflag = 0;
        break;
    default:
        printf("Opcion no valida\n");
        break;
    }
    return vflag;
}

int main(void) {
    int i, n, vflag = 1;
    printf("\n************ CENTRO MEDICO ************\n");
    printf("Ingrese el numero de pacientes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("\nPaciente %d\n", i+1);
        printf("Ingrese el nombre: ");
        scanf("%s", paciente[i].nombre);
        printf("Ingrese el apellido: ");
        scanf("%s", paciente[i].apellido);
        printf("Ingrese la edad: ");
        scanf("%d", &paciente[i].edad);
        printf("Resultados de Covid p/n: ");
        scanf("%s", paciente[i].covid);
        if (strcmp(paciente[i].covid, "p")==0){
            strcpy( paciente[i].covid, "Positivo" );
        }else{
            strcpy( paciente[i].covid, "Negativo" );
        }
        printf("Ingrese la direccion: ");
        scanf("%s", paciente[i].direccion);
        printf("Ingrese la provincia: ");
        scanf("%s", paciente[i].provincia);
        printf("Ingrese la region: ");
        scanf("%s", paciente[i].region);
    }
    while(vflag == 1){
        menu(vflag, i, n);
    }
    
  
  return 0;
}

