#include <stdio.h>

void write(char* p, int i)
{
	printf("p is \"%s\" and i is %i\n", p, i);
}

int main()
{
	//feladat 1
	
	printf("Hello world\n");
	
	//feladat 2
	
	char* hello = "Hello";
	char* world = "World";
	
	printf("%s %s\n", hello, world);
	
	//feladat 3
	
	write("foo", 7);
	
	return 0;
}
