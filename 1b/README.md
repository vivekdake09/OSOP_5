# Shell Scripting Basics

### Overview

| **Topic**                     | **Description**                                                                                                                                      |
|-------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Shell Script**              | A program written in shell language to automate tasks in Unix/Linux systems (e.g., `#!/bin/bash echo "Hello, World!"`).                            |
| **Exit Status**               | Value returned after executing a command, where `0` means success, and non-zero indicates an error (e.g., `echo $?`).                             |
| **User Defined Variables (UDV)** | Custom variables defined by the user in a script to store data (e.g., `NAME="John"`).                                                              |
| **Naming Rules (UDV & System Variables)** | Variable names must start with a letter or underscore, with no spaces or special characters (e.g., `my_var=10`).                      |

---

### Variables in Shell

| **Type**        | **Description**                              | **Example**          |
|-----------------|----------------------------------------------|-----------------------|
| **Local**       | Temporary variables used within scripts      | `count=5`            |
| **Environment** | Global variables used across the system      | `PATH=/usr/bin`      |
| **Positional**  | Arguments passed to a script as `$1`, `$2`, etc. | `script.sh arg1`  |

---

### Operators in Shell

| **Type**          | **Operator** | **Description**                | **Example**          |
|-------------------|--------------|--------------------------------|-----------------------|
| **Arithmetic**    | `+ - * / %`  | Basic math operations          | `$((5 + 3))`         |
| **Relational**    | `-eq -ne -lt -gt -le -ge` | Comparison between values | `[ $a -eq $b ]`      |
| **Logical**       | `&&, ||, !`  | Logical AND, OR, NOT           | `[ $a -gt 5 ] && [ $b -lt 10 ]` |
| **Assignment**    | `=`          | Assign value to a variable      | `count=10`           |

---

### Loops in Shell

| **Loop Type** | **Syntax**                                | **Description**                  | **Example**              |
|---------------|-------------------------------------------|----------------------------------|--------------------------|
| **For**       | `for var in list; do ... done`           | Iterates over a list             | `for i in 1 2 3; do echo $i; done` |
| **While**     | `while condition; do ... done`           | Runs as long as condition is true | `while [ $count -lt 5 ]; do echo $count; count=$((count+1)); done` |
| **Until**     | `until condition; do ... done`           | Runs until condition is true     | `until [ $count -ge 5 ]; do echo $count; count=$((count+1)); done` |

---

### Conditional Statements in Shell

| **Type**   | **Syntax**                                | **Description**                  | **Example**              |
|------------|-------------------------------------------|----------------------------------|--------------------------|
| **If**     | `if condition; then ... fi`               | Executes block if condition is true | `if [ $a -eq $b ]; then echo "Equal"; fi` |
| **If-Else** | `if condition; then ... else ... fi`      | Executes one block if true, another if false | `if [ $a -gt $b ]; then echo "Greater"; else echo "Lesser"; fi` |
| **Else If** | `if ... elif ... else ... fi`             | Multiple conditional checks      | `if [ $a -eq $b ]; then echo "Equal"; elif [ $a -gt $b ]; then echo "Greater"; else echo "Lesser"; fi` |

---

This document provides a concise overview of essential shell scripting concepts and syntax. For more detailed examples and explanations, refer to the shell scripting manual or online documentation.
