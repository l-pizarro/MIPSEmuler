#include "lectura_archivos.h"

char** manejar_archivo_instrucciones(int* largo) {
  FILE*  archivo;
  char   instruccion[50];
  char   nombre_archivo[50];
  char** instrucciones;

  printf("\nIngrese nombre del archivo con instrucciones: ");
  scanf("%s", nombre_archivo);
  archivo       = fopen(nombre_archivo, "r");
  instrucciones = NULL;

  if (archivo){
    *largo        = 0;
    instrucciones = (char**)calloc(1, sizeof(char*));
    while ( fgets(instruccion, 50, archivo)) {
      instrucciones         = (char**)realloc(instrucciones, (*largo + 1) * sizeof(char*));
      instrucciones[*largo] = (char*)malloc(sizeof(char) * strlen(instruccion));
      strcpy(instrucciones[*largo], instruccion);
      (*largo) ++;
    }
    fclose(archivo);
  }
  else {
    printf("El archivo '%s' no se encuentra\n", nombre_archivo);
  }

  return instrucciones;
}

char** manejar_archivo_control(int* largo) {

  FILE*  archivo;
  char   linea_de_control[50];
  char   nombre_archivo[50];
  char*  auxiliar;
  char** stuck_at_0;

  printf("\nIngrese nombre del archivo con las líneas de control: ");
  scanf("%s", nombre_archivo);
  archivo       = fopen(nombre_archivo, "r");
  stuck_at_0 = NULL;


  if (archivo){
    *largo    = 0;
    stuck_at_0 = (char**)calloc(1, sizeof(char*));
    while ( fgets(linea_de_control, 50, archivo)) {
      if (strchr(linea_de_control, '0') != NULL) {
        auxiliar            = strtok(linea_de_control, " ");
        stuck_at_0          = (char**)realloc(stuck_at_0, (*largo + 1) * sizeof(char *));
        stuck_at_0[*largo] = (char*)malloc(sizeof(char) * strlen(auxiliar));
        strcpy(stuck_at_0[*largo], auxiliar);
        (*largo) ++;
      }
    }
    fclose(archivo);
  }
  else {
    printf("El archivo '%s' no se encuentra\n", nombre_archivo);
  }

  return stuck_at_0;
}
