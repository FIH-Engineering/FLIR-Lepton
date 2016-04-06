#include<iostream>
#include<stdio.h>
#include<unistd.h>

using namespace std;

int main()
{
	while(1)
	{
		cout << "cout example" << endl;
		printf("printf example \n");
		usleep(1000000);
	}
	
	return 0;
}