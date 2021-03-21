// FIND THE VERSION OF GLIBC
#include <gnu/libc-version.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	/* function definition
	const char *gnu_get_libc_version(void);
	const char *gnu_get_libc_release(void);
	*/

	/* the version can also be determined by - confstr() */

	/*
	returns a string that identifies the glibc version available on the system,
	this function first introduced on glibc version 2.1,
	*/
	printf("GNU libc version: %s\n", gnu_get_libc_version());
	/*
	return a string that identifies the glibs version status,
	the value is retured as string
	*/
 	printf("GNU libc release: %s\n", gnu_get_libc_release());
	exit(EXIT_SUCCESS);
}

// OUTPUT
// GNU libc version: 2.27
// GNU libc release: stable

