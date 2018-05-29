#include "programa.h"

int buscar_etiqueta(char** instrucciones, char* token, int l) {
  int n, m, r;
  for (n = 0; n < l; n++) {
    r = 0;
    if (strstr(instrucciones[n], token) != NULL) {
      printf("%s\n", instrucciones[n]);
      for (m = 0; m < strlen(token); m++) {
        if (token[m] == instrucciones[n][m]) {
          r++;
        }
      }
      if (r == strlen(token)) {
        return n;
      }
    }
  }
  return -1;
}

int validar_control(char** stuck_at_0, char* linea_de_control, int s) {
  int n;
  for (n = 0; n < s; n++) {
    if (!strcmp(stuck_at_0[n], linea_de_control)) {
      return 1;
    }
  }
  return 0;
}

void contador_de_programa(char** instrucciones, Registro* registros, char** stuck_at_0, int** memoria, int l, int s){
  int i, n, r1,r2,r3, offset, label;
  n = 0;
  char* token;
  FILE* archivo_salida1;
  FILE* archivo_salida2;
  archivo_salida1 = fopen("Traza.txt", "w");
  archivo_salida2 = fopen("Registros.txt", "w");

  fprintf(archivo_salida2, "     ");
  for (i = 0; i < 32 ; i ++) {
    fprintf(archivo_salida2, "%5s", registros[i].nombre);
  }
  fprintf(archivo_salida2, "\n");
  while (n < l) {
    label = 0;
    if (n > 0) {
      fprintf(archivo_salida2, "C(%d) ", n);
      for (i = 0; i < 32 ; i ++) {
        fprintf(archivo_salida2, "%5d", registros[i].estado);
      }
      fprintf(archivo_salida2, "\n");
    }
    if (strstr(instrucciones[n], ":") ==  NULL) {
      fprintf(archivo_salida1, "%s", instrucciones[n]);
    }
    token = strtok(instrucciones[n], " )(,");

    if (!strcmp(token, "addi")) {
      if (validar_control(stuck_at_0, "Regdst", s) || validar_control(stuck_at_0, "Aluop", s) || validar_control(stuck_at_0, "Regwrite", s)) {
        n++;
        continue;
      }
      token = strtok(NULL, " )(,");
      for (i = 0; i < 32; i++) {
        if (!strcmp(token, registros[i].nombre)) {
          r1 = i;
        }
      }
      token = strtok(NULL, " )(,");
      for (i = 0; i < 32; i++) {
        if (!strcmp(token, registros[i].nombre)) {
          r2 = i;
        }
      }
      token = strtok(NULL, " )(,");
      offset = atoi(token);

      registros[r1].estado = registros[r2].estado + offset;
      n++;
      continue;
    }

    else if (!strcmp(token, "add")) {
      if (validar_control(stuck_at_0, "Regdst", s) || validar_control(stuck_at_0, "Aluop", s) || validar_control(stuck_at_0, "Regwrite", s)) {
        n++;
        continue;
      }
      token = strtok(NULL, " )(,");
      for (i = 0; i < 32; i++) {
        if (!strcmp(token, registros[i].nombre)) {
          r1 = i;
        }
      }
      token = strtok(NULL, " )(,");
      for (i = 0; i < 32; i++) {
        if (!strcmp(token, registros[i].nombre)) {
          r2 = i;
        }
      }
      token = strtok(NULL, " )(,\n");
      for (i = 0; i < 32; i++) {
        if (!strcmp(token, registros[i].nombre)) {
          r3 = i;
        }
      }

      registros[r1].estado = registros[r2].estado + registros[r3].estado;
      n++;
      continue;
    }

    else if (!strcmp(token, "sub")) {
      if (validar_control(stuck_at_0, "Regdst", s) || validar_control(stuck_at_0, "Aluop", s) || validar_control(stuck_at_0, "Regwrite", s)) {
        n++;
        continue;
      }
      token = strtok(NULL, " )(,");
      for (i = 0; i < 32; i++) {
        if (!strcmp(token, registros[i].nombre)) {
          r1 = i;
        }
      }
      token = strtok(NULL, " )(,");
      for (i = 0; i < 32; i++) {
        if (!strcmp(token, registros[i].nombre)) {
          r2 = i;
        }
      }
      token = strtok(NULL, " )(,\n");
      for (i = 0; i < 32; i++) {
        if (!strcmp(token, registros[i].nombre)) {
          r3 = i;
        }
      }

      registros[r1].estado = registros[r2].estado - registros[r3].estado;
      n++;
      continue;
    }

    else if (!strcmp(token, "subi")) {
      if (validar_control(stuck_at_0, "Regdst", s) || validar_control(stuck_at_0, "Aluop", s) || validar_control(stuck_at_0, "Regwrite", s)) {
        n++;
        continue;
      }
      token = strtok(NULL, " )(,");
      for (i = 0; i < 32; i++) {
        if (!strcmp(token, registros[i].nombre)) {
          r1 = i;
        }
      }
      token = strtok(NULL, " )(,");
      for (i = 0; i < 32; i++) {
        if (!strcmp(token, registros[i].nombre)) {
          r2 = i;
        }
      }
      token = strtok(NULL, " )(,");
      offset = atoi(token);

      registros[r1].estado = registros[r2].estado - offset;
      n++;
      continue;
    }

    else if (!strcmp(token, "mul")) {
      if (validar_control(stuck_at_0, "Regdst", s) || validar_control(stuck_at_0, "Aluop", s) || validar_control(stuck_at_0, "Regwrite", s)) {
        n++;
        continue;
      }
      token = strtok(NULL, " )(,");
      for (i = 0; i < 32; i++) {
        if (!strcmp(token, registros[i].nombre)) {
          r1 = i;
        }
      }
      token = strtok(NULL, " )(,");
      for (i = 0; i < 32; i++) {
        if (!strcmp(token, registros[i].nombre)) {
          r2 = i;
        }
      }
      token = strtok(NULL, " )(,\n");
      for (i = 0; i < 32; i++) {
        if (!strcmp(token, registros[i].nombre)) {
          r3 = i;
        }
      }

      registros[r1].estado = registros[r2].estado * registros[r3].estado;
      n++;
      continue;
    }

    else if (!strcmp(token, "div")) {
      if (validar_control(stuck_at_0, "Regdst", s) || validar_control(stuck_at_0, "Aluop", s) || validar_control(stuck_at_0, "Regwrite", s)) {
        n++;
        continue;
      }
      token = strtok(NULL, " )(,");
      for (i = 0; i < 32; i++) {
        if (!strcmp(token, registros[i].nombre)) {
          r1 = i;
        }
      }
      token = strtok(NULL, " )(,");
      for (i = 0; i < 32; i++) {
        if (!strcmp(token, registros[i].nombre)) {
          r2 = i;
        }
      }
      token = strtok(NULL, " )(,\n");
      for (i = 0; i < 32; i++) {
        if (!strcmp(token, registros[i].nombre)) {
          r3 = i;
        }
      }

      registros[r1].estado = registros[r2].estado / registros[r3].estado;
      n++;
      continue;
    }

    else if (!strcmp(token, "beq")) {
      if (validar_control(stuck_at_0, "Branch", s) || validar_control(stuck_at_0, "Aluop", s)) {
        n++;
        continue;
      }
      token = strtok(NULL, " )(,");
      for (i = 0; i < 32; i++) {
        if (!strcmp(token, registros[i].nombre)) {
          r1 = i;
        }
      }
      token = strtok(NULL, " )(,");
      for (i = 0; i < 32; i++) {
        if (!strcmp(token, registros[i].nombre)) {
          r2 = i;
        }
      }
      token = strtok(NULL, " )(,\n");

      if (registros[r1].estado == registros[r2].estado) {
        n = buscar_etiqueta(instrucciones, token, l);
      }
      else {
        n++;
      }
      continue;
    }

    else if (!strcmp(token, "lw")) {
      if (validar_control(stuck_at_0, "Branch", s) || validar_control(stuck_at_0, "Alusrc", s)) {
        n++;
        continue;
      }
      token = strtok(NULL, " )(,");
      for (i = 0; i < 32; i++) {
        if (!strcmp(token, registros[i].nombre)) {
          r1 = i;
        }
      }

      token = strtok(NULL, " )(,");
      offset = atoi(token)/4;

      token = strtok(NULL, " )(,");
      for (i = 0; i < 32; i++) {
        if (!strcmp(token, registros[i].nombre)) {
          r2 = i;
        }
      }

      registros[r1].estado = memoria[registros[r2].estado][offset];
      n++;
      continue;
    }

    else if (!strcmp(token, "sw")) {
      if (validar_control(stuck_at_0, "Branch", s) || validar_control(stuck_at_0, "Alusrc", s)) {
        n++;
        continue;
      }

      token = strtok(NULL, " )(,");
      for (i = 0; i < 32; i++) {
        if (!strcmp(token, registros[i].nombre)) {
          r1 = i;
        }
      }

      token = strtok(NULL, " )(,");
      offset = atoi(token)/4;

      token = strtok(NULL, " )(,");
      for (i = 0; i < 32; i++) {
        if (!strcmp(token, registros[i].nombre)) {
          r2 = i;
        }
      }

      memoria[registros[r2].estado][offset] = registros[r1].estado;
      n++;
      continue;
    }

    else if (!strcmp(token, "j") || !strcmp(token, "Jump")) {
      if (validar_control(stuck_at_0, "Jump", s)) {
        n++;
        continue;
      }
      token = strtok(NULL, ")(,:");
      n = buscar_etiqueta(instrucciones, token, l);
      continue;
    }

    else {
      label = 1;
      n++;
    }
  }
  if (!label) {
    fprintf(archivo_salida2, "C(%d) ", n);
    for (i = 0; i < 32 ; i ++) {
      fprintf(archivo_salida2, "%5d", registros[i].estado);
    }
    fprintf(archivo_salida2, "\n");
  }

  fclose(archivo_salida1);
  fclose(archivo_salida2);

}

int** crear_memoria() {
  int i;
  int** memoria = (int**)calloc(16, sizeof(int*));

  for (i = 0; i < 16; i++) {
    memoria[i] = (int*)calloc(8, sizeof(int));
  }

  return memoria;
}

void liberar_memoria(int** memoria) {
  int i;
  for (i = 0; i < 16; i++) {
    free(memoria[i]);
  }
  free(memoria);
}

void iniciar() {
  int largo_instrucciones;
  int largo_lineas_de_control;
  char** instrucciones = manejar_archivo_instrucciones(&largo_instrucciones);
  char** stuck_at_0    = manejar_archivo_control(&largo_lineas_de_control);
  Registro* registros  = crear_registros();
  int** memoria        = crear_memoria();

  contador_de_programa(instrucciones, registros, stuck_at_0, memoria, largo_instrucciones, largo_lineas_de_control);

  liberar_registros(registros);
  liberar_memoria(memoria);
}
