#include <stdio.h>

int main()
{
	int x = 10;

	int *ptr;
	ptr = &x;

	int *ptr2 = &x;

	// Prints value of x
	printf("Value of x = %d\n", x);

	// Prints value that is stored in x
	printf("Value of x stored in ptr = %d\n", *ptr);
	printf("Value of x stored in ptr2 = %d\n", *ptr2);

	// Prints address of x which is assigned to ptr
	printf("Address of x assigned to ptr = %p\n", ptr);
	printf("Address of x assigned to ptr2 = %p\n", ptr2);

	// Prints address of x
	printf("Address of x = %p\n", &x);
	
	*ptr = 20;
	printf("After doing *ptr = 20, *ptr is %d\n", *ptr);
	printf("After doing *ptr = 20, ptr is %p\n", ptr);


	return 0;
}

