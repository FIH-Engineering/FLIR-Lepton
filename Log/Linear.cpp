//Course: EECE458/ECEG758
//Semester: Spring 2016
//Alex Gitlitz

//Linear Sorting
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <map>
#include<cassert>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <iostream>
#include <sys/socket.h> 
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fstream>
#include <sstream>

#define SIZE         1024

//Protypes for functions
string sconvert(const char *bufferchar, int arraySize);

//global variable to run the linear search
const char COMPARE = '*';

class service
{
public:
	int serviceID;
	string serviceName;
	string serviceType;
	string serviceContextInfo;

	//Function prototypes for service objects
	void sendQueryInfo();

	int GetServiceID()
	{
		return(serviceID);
	}

	void SetServiceID(int serviceID_in)
	{
		serviceID = serviceID_in;
	}

	string GetServiceName()
	{
		return(serviceName);
	}

	void SetServiceName(string serviceName_in)
	{
		serviceName = serviceName_in;
	}

	string GetServiceType()
	{
		return(serviceType);
	}

	void SetServiceType(string serviceType_in)
	{
		serviceType = serviceType_in;
	}

	string GetServiceContext()
	{
		return(serviceContextInfo);
	}

	void SetServiceContext(string serviceContext_in)
	{
		serviceContextInfo = serviceContext_in;
	}

	int GetServiceLifeSpan()
	{
		return(serviceLife_Span);
	}

	void SetServiceLifeSpan(int serviceLifeSpan_in)
	{
		serviceLife_Span = serviceLifeSpan_in;
	}

	//Prototypes of Client Objects


	int GetService_Status()
	{
		return(Service_Status);
	}

	void SetService_Status(int Service_Status_in)
	{
		Service_Status = Service_Status_in;
	}


protected:
	string IPAddress;
	unsigned int port;
	time_t date;
	int Service_Status;
	int serviceLife_Span;

};


//Function stores object information given to the server via service registration
//Argument is an object
void setService(service device)
{
	int number;
	string ID_LOG = "ID:"; //header to find the file
						   //open output file
	ofstream deviceFile("Devices.txt", fstream::app);
	if (deviceFile.is_open())
	{
		deviceFile << ID_LOG; //Seperation Header 
							  //Store Values of object in a file to read from later
		
		//close output file
		deviceFile.close();
	}

	//Clear ID File 
	ofstream file;
	file.open("ID.txt", ofstream::out | ofstream::trunc);   //deletes everything in the file
	file.close();

	//Update ID file to next ID
	ofstream deviceFile1("ID.txt");
	if (deviceFile1.is_open())
	{
		number = device.GetServiceID() + 1;   //rights next server ID number
		deviceFile1 << number << endl;
	}
	deviceFile1.close();  //close file to avoid issues
	return;
}

service getService(int index)
{
	//temp variable declarations
	service dev1;      //service object
	string input, compare;  //local compare
	
	//set Service's ID to Index
	dev1.SetServiceID(index);
	//convert index to the compare start of file
	ostringstream conv;
	conv << index;
	compare = "ID:" + conv.str();  //local compare

	ifstream deviceFile("Devices.txt");
	//find beginning of Service Info
	while (input != compare)  //local compare
	{
		getline(deviceFile, input);
	}


}

int getNEXTSERVICEID()
{
	//open input file
	ifstream deviceFile("ID.txt");
	int index;
	string input;
	//get the Next Service ID =
	if (deviceFile.is_open())
	{
		getline(deviceFile, input);
		stringstream InputStream(input);
		InputStream >> index;
	}
	//close file and return ID of last service
	deviceFile.close();
	return index;   //number of the last registered service
}


//char buffer to string to int
tempstring = sconvert(tempbuffer, j); //string conversion
int tempint = atoi(tempstring.c_str());

string tempstring = sconvert(tempbuffer, j);

//Query all services
if (tempstring == "Services")
{
	k = 0;


	//output data with an header to ensure no data loss in socket communication
	while (k<index)
	{
		//ensure buffer is clean
		for (int j = 0; j < sizeof(buf); j++) {
			buf[j] = '\0';
		}
		sprintf(tempport, "%d", tempPort[k]);
		tempport1 = sconvert(tempport, 4);
		tempport1 = tempport1 + "*";
		//temp string with all needed variables in Table 1
		temp = header + tempName[k] + tempServiceType[k] + tempIPaddress[k] + tempport1 + tempContext[k];
		strcpy(buf, temp.c_str());
		//show what was sent
		cout << "I just sent: " << temp << endl;
		//wait to ensure a clear send
		usleep(5500);
		//clear buffer to ensure clean data transmission
		for (int j = 0; j < sizeof(buf); j++) {
			buf[j] = '\0';
		}
		k++;


		//safe string conversion from buffer function to avoid data loss
		string sconvert(const char *charbuffer, int arraySize) {
			string str1;
			if (charbuffer[arraySize - 1] == '\0') str1.append(charbuffer);
			else for (int i = 0; i<arraySize; i++) str1.append(1, charbuffer[i]);
			return str1;
		}