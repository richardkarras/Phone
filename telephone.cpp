//Program to play audio files from a "record player" using RFID tags captured on an Arduino, processed through a BeagleBoneBlack

#include <stdio.h>
#include <string>
#include <sstream>
#include "console.h"
#include "simpio.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

//defining reusable modules
void audio_out(int case_number);

int main()
{
    //Define variables
    string phone_number[4];
    // 4 digit phone number, input from rotary phone
    string code_1[4], code_2[4], code_3[4], code_4[4], code_5[4];
    code_1 = '7513';
    code_2 = '4900';
	code_3 = '8020';
	code_4 = '0918';
    code_5 = '3855';
    
    while (1)
    {
        
        //get rfid input from record player contact
        getline(cin,phone_number);
        
        //switch/case build to evaulate incoming rf tag against desired audio out
        
        if(strcmp(phone_number,code_1)==0)
            audio_out(1);
        
        else if (strcmp(phone_number,code_2)==0)
            audio_out(2);
        
		else if (strcmp(phone_number, code_3) == 0)
			audio_out(3);

		else if (strcmp(phone_number, code_4) == 0)
			audio_out(4);

        else if (strcmp(phone_number, code_5) == 0)
            audio_out(5);
            
        else audio_out(6);
    }
    return 0;
}

void audio_out(int case_number)
{
    switch (case_number)
    {
        case '1':
        {
            system("canberra-gtk-play -f audio1.ogg");
            break;
        }
        case '2':
        {
            system("canberra-gtk-play -f audio2.ogg");
            break;
        }
		case '3':
        {
            system("canberra-gtk-play -f audio3.ogg");
			break;
        }

		case '4':
        {
            system("canberra-gtk-play -f audio4.ogg");
			break;
        }
        case '5':
        {
            system("canberra-gtk-play -f wincond.ogg");
            break
        }
		default: system("canberra-gtk-play -f error.ogg");
            
    }//output audio queues based on incoming call number
    return;
}