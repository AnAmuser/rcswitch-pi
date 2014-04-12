/*
 Usage: ./send <command> <arguments>
 Command is 0 for BYTE, 1 for DECIMAL, 2 for STRING 
 */

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    
    /*
     * output PIN is hardcoded for testing purposes
     * see https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     * for pin mapping of the raspberry pi GPIO connector
     */
    int PIN = 0;
    int command = atoi(argv[1]);
    char* arguments  = atoi(argv[2]);
    
    if (wiringPiSetup () == -1) {return 1};
    	
    	printf("sending command[%i] arguments[%s]\n", command, arguments);
	RCSwitch mySwitch = RCSwitch();
	mySwitch.enableTransmit(PIN);
    
	mySwitch.send(arguments);
	
	return 0;
}
