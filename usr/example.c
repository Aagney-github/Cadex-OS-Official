/*
Copyright (C) 2019-2020 OpenCreeck
This software is distributed under the GNU General Public License.
See the file LICENSE for details.
*/

// An example program 

#include <library/syscalls.h>
#include <library/string.h>
#include <library/malloc.h>
#include <library/stdio.h>

int main(int argc, char *argv[])
{
	printf("hello world, I am %d, and I have %d arguments!\n", syscall_process_self(), argc);

	printf("They are: ");

	int i;
	for(i = 0; i < argc; ++i) {
		printf("(%s) ", argv[i]);
	}
	printf("\n");

	int n = 4096;
	printf("adding up %d values...\n", n);

	int *big = malloc(n * sizeof(int));
	if(!big)
		printf("malloc failed!\n");

	for(i = 0; i < n; i++) {
		big[i] = i;
	}
	int sum = 0;
	for(i = 0; i < n; ++i) {
		sum += big[i];
	}
	free(big);

	printf("The sum of 0 to %d is %d\n", n, sum);

	return 0;
}