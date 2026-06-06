# Cuac Management System (Trees + Hash Version) 🦆

This project implements a message dictionary (called "Cuacs") in C++. The system combines two advanced data structures to optimize performance: **Hash Tables** for fast user-based lookups and **Binary Search Trees (BST)** for maintaining chronological order and performing date-range queries.

## 📂 Project Structure

The source code is organized as follows:

* **`main.cpp`**: Main entry point. Contains the command interpreter and menu logic.
* **`DiccionarioCuacs`**: Container class that coordinates the Hash Table and the Tree.
* **`TablaHash`**: Hash table implementation for indexing users.
* **`Arbol`**: Binary Search Tree implementation for sorting messages.
* **`Cuac`**: Base object representing a message (contains user, date, and text).
* **`Fecha`**: Helper class for precise date and time handling.

## 🛠️ Build & Run

The project includes a `Makefile` to automate compilation.

1.  Open a terminal in the project folder:
    ```bash
    cd main
    ```
2.  Compile the code:
    ```bash
    make
    ```
3.  Run the program (Linux/Mac):
    ```bash
    ./main
    ```
    *Or on Windows:* `main.exe`

## 📖 Usage Guide & Commands

The program does not use a traditional numbered menu ("Press 1 for..."). Instead, it works as a **command interpreter**, reading instructions line by line from standard input (`cin`).

### ⚠️ Date and Time Format

The format is strict. Every date entered must follow this format exactly (including slashes `/` and colons `:`):

`DD/MM/YYYY HH:MM:SS`

---

### 1. Inserting Messages

There are two commands for adding messages, depending on whether the content is predefined or free-form:

#### A. `pcuac` (Predefined Personal Message)

Inserts a message by selecting a phrase from a preset list (1 to 30).

* **Syntax:** `pcuac <user> <datetime> <message_number>`
* **Parameters:**
    * `user`: Username (no spaces).
    * `datetime`: Format `DD/MM/YYYY HH:MM:SS`.
    * `message_number`: An integer from **1 to 30**.
* **Example:**
    ```text
    pcuac @antonio 20/01/2024 10:30:00 5
    ```
    *(This will publish predefined phrase number 5: "Congratulations, champions!")*

#### B. `mcuac` (Free-form Message)

Inserts a message with free text written by the user.

* **Syntax:** `mcuac <user> <datetime> <free_text>`
* **Parameters:**
    * `free_text`: Everything written after the time will be treated as part of the message.
* **Example:**
    ```text
    mcuac @news 21/01/2024 14:00:00 Heatwave in the middle of winter
    ```

---

### 2. Queries & Display

#### `follow` (Follow User)

Searches the **Hash Table** and displays all messages associated with a specific user.

* **Syntax:** `follow <user>`
* **Example:** `follow @antonio`

#### `last` (Latest Messages)

Uses the **Tree** to retrieve the last `N` messages entered in the system (reverse chronological order).

* **Syntax:** `last <amount>`
* **Example:** `last 10`

#### `date` (Date Range)

Displays all messages published between two given dates.

* **Syntax:** `date <start_date> <start_time> <end_date> <end_time>`
* **Example:**
    ```text
    date 01/01/2024 00:00:00 31/01/2024 23:59:59
    ```

### 3. Exit

* **`exit`**: Closes the program.

---

### Full execution flow example

You can copy and paste this block into the terminal to try it out:

```text
pcuac @user1 01/05/2023 12:00:00 1
mcuac @news 02/05/2023 09:30:00 Breaking news
pcuac @user2 03/05/2023 18:45:00 15
last 2
follow @user1
date 01/05/2023 00:00:00 02/05/2023 23:59:59
exit
```
