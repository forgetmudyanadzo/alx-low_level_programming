#include <elf.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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

/**
 * check_elf - Check if the file is a ELF
 * @magic_numbers: pointer to array that contains ELF magic numbers
 */
void check_elf(unsigned char *magic_numbers)
{
	int i;

	/* Check the first four bytes of the header for the ELF magic numbers*/
	for (i = 0; i < 4; i++)
	{
		if (magic_numbers[i] != 127 &&
		    magic_numbers[i] != 'E' &&
		    magic_numbers[i] != 'L' &&
		    magic_numbers[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}
/**
 * print_magic - print magic numbers of the ELF header
 * magic_numbers: pointer to array that contains ELF magic numbers
 */
void print_magic(unsigned char *magic_numbers)
{
	int i;

	printf("  Magic:   ");
/*print the magic numbers in hexadecimal format*/
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", magic_numbers[i]);
    /*add a space between the magic numbers*/

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}
/**
 * print_class - print class of the ELF header.
 * @magic_numbers: pointer to array that contains ELF class
 */
void print_class(unsigned char *magic_numbers)
{
	printf("  Class:                             ");
/*if the class is invalid, print <unkown> and the hex value*/
	switch (magic_numbers[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");/*if class is 32-bit, print ELF32*/
		break;
	case ELFCLASS64:
		printf("ELF64\n");/*if class is 64-bit, print ELF64*/
		break;
	default:
		printf("<unknown: %x>\n", magic_numbers[EI_CLASS]);
	}
}
/**
 * print_data - print data of the ELF header
 * @magic_numbers: pointer to array that contains ELF class
 */
void print_data(unsigned char *magic_numbers)
{
	printf("  Data:                              ");

	switch (magic_numbers[EI_DATA])
	{
	case ELFDATANONE:/*if the encoding is invalid, print none*/
		printf("none\n");
		break;
  /*if the encoding is little-endian, print 2's complement, little endian*/
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
  /*if the encoding is big-endian, print 2's complement, big endian*/
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", magic_numbers[EI_CLASS]);
	}
}
/**
 * print_version - prints version of the ELF header
 * @magic_numbers: pointer to array that contains ELF version
 */
void print_version(unsigned char *magic_numbers)
{
	printf("  Version:                           %d",
	       magic_numbers[EI_VERSION]);

	switch (magic_numbers[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}
/**
 * print_osabi - print OS/ABI of the ELF header
 * @magic_numbers: pointer to array that contains ELF version
 */
void print_osabi(unsigned char *magic_numbers)
{
	printf("  OS/ABI:                            ");

	switch (magic_numbers[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", magic_numbers[EI_OSABI]);
	}
}
/**
 * print_abi - print ABI version of the ELF header
 * @magic_numbers: pointer to array that contains ELF ABI version
 */
void print_abi(unsigned char *magic_numbers)
{
	printf("  ABI Version:                       %d\n",
	       magic_numbers[EI_ABIVERSION]);
}
/**
 * print_type - print type of the ELF header
 * @type: ELF type
 * @magic_numbers: pointer to array that contains ELF class
 */
void print_type(unsigned int type, unsigned char *magic_numbers)
{
	if (magic_numbers[EI_DATA] == ELFDATA2MSB)
		type >>= 8;

	printf("  Type:                              ");

	switch (type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", type);
	}
}
/**
 * print_entry - print entry point of the ELF header
 * @entry: address of ELF entry point
 * @magic_numbers: pointer to array that contains ELF class
 */
void print_entry(unsigned long int entry, unsigned char *magic_numbers)
{
	printf("  Entry point address:               ");

	if (magic_numbers[EI_DATA] == ELFDATA2MSB)
	{
		entry = ((entry << 8) & 0xFF00FF00) |
			  ((entry >> 8) & 0xFF00FF);
		entry = (entry << 16) | (entry >> 16);
	}

	if (magic_numbers[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entry);

	else
		printf("%#lx\n", entry);
}
/**
 * close_elf - close file descriptor of the ELF file
 * @file: file descriptor of ELF file
 */
void close_elf(int file)
{
    if (close(file) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file);
        exit(98);
    }
}
/**
 * main - display information that contained in
 *        ELF header at start of the ELF file
 * @argc: number of the arguments that supplied to the program
 * @argv: array pointers to arguments
 * Return: 0 on success
 */
int main(int _attribute((unused)) argc, char *argv[])
{
    Elf64_Ehdr *header;
    int fd, r;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }

    header = malloc(sizeof(Elf64_Ehdr));
    if (header == NULL)
    {
        close_elf(fd);
        dprintf(STDERR_FILENO, "Error: Can't allocate memory for ELF header\n");
        exit(98);
    }

    r = read(fd, header, sizeof(Elf64_Ehdr));
    if (r == -1)
    {
        free(header);
        close_elf(fd);
        dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
        exit(98);
    }

    check_elf(header->magic_numbers);

    printf("ELF Header:\n");
    print_abi(header->magic_numbers);
    print_magic(header->magic_numbers);
    print_entry(header->entry, magic_numbers);
     print_type(header->type, header->magic_numbers);
    print_version(header->magic_numbers);
    print_osabi(header->magic_numbers);
    print_class(header->magic_numbers);
    print_data(header->magic_numbers);

    free(header);
    close_elf(file);

    return (0);
}
