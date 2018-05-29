#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Entrada: - Puntero a número entero
// Salida:	- Arreglo de strings
// Descripción: Función que abre el archivo solitado por
// el usuario y almacena en un arreglo de punteros a
// caracteres cada una de las instrucciones del programa
// en MIPS, para finalmente retornarlo. Además modifica
// el valor del entero al cual apunta el puntero de entrada
// con la cantidad de instrucciones leidas del archivo
char** manejar_archivo_instrucciones(int* cantidad_instrucciones);

// Entrada: - Puntero a número entero
// Salida:	- Arreglo de strings
// Descripción: Función que abre el archivo solitado por
// el usuario y almacena en un arreglo de punteros a
// caracteres cada línea de control que presenta stuck_at_0
// para finalmente retornarlo. Además modifica el valor del
// entero al cual apunta el puntero de entrada con la
// cantidad de linea de control con problemas.
char** manejar_archivo_control(int* cantidad_lineas_de_control);
