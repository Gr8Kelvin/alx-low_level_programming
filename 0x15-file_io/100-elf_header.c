#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void chk_elf(unsigned char *e_ident);
void prt_mgc(unsigned char *e_ident);
void prt_class(unsigned char *e_ident);
void prt_data(unsigned char *e_ident);
void prt_vs(unsigned char *e_ident);
void prt_abi(unsigned char *e_ident);
void prt_osabi(unsigned char *e_ident);
void prt_type(unsigned int e_type, unsigned char *e_ident);
void prt_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * chk_elf - Checks
 * @e_ident: A pointer
 * Description: exit code 98.
 */
void chk_elf(unsigned char *e_ident)
{
	int ind;

	for (ind = 0; ind < 4; ind++)
	{
		if (e_ident[ind] != 127 &&
				e_ident[ind] != 'E' &&
				e_ident[ind] != 'L' &&
				e_ident[ind] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * prt_mgc - Prints the magic numbers
 * @e_ident: A pointer to an array
 * Description: Magic numbers
 */
void prt_mgc(unsigned char *e_ident)
{
	int ind;

	printf(" Magic: ");

	for (ind = 0; ind < EI_NIDENT; ind++)
	{
		printf("%02x", e_ident[ind]);

		if (ind == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * prt_class - Prints the class
 * @e_ident: A pointer to an array
 */
void prt_class(unsigned char *e_ident)
{
	printf(" Class: ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * prt_data - Prints the data
 * @e_ident: A pointer to an array
 */
void prt_data(unsigned char *e_ident)
{
	printf(" Data: ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 *prt_vs - Prints the version
 *@e_ident: A pointer to an array.
 */
void prt_vs(unsigned char *e_ident)
{
	printf(" Version: %d",
			e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
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
 * prt_osabi - Prints the OS/ABI
 * @e_ident: A pointer to an array
 */
void prt_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");

	switch (e_ident[EI_OSABI])
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
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * prt_abi - Prints the ABI version
 * @e_ident: A pointer to an array
 */
void prt_abi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n",
			e_ident[EI_ABIVERSION]);
}

/**
 * prt_type - Prints
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array
 */
void prt_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf(" Type: ");

	switch (e_type)
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
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * prt_entry - Prints the entry point
 * @e_entry: The address of the ELF
 * @e_ident: A pointer to an array
 */
void prt_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor
 * Description: - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information
 * @argc: The number of arguments
 * @argv: An array of pointers
 * Return: 0 on suc
 * Description: exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int ode, rde;

	ode = open(argv[1], O_RDONLY);
	if (ode == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(ode);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	rde = read(ode, header, sizeof(Elf64_Ehdr));
	if (rde == -1)
	{
		free(header);
		close_elf(ode);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	chk_elf(header->e_ident);
	printf("ELF Header:\n");
	prt_mgc(header->e_ident);
	prt_class(header->e_ident);
	prt_data(header->e_ident);
	prt_vs(header->e_ident);
	prt_osabi(header->e_ident);
	prt_abi(header->e_ident);
	prt_type(header->e_type, header->e_ident);
	prt_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(ode);
	return (0);
}
