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
2.  Accede a la carpeta de la versión que desees probar (ej. `300` para árboles):
    ```bash
    cd Temas2y3/300
    ```
3.  Compila y ejecuta:
    ```bash
    make
    ./nombre_del_ejecutable
    ```

## 📄 Documentación

Para detalles teóricos sobre las decisiones de diseño y análisis de complejidad, consultar el archivo `Memoria_temas2y3.pdf` incluido en la raíz.

---
*Proyecto realizado para la asignatura de Estructuras de Datos.*
