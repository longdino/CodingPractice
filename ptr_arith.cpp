#include <bits/stdc++.h>
using namespace std;

void geeks()
{
	int val[3] = { 5, 10, 15};

	int *ptr;

	ptr = val;
	cout << "Elements of the array are: ";

	cout << ptr[0] << " " << ptr[1] << " " << ptr[2];
	cout << endl;
	return;
}

int main()
{
	int v[3] = {10, 100, 200};

	int *ptr;

	ptr = v;

	for (int i = 0; i < 3; i++)
	{
		printf("Value of *ptr = %d\n", *ptr);
		printf("Value of ptr = %p\n\n", ptr);

		ptr++;
	}

	geeks();
	return 0;
}
