#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct Datos {// Estructura para almacenar los datos de los pacientes.
    char covid[10];
    char direccion[50];
    char provincia[50];
    char region[50];
    char nombre[50];
    int edad;
}paciente[100];


void aniadir_paciente(int *i){// Funcion para aniadir pacientes.
    struct Datos *pacientePtr[100];
    pacientePtr[*i] = &paciente[*i];
    printf("\nPaciente %d\n", (*i)+1);
    printf("Ingrese el nombre y apellido: ");
    fgets(pacientePtr[*i]->nombre, sizeof(pacientePtr[*i]->nombre), stdin);
    printf("Ingrese la edad: ");
    scanf("%d", &pacientePtr[*i]->edad);
    getchar(); // Para borrar '\n' que queda en el buffer.
    printf("Resultados de Covid p/n: ");
    scanf("%s", pacientePtr[*i]->covid);
    // if (strcmp(pacientePtr[*i]->covid, "p\n")==0){
    //     strcpy(pacientePtr[*i]->covid, "Positivo");
    // }else{
    //     strcpy(pacientePtr[*i]->covid, "Negativo");
    // }
    getchar();
    printf("Ingrese la direccion: ");
    fgets(pacientePtr[*i]->direccion, sizeof(pacientePtr[*i]->direccion), stdin);
    printf("Ingrese la provincia: ");
    fgets(pacientePtr[*i]->provincia, sizeof(pacientePtr[*i]->provincia), stdin);
    printf("Ingrese la region: ");
    fgets(pacientePtr[*i]->region, sizeof(pacientePtr[*i]->region), stdin);
    (*i)++;
}

void imprimir_pacientes(int *i){// Funcion para imprimir los datos de los pacientes.
    char ch;
    for ( int j = 0 ; j < *i; j++){// Imprime los datos de los pacientes.
        printf("\n");
            for (int k = 0; k < 50; k++){// Imprime el nombre del paciente en mayusculas.
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

void leer_base_datos(void){// Funcion para leer la base de datos.
    char chx;
    FILE *archivo;
    archivo = fopen("datos_pacientes.txt", "r");// Abre el archivo en modo lectura.
    if (archivo == NULL){// Si el archivo no existe, imprime un mensaje.
        printf("El archivo no ha sido creado\n");
    }else{// Si el archivo existe, imprime su contenido.
        do {
        chx = fgetc(archivo);
        printf("%c", chx);
        } while (chx != EOF); 
    }     
    fclose(archivo);
}

void editar_paciente(int *i){// Funcion para editar los datos de los pacientes.

    int p_edit;
    for (int j = 0; j < *i; j++){
        printf("%d. %s", j+1, paciente[j].nombre);
    }
    printf("\nIngrese el numero de paciente a editar: ");
    scanf("%d", &p_edit);//lee el numero de paciente a editar
    getchar();
    p_edit--;
    printf("Nombre: %s -> ", paciente[p_edit].nombre);//se reemplazan los datos del paciente
    fgets(paciente[p_edit].nombre, sizeof(paciente[p_edit].nombre), stdin);
    printf("Edad: %d\n -> ", paciente[p_edit].edad);
    scanf("%d", &paciente[p_edit].edad);
    getchar();
    printf("Resultados Covid: %s\n -> ", paciente[p_edit].covid);
    scanf("%s", paciente[p_edit].covid);
    // if (strcmp(pacientePtr[*i]->covid, "p\n")==0){
    //     strcpy(pacientePtr[*i]->covid, "Positivo");
    // }else{
    //     strcpy(pacientePtr[*i]->covid, "Negativo");
    // }
    getchar();
    printf("Direccion: %s -> ", paciente[p_edit].direccion);
    fgets(paciente[p_edit].direccion, sizeof(paciente[p_edit].direccion), stdin);
    printf("Provincia: %s -> ", paciente[p_edit].provincia);
    fgets(paciente[p_edit].provincia, sizeof(paciente[p_edit].provincia), stdin);
    printf("Region: %s ->", paciente[p_edit].region);
    fgets(paciente[p_edit].region, sizeof(paciente[p_edit].region), stdin);

}

void eliminar_paciente(int *i){// Funcion para eliminar los datos de los pacientes.

    int p_delete;
    printf("\n");
    for (int j = 0; j < *i; j++){
        printf("%d. %s", j+1, paciente[j].nombre);// imprime los nombres de los pacientes que se pueden eliminar
    }
    printf("\nIngrese el numero de paciente a editar: ");
    scanf("%d", &p_delete);//lee el numero de paciente a eliminar
    getchar();
    p_delete--;
    for (int j = p_delete; j < (*i)-1; j++){
        paciente[j] = paciente[j+1];
    }
    (*i)--;// disminuye el contador de pacientes
    printf("Paciente eliminado con exito\n");
    return;
}

void guardar(int *i){// Funcion para guardar los datos de los pacientes.
    char ch, cap;
    int size;
    FILE *archivo;
    archivo = fopen("datos_pacientes.txt", "r");// abre un archivo para lectura
    if (archivo == NULL){// si el archivo no existe, lo crea
        archivo = fopen("datos_pacientes.txt", "w");// abre un archivo para escritura
        for (int j = 0; j < *i; j++){// guarda los datos de los pacientes en el archivo
            fprintf(archivo, "\n");
            size = sizeof(paciente[j].nombre);
            for (int k = 0; k < size; k++){
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
    }else{// si el archivo existe, agrega los datos de los pacientes al final del archivo
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
    fclose(archivo);// cierra el archivo
    printf("Datos guardados con exito\n");
}

int menu(int *i){// Funcion para mostrar el menu de opciones.
    int opcion;
    printf("\n***************** MENU *****************\n");
    printf("1. Aniadir paciente\n");
    printf("2. Ver datos de todos los pacientes recientemente ingresados\n");
    printf("3. Leer base de datos de pacientes\n");
    printf("4. Editar datos de paciente\n");
    printf("5. Eliminar paciente\n");
    printf("6. Guardar en base de datos\n");
    printf("7. Salir\n");
    printf("\nIngrese una opcion: ");
    scanf("%d", &opcion);
    getchar();
    switch (opcion){// switch para ejecutar las funciones segun la opcion ingresada
    case 1:
        aniadir_paciente(i);// se le pasa la direccion de memoria de la variable i
        break;
    case 2:
        imprimir_pacientes(i);// se le pasa la direccion de memoria de la variable i
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

int main(void){// Funcion principal.
    int i = 0;
    printf("\n************ CENTRO MEDICO ************\n");
    while(menu(&i));// bucle para mostrar el menu hasta que se ingrese la opcion 7
    return 0;
}
