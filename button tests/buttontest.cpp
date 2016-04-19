#include "GPIOClass.h"
#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//button test

int main()
{
	string inputstate;
	GPIOClass* gpio17 = new GPIOClass("17"); 
	gpio17->export_gpio();
	gpio17->setdir_gpio("in");
	
	 while(1)
    {
        usleep(500000);  // wait for 0.5 seconds
        gpio17->getval_gpio(inputstate); //read state of GPIO17 input pin
        cout << "Current input pin state is " << inputstate  <<endl;
        if(inputstate == "1") // if input pin is at state "0" i.e. button pressed
        {
            cout << "input pin state is Pressed.n Will check input pin state again in 20ms "<<endl;
                usleep(20000);
                    cout << "Checking again ....." << endl;
                    gpio17->getval_gpio(inputstate); // checking again to ensure that state "0" is due to button press and not noise
            if(inputstate == "0")
            {

                cout << " Waiting until pin is unpressed....." << endl;
                while (inputstate == "0"){
                gpio17->getval_gpio(inputstate);
                };
                cout << "pin is unpressed" << endl;

            }
            else
                cout << "input pin state is definitely UnPressed. That was just noise." <<endl;

        }
    }
}