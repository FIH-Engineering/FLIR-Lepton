#include<iostream>
#include<stdio.h>
#include<unistd.h>

using namespace std;

int main()
{
	for (int i = 0; i < 5; i++)
	{
		cout << "cout example" << endl;
		printf("printf example \n");
		usleep(1000000);
	}
	
	return 0;
}