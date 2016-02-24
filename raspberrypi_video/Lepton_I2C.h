#ifndef LEPTON_I2C
#define LEPTON_I2C

void lepton_perform_ffc();
int lepton_temperature(); //ADDED
int internaltemp;


//BELOW IS QUESTIONABLE
internaltemp = lepton_temperature();
cout<<internaltemp;



#endif
