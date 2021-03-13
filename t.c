#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv, char **env)
{
	char *ar[3];

	ar[0] = malloc(15);
	ar[1] = malloc(8);
	ar[0] = "/bin/env";
	// ar[1] = "$PATH asd";
	ar[1] = NULL;
	execve("/bin/env", ar, env);
	// write(1, "a", 1);
	write(1, ar[0], 10); 
}
