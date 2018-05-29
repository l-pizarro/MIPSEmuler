#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registro.h"
#include "lectura_archivos.h"

// Entrada: - Arreglo de strings (instrucciones)
//          - Token con la etiqueta a buscar
//          - Número entero (cantidad de instrucciones)
// Salida:	- Número entero con la posición de la etiqueta
// Descripción: La función realiza busca la posición de una
// etiqueta dentro de las instrucciones de un programa
int buscar_etiqueta(char** instrucciones, char* token, int l);

// Entrada: - Arreglo de strings (lineas con stuck_at_0)
//          - Linea de control a validar
//          - Número entero (cantidad de stuck_at_0)
// Salida:	- Número entero (representación booleano)
// Descripción: Función que recorre el arreglo de líneas de
// control con stuck_at_0 y determina si la linea de control
// ingresada posee el problema. Retorna 1 de ser verdadero o 0
// de lo contrario
int validar_control(char** stuck_at_0, char* linea_de_control, int s);

// Entrada: - Arreglo de strings (instrucciones)
//          - Arreglo de registros
//          - Arreglo de strings (lineas con stuck_at_0)
//          - Arreglo de enteros (memoria)
//          - Número entero (cantidad de instrucciones)
//          - Número entero (cantidad de stuck_at_0)
// Salida:	- No posee
// Descripción: Este procedimiento ejecuta cada una de las
// instrucciones del programa en MIPS, escribe dos archivos
// de salida, no con la traza del progrma y otro con los
// valores de los 32 registros para cada instrucción.
void contador_de_programa(char** instrucciones, Registro* registros, char** stuck_at_0, int** memoria, int l, int s);

// Entrada: - No posee
// Salida:	- Puntero a un arreglo de enteros
// Descripción: La función solicita la memoria necesaria
// para simular RAM en la ejecución de un programa en MIPS
int** crear_memoria();

// Entrada: - Matriz de números enteros
// Salida:
// Descripción: El procedimiento libera la memoria utilizada
// para emular la ram
void liberar_memoria(int** memoria);

// Entrada: - No posee
// Salida:	- No posee
// Descripción: Este procedimiento realiza la llamada al resto de
// funciones y procedimientos en un correcto orden
void iniciar();
