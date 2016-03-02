#include "Lepton_I2C.h"

#include "leptonSDKEmb32PUB/LEPTON_SDK.h"
#include "leptonSDKEmb32PUB/LEPTON_SYS.h"
#include "leptonSDKEmb32PUB/LEPTON_Types.h"
#include "leptonSDKEmb32PUB/LEPTON_AGC.h" //ADDED

bool _connected;

LEP_CAMERA_PORT_DESC_T _port;
LEP_SYS_FPA_TEMPERATURE_KELVIN_T fpa_temp_kelvin; //ADDED
LEP_RESULT result; //ADDED

int lepton_connect() {
	LEP_OpenPort(1, LEP_CCI_TWI, 400, &_port);
	_connected = true;
	return 0;
}

void lepton_perform_ffc() {
	if(!_connected) {
		lepton_connect();
	}
	LEP_RunSysFFCNormalization(&_port);
}

//presumably more commands could go here if desired
// BELOW IS ADDED
int lepton_temperature() {
    if(!_connected) {
          lepton_connect();
    }
   result = ((LEP_GetSysFpaTemperatureKelvin(&_port, &fpa_temp_kelvin)));
   
   //originally was: fpa_temp_kelvin// 
   return ( result);
}


