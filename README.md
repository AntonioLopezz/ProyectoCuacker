# Sistema de Gestión de Cuacs (Versión Árboles + Hash) 🦆

Este proyecto implementa un diccionario de mensajes (llamados "Cuacs") en C++. El sistema combina dos estructuras de datos avanzadas para optimizar el rendimiento: **Tablas Hash** para búsquedas rápidas por usuario y **Árboles Binarios de Búsqueda (ABB)** para mantener el orden cronológico y realizar consultas por rangos de fechas.

## 📂 Estructura del Proyecto

El código fuente está organizado de la siguiente manera:

* **`main.cpp`**: Punto de entrada principal. Contiene el intérprete de comandos y la lógica del menú.
* **`DiccionarioCuacs`**: Clase contenedora que coordina la Tabla Hash y el Árbol.
* **`TablaHash`**: Implementación de una tabla hash para indexar usuarios.
* **`Arbol`**: Implementación de un Árbol Binario de Búsqueda para ordenar los mensajes.
* **`Cuac`**: Objeto base que representa un mensaje (contiene usuario, fecha y texto).
* **`Fecha`**: Clase auxiliar para el manejo preciso de fechas y horas.

## 🛠️ Compilación y Ejecución

El proyecto incluye un archivo `Makefile` para automatizar la compilación.

1.  Abre una terminal en la carpeta del proyecto:
    ```bash
    cd main
    ```
2.  Compila el código:
    ```bash
    make
    ```
3.  Ejecuta el programa (en Linux/Mac):
    ```bash
    ./main
    ```
    *O en Windows:* `main.exe`

## 📖 Guía de Uso y Comandos

El programa no utiliza un menú numérico tradicional ("Pulse 1 para..."), sino que funciona como un **intérprete de comandos**. Lee instrucciones línea por línea desde la entrada estándar (`cin`).

### ⚠️ Formato de Fecha y Hora
Es estricto. Cualquier fecha introducida debe seguir rigurosamente este formato (incluyendo las barras `/` y los dos puntos `:`):
`DD/MM/AAAA HH:MM:SS`

---

### 1. Insertar Mensajes

Existen dos comandos para añadir mensajes, dependiendo de si el contenido es predefinido o libre:

#### A. `pcuac` (Mensaje Personal Predefinido)
Inserta un mensaje seleccionando una frase de una lista preestablecida (del 1 al 30).

* **Sintaxis:** `pcuac <usuario> <fecha_hora> <numero_mensaje>`
* **Parámetros:**
    * `usuario`: Nombre del usuario (sin espacios).
    * `fecha_hora`: Formato `DD/MM/AAAA HH:MM:SS`.
    * `numero_mensaje`: Un número entero del **1 al 30**.
* **Ejemplo:**
    ```text
    pcuac @antonio 20/01/2024 10:30:00 5
    ```
    *(Esto publicará la frase predefinida número 5: "Enhorabuena, campeones!")*

#### B. `mcuac` (Mensaje de Medio/Máquina)
Inserta un mensaje con texto libre escrito por el usuario.

* **Sintaxis:** `mcuac <usuario> <fecha_hora> <texto_libre>`
* **Parámetros:**
    * `texto_libre`: Todo lo que se escriba después de la hora se considerará parte del mensaje.
* **Ejemplo:**
    ```text
    mcuac @noticias 21/01/2024 14:00:00 Ola de calor en pleno invierno
    ```

---

### 2. Consultas y Visualización

#### `follow` (Seguir Usuario)
Busca en la **Tabla Hash** y muestra todos los mensajes asociados a un usuario específico.
* **Sintaxis:** `follow <usuario>`
* **Ejemplo:** `follow @antonio`

#### `last` (Últimos Mensajes)
Utiliza el **Árbol** para recuperar los últimos `N` mensajes introducidos en el sistema (orden cronológico inverso).
* **Sintaxis:** `last <cantidad>`
* **Ejemplo:** `last 10`

#### `date` (Rango de Fechas)
Muestra todos los mensajes publicados entre dos fechas dadas.
* **Sintaxis:** `date <fecha_inicio> <hora_inicio> <fecha_fin> <hora_fin>`
* **Ejemplo:**
    ```text
    date 01/01/2024 00:00:00 31/01/2024 23:59:59
    ```

### 3. Salir
* **`exit`**: Cierra el programa.

---

### Ejemplo de flujo de ejecución completo

Puedes copiar y pegar este bloque en la terminal para probarlo:

```text
pcuac @usuario1 01/05/2023 12:00:00 1
mcuac @diario 02/05/2023 09:30:00 Noticia de ultima hora
pcuac @usuario2 03/05/2023 18:45:00 15
last 2
follow @usuario1
date 01/05/2023 00:00:00 02/05/2023 23:59:59
exit
