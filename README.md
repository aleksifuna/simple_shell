# Simple Shell Project

This repository contains a simple Unix shell implementation, developed as part of the ALX Software Engineering curriculum. The goal of this project is to build a foundational shell that executes commands, mimicking basic functionality found in standard Unix shells.

## Learning Objectives

By completing this project, you will understand:
- The design and inner workings of a Unix shell
- System calls like `execve`, `fork`, `wait`, and `exit`
- Process and environment management (PID, PPID)
- Path resolution using the `PATH` environment variable
- Basic error handling in shell implementations

## Requirements

- **OS**: Ubuntu 20.04 LTS
- **Compiler**: `gcc` with options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- **Code Style**: Betty style guidelines (checked with `betty-style.pl` and `betty-doc.pl`)
- **Functionality**: Your shell must work in both interactive and non-interactive modes, matching the output of `/bin/sh`
- **Memory**: No memory leaks allowed

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
### Usage
### Interactive mode
```bash
$ ./hsh
($) /bin/ls
```
### Non-Interactive mode
```bash
$ echo "/bin/ls" | ./hsh
```

