#include "registro.h"

Registro* crear_registros() {
  Registro* registros = (Registro*)calloc(32, sizeof(Registro));

  registros[0].nombre  = (char*)calloc(6, sizeof(char));
  registros[1].nombre  = (char*)calloc(4, sizeof(char));
  registros[2].nombre  = (char*)calloc(4, sizeof(char));
  registros[3].nombre  = (char*)calloc(4, sizeof(char));
  registros[4].nombre  = (char*)calloc(4, sizeof(char));
  registros[5].nombre  = (char*)calloc(4, sizeof(char));
  registros[6].nombre  = (char*)calloc(4, sizeof(char));
  registros[7].nombre  = (char*)calloc(4, sizeof(char));
  registros[8].nombre  = (char*)calloc(4, sizeof(char));
  registros[9].nombre  = (char*)calloc(4, sizeof(char));
  registros[10].nombre = (char*)calloc(4, sizeof(char));
  registros[11].nombre = (char*)calloc(4, sizeof(char));
  registros[12].nombre = (char*)calloc(4, sizeof(char));
  registros[13].nombre = (char*)calloc(4, sizeof(char));
  registros[14].nombre = (char*)calloc(4, sizeof(char));
  registros[15].nombre = (char*)calloc(4, sizeof(char));
  registros[16].nombre = (char*)calloc(4, sizeof(char));
  registros[17].nombre = (char*)calloc(4, sizeof(char));
  registros[18].nombre = (char*)calloc(4, sizeof(char));
  registros[19].nombre = (char*)calloc(4, sizeof(char));
  registros[20].nombre = (char*)calloc(4, sizeof(char));
  registros[21].nombre = (char*)calloc(4, sizeof(char));
  registros[22].nombre = (char*)calloc(4, sizeof(char));
  registros[23].nombre = (char*)calloc(4, sizeof(char));
  registros[24].nombre = (char*)calloc(4, sizeof(char));
  registros[25].nombre = (char*)calloc(4, sizeof(char));
  registros[26].nombre = (char*)calloc(4, sizeof(char));
  registros[27].nombre = (char*)calloc(4, sizeof(char));
  registros[28].nombre = (char*)calloc(4, sizeof(char));
  registros[29].nombre = (char*)calloc(4, sizeof(char));
  registros[30].nombre = (char*)calloc(4, sizeof(char));
  registros[31].nombre = (char*)calloc(4, sizeof(char));


  strcpy(registros[0].nombre, "$zero");
  strcpy(registros[1].nombre,  "$at");
  strcpy(registros[2].nombre,  "$v0");
  strcpy(registros[3].nombre,  "$v1");
  strcpy(registros[4].nombre,  "$a0");
  strcpy(registros[5].nombre,  "$a1");
  strcpy(registros[6].nombre,  "$a2");
  strcpy(registros[7].nombre,  "$a3");
  strcpy(registros[8].nombre,  "$t0");
  strcpy(registros[9].nombre,  "$t1");
  strcpy(registros[10].nombre, "$t2");
  strcpy(registros[11].nombre, "$t3");
  strcpy(registros[12].nombre, "$t4");
  strcpy(registros[13].nombre, "$t5");
  strcpy(registros[14].nombre, "$t6");
  strcpy(registros[15].nombre, "$t7");
  strcpy(registros[16].nombre, "$t8");
  strcpy(registros[17].nombre, "$t9");
  strcpy(registros[18].nombre, "$s0");
  strcpy(registros[19].nombre, "$s1");
  strcpy(registros[20].nombre, "$s2");
  strcpy(registros[21].nombre, "$s3");
  strcpy(registros[22].nombre, "$s4");
  strcpy(registros[23].nombre, "$s5");
  strcpy(registros[24].nombre, "$s6");
  strcpy(registros[25].nombre, "$s7");
  strcpy(registros[26].nombre, "$k0");
  strcpy(registros[27].nombre, "$k1");
  strcpy(registros[28].nombre, "$gp");
  strcpy(registros[29].nombre, "$sp");
  strcpy(registros[30].nombre, "$fp");
  strcpy(registros[31].nombre, "$ra");

  registros[0].estado = 0;

  return registros;
}

void liberar_registros(Registro* r) {
  int i;

  for (i = 0; i < 32; i++) {
    free(r[i].nombre);
  }
  free(r);
}
