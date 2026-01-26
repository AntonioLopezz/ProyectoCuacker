# Gestión de Diccionario de Datos (Cuacs) en C++ 🦆

Este repositorio contiene el desarrollo incremental de un sistema de gestión de datos implementado en C++. El proyecto explora y compara diferentes estructuras de datos para optimizar el almacenamiento y búsqueda de información.

## 📋 Descripción del Proyecto

El objetivo principal es implementar un diccionario de objetos (denominados `Cuacs`) aplicando conceptos avanzados de programación y estructuras de datos no lineales. El proyecto evoluciona a través de diferentes etapas (Temas 2 y 3), pasando de estructuras lineales básicas a implementaciones más complejas y eficientes.

### 🚀 Evolución y Estructura

El código está organizado en carpetas numeradas que representan las distintas iteraciones y mejoras del software:

* **Versiones Iniciales (001 - 006):** Implementación base utilizando listas y vectores para la gestión secuencial de datos.
* **Tema 2 - Hashing (Carpeta 200):** Refactorización del sistema para utilizar **Tablas Hash** (`TablaHash`), mejorando drásticamente la complejidad temporal en las búsquedas.
* **Tema 3 - Árboles (Carpetas 300 - 302):** Implementación basada en **Árboles Binarios de Búsqueda (ABB)** (`Arbol`), permitiendo un ordenamiento natural de los datos y búsquedas logarítmicas.

## 🛠️ Tecnologías y Conceptos Clave

* **Lenguaje:** C++ (Estándar moderno).
* **Estructuras de Datos:** Tablas Hash (resolución de colisiones), Árboles Binarios, Listas Enlazadas.
* **Gestión de Memoria:** Uso intensivo de punteros y gestión dinámica de memoria.
* **Diseño Modular:** Separación clara entre declaración (`.h`) e implementación (`.cpp`).
* **Compilación:** Automatización mediante `Makefile` para facilitar la construcción en entornos Linux/Unix.

## ✨ Optimizaciones Recientes

Siguiendo principios de *Clean Code*, el proyecto ha sido refactorizado para incluir:
* Eliminación de constructores redundantes para optimizar la inicialización de objetos.
* Agrupación de operaciones de E/S (`std::cout`) para mejorar la legibilidad y reducir la sobrecarga de llamadas al sistema.
* Modularización de clases auxiliares como `Fecha` y `Diccionario`.

## 🔧 Instalación y Ejecución

El proyecto incluye un `Makefile` para una compilación sencilla.

1.  Clona el repositorio:
    ```bash
    git clone [https://github.com/AntonioLopezz/ProyectoCuacker.git](https://github.com/AntonioLopezz/ProyectoCuacker.git)
    ```
2.  Accede a la carpeta de la versión que desees probar (ej. `302` para la versión final con Árboles):
    ```bash
    cd Temas2y3/302
    ```
3.  Compila y ejecuta:
    ```bash
    make
    ./nombre_del_ejecutable
    ```

## 📖 Guía de Uso y Comandos

El programa funciona como un **intérprete de comandos**. Lee instrucciones línea por línea (ya sea escritas a mano o redirigidas desde un fichero).

⚠️ **Importante:** El formato de la fecha debe ser rigurosamente `DD/MM/AAAA HH:MM:SS`.

### 1. Inserción de Datos

Existen dos tipos de entradas que se pueden añadir al diccionario:

* **`pcuac` (Personal Cuac):** Mensaje predefinido.
    * *Sintaxis:* `pcuac <usuario> <fecha> <hora> <numero_mensaje>`
    * *Nota:* El número debe ser un entero entre 1 y 30 (corresponden a frases predefinidas en el sistema).
    * *Ejemplo:* `pcuac @antonio 25/01/2024 14:30:00 5`

* **`mcuac` (Media Cuac):** Mensaje de texto libre.
    * *Sintaxis:* `mcuac <usuario> <fecha> <hora> <mensaje_texto>`
    * *Ejemplo:* `mcuac @noticias 25/01/2024 10:00:00 Ola de calor en invierno`

### 2. Consultas y Visualización

* **`follow`:** Muestra todos los mensajes de un usuario específico.
    * *Sintaxis:* `follow <usuario>`
    * *Ejemplo:* `follow @antonio`

* **`last`:** Muestra los últimos `N` mensajes introducidos (orden cronológico inverso).
    * *Sintaxis:* `last <cantidad>`
    * *Ejemplo:* `last 10`

* **`date`:** Muestra los mensajes publicados en un rango de fechas específico.
    * *Sintaxis:* `date <fecha_inicio> <hora_inicio> <fecha_fin> <hora_fin>`
    * *Ejemplo:* `date 01/01/2024 00:00:00 31/01/2024 23:59:59`

### 3. Salir
* **`exit`:** Termina la ejecución del programa.

---

### Ejemplo completo de flujo de ejecución:

```text
pcuac @usuario1 20/01/2024 12:00:00 1
mcuac @diario 21/01/2024 09:30:00 Titular del dia
last 2
follow @usuario1
exit
