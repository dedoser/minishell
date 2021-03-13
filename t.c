#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv, char **env)
{
	char *ar[4];

	ar[0] = malloc(15);
	// ar[1] = "ls";
	ar[0] = "/bin/echo";
	// ar[1] = "$PATH asd";
	ar[1] = "";
	ar[2] = NULL;
	execve("bin/echo", ar, env);
	// write(1, "a", 1);
	// write(1, ar[0], 10); 
}
