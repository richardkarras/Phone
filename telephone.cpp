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
    string hint_1[4], hint_2[4];
    hint_1 = '4567';
    hint_2 = '7654';
    
    while (1)
    {
        
        //get rfid input from record player contact
        getline(cin,phone_number);
        
        //switch/case build to evaulate incoming rf tag against desired audio out
        
        if(strcmp(phone_number,hint_1)==0)
            audio_out(1);
        
        else if (strcmp(phone_number,hint_2)==0)
            audio_out(2);
        
        else audio_out(3);
    }
    return 0;
}

void audio_out(int case_number)
{
    switch (case_number)
    {
        case '1':
            system("audio_script_1.sh");
            break;
            
        case '2':
            system("audio_script_2.sh");
            break;
            
        default: system("dial_tone.sh");
            
    }//output audio queues based on incoming call number
    return;
}