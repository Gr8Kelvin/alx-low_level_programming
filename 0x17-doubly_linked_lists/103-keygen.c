#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - generate a key
 * @argc: number of arguments passed
 * @argv: arguments passed to main
 * Return: 0 , 1
 */
int main(int argc, char *argv[])
{
	unsigned int irs, brs;
	size_t lenrs, addrs;
	char *lrs = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char prs[7] = "      ";

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}
	lenrs = strlen(argv[1]);
	prs[0] = lrs[(lenrs ^ 59) & 63];
	for (irs = 0, addrs = 0; irs < lenrs; irs++)
		addrs += argv[1][irs];
	prs[1] = lrs[(addrs ^ 79) & 63];
	for (irs = 0, brs = 1; irs < lenrs; irs++)
		brs *= argv[1][irs];
	prs[2] = lrs[(brs ^ 85) & 63];
	for (brs = argv[1][0], irs = 0; irs < lenrs; irs++)
		if ((char)brs <= argv[1][irs])
			brs = argv[1][irs];
	srand(brs ^ 14);
	prs[3] = lrs[rand() & 63];
	for (brs = 0, irs = 0; irs < lenrs; irs++)
		brs += argv[1][irs] * argv[1][irs];
	prs[4] = lrs[(brs ^ 239) & 63];
	for (brs = 0, irs = 0; (char)irs < argv[1][0]; irs++)
		brs = rand();
	prs[5] = lrs[(brs ^ 229) & 63];
	printf("%s\n", prs);
	return (0);
}
