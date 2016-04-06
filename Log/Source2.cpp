#include<iostream>
#include<stdio.h>
#include<unistd.h>
//#include<python.h>

using namespace std;

int main()
{
	for (int i = 0; i < 5; i++)
	{
		cout << "cout example2" << endl;
		printf("printf example2 \n");
		usleep(1000000)
	}

	return 0;
}