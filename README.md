# Sistema de Gestión de Ventas - Pollería Express 2019

En el Perú, las **pollerías** son establecimientos comerciales que venden el **pollo a la brasa**. Se suele vender en 1/4, y en pollo entero.

Este proyecto es un sistema básico de gestión de ventas desarrollado en C++. Permite registrar, consultar, modificar y eliminar registros de ventas, así como generar reportes totales. Este proyecto aplica varios conceptos fundamentales aprendidos en el curso de "Fundamentos de Programación 2019-2 UPN" en C++.

A continuación se muestra un DEMO [Video de Demostración](https://youtu.be/2nVd3Bp1ONM)

## Tabla de Contenidos

- [Descripción General](#descripción-general)
- [Funcionalidades](#funcionalidades)
- [Conceptos Aplicados](#conceptos-aplicados)
  - [Estructuras y Archivos de Texto](#estructuras-y-archivos-de-texto)
  - [Punteros y Manejo de Memoria](#punteros-y-manejo-de-memoria)
  - [Simulaciones y Juegos](#simulaciones-y-juegos)
  - [Representación de Tipos de Datos y Operaciones con Bits](#representación-de-tipos-de-datos-y-operaciones-con-bits)
  - [Recursividad y Comparación con Iteración](#recursividad-y-comparación-con-iteración)
  - [Métodos de Ordenación y Búsqueda](#métodos-de-ordenación-y-búsqueda)
  - [Archivos de Acceso Aleatorio](#archivos-de-acceso-aleatorio)
  - [Funciones](#funciones)
  - [Uso de Librerías](#uso-de-librerías)

## Descripción General

El proyecto consiste en un programa de consola que gestiona las ventas de una pollería ficticia llamada "Pollería Express". Las operaciones principales incluyen registrar nuevas ventas, buscar ventas existentes, modificar registros de ventas, eliminar registros y generar un reporte total de ventas. Los datos se almacenan en un archivo de texto (`RegistroVentas.txt`), lo que permite su persistencia.

## Funcionalidades

- **Registrar Ventas:** Permite agregar nuevos registros de ventas al sistema.
- **Consultar Ventas:** Visualiza todos los registros de ventas almacenados.
- **Modificar Ventas:** Permite modificar la información de ventas existente.
- **Eliminar Ventas:** Elimina un registro de ventas específico.
- **Buscar Ventas:** Busca un registro de ventas específico por número de pedido.
- **Generar Reporte Total:** Muestra un resumen total de las ventas.

## Conceptos Aplicados

### Estructuras y Archivos de Texto

El programa utiliza archivos de texto para almacenar y gestionar los registros de ventas. Las operaciones como la inserción, búsqueda, modificación y eliminación de registros se realizan mediante la manipulación de estos archivos. Esto demuestra el uso de archivos de texto en aplicaciones prácticas para la gestión de datos.

### Punteros y Manejo de Memoria

Aunque el código no utiliza punteros explícitamente, el conocimiento de manejo de memoria y punteros es fundamental en C++ para manipular estructuras de datos complejas y optimizar el rendimiento.

### Simulaciones y Juegos

El sistema puede considerarse una simulación básica de un punto de venta. El flujo de operaciones a través del menú y la gestión de la lógica del programa reflejan una estructura similar a la de un juego, donde cada operación representa una "acción" o "evento".

### Representación de Tipos de Datos y Operaciones con Bits

El código utiliza tipos de datos estándar de C++ como `int`, `string`, y `bool`. Aunque no se implementan operaciones lógicas con bits, comprender cómo los datos se representan en memoria es crucial para el manejo eficiente de datos.

### Recursividad y Comparación con Iteración

El código utiliza técnicas iterativas, como bucles `while` y `do-while`, para realizar tareas repetitivas. Esto demuestra cómo se pueden aplicar estructuras de bucle iterativas en lugar de recursividad para ciertos problemas.

### Métodos de Ordenación y Búsqueda

Se utiliza un método de búsqueda secuencial en la función `buscar` para localizar registros de ventas específicos. Esto es un ejemplo práctico del método de búsqueda secuencial, uno de los conceptos fundamentales en algoritmos de búsqueda.

### Archivos de Acceso Aleatorio

Aunque el programa actual utiliza archivos secuenciales, los principios de acceso aleatorio pueden aplicarse para mejorar la eficiencia de la gestión de datos en futuras versiones del programa.

### Funciones

El código está estructurado en varias funciones personalizadas (`ingresar`, `consultar`, `eliminar`, `buscar`, `modificar`, `ReporteTotal`) que organizan la lógica del programa en bloques manejables y reutilizables. Este enfoque demuestra la descomposición funcional en la programación estructurada.

### Uso de Librerías

El programa utiliza varias librerías estándar de C++:
- `<iostream>` para entrada y salida estándar.
- `<fstream>` para manipulación de archivos.
- `<string.h>` y `<sstream>` para operaciones con cadenas.
- `<algorithm>` para funciones como `replace`.
- `<stdlib.h>` para funciones de control del sistema.
- `<conio.h>` para la captura de entrada de teclado sin bloqueo.

## Autor: Bernabé Jordán C.
