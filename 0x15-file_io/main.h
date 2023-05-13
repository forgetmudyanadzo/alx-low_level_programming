#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFSIZE 1204

int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void print_version(unsigned char *magic_numbers);
void print_class(unsigned char *magic_numbers);
void print_magic(unsigned char *magic_numbers);
void print_abi(unsigned char *magic_numbers);
void print_data(unsigned char *magic_numbers);
void print_type(unsigned int type, unsigned char *magic_numbers);
void close_elf(int file);
void print_osabi(unsigned char *magic_numbers);
void print_entry(unsigned long int entry, unsigned char *magic_numbers);
void check_elf(unsigned char *magic_numbers);

#endif
