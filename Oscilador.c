/*
 * File:   Oscilador.c
 * Author: Ricochetrj
 *
 * Created on January 27, 2020, 4:20 PM
 */


#include <xc.h>
#include <stdint.h>
void initOsc(int frec){
    switch(frec){
        case 0: // 31KHz 
            OSCCONbits.IRCF0 = 0;
            OSCCONbits.IRCF1 = 0;
            OSCCONbits.IRCF2 = 0;
            OSCCONbits.OSTS = 0;
            OSCCONbits.LTS = 0;
            OSCCONbits.SCS = 1;
            break;
            
        case 1: // 31KHz 
            OSCCONbits.IRCF0 = 1;
            OSCCONbits.IRCF1 = 0;
            OSCCONbits.IRCF2 = 0;
            OSCCONbits.OSTS = 0;
            OSCCONbits.LTS = 0;
            OSCCONbits.SCS = 1;
            break;
        case 2: // 31KHz 
            OSCCONbits.IRCF0 = 0;
            OSCCONbits.IRCF1 = 1;
            OSCCONbits.IRCF2 = 0;
            OSCCONbits.OSTS = 0;
            OSCCONbits.LTS = 0;
            OSCCONbits.SCS = 1;
            break;
        case 3: // 31KHz 
            OSCCONbits.IRCF0 = 0;
            OSCCONbits.IRCF1 = 0;
            OSCCONbits.IRCF2 = 0;
            OSCCONbits.OSTS = 0;
            OSCCONbits.LTS = 0;
            OSCCONbits.SCS = 1;
            break;
        case 4: // 31KHz 
            OSCCONbits.IRCF0 = 0;
            OSCCONbits.IRCF1 = 0;
            OSCCONbits.IRCF2 = 0;
            OSCCONbits.OSTS = 0;
            OSCCONbits.LTS = 0;
            OSCCONbits.SCS = 1;
            break;
        case 5: // 31KHz 
            OSCCONbits.IRCF0 = 0;
            OSCCONbits.IRCF1 = 0;
            OSCCONbits.IRCF2 = 0;
            OSCCONbits.OSTS = 0;
            OSCCONbits.LTS = 0;
            OSCCONbits.SCS = 1;
            break;
        case 6: // 31KHz 
            OSCCONbits.IRCF0 = 0;
            OSCCONbits.IRCF1 = 0;
            OSCCONbits.IRCF2 = 0;
            OSCCONbits.OSTS = 0;
            OSCCONbits.LTS = 0;
            OSCCONbits.SCS = 1;
            break;
        case 7: // 31KHz 
            OSCCONbits.IRCF0 = 0;
            OSCCONbits.IRCF1 = 0;
            OSCCONbits.IRCF2 = 0;
            OSCCONbits.OSTS = 0;
            OSCCONbits.LTS = 0;
            OSCCONbits.SCS = 1;
            break;
        case 8: // 8MHz 
            OSCCONbits.IRCF0 = 1;
            OSCCONbits.IRCF1 = 1;
            OSCCONbits.IRCF2 = 1;
            OSCCONbits.OSTS = 0;
            OSCCONbits.LTS = 0;
            OSCCONbits.SCS = 1;
            break;
        default: //4 MHz
            OSCCONbits.IRCF0 = 0;
            OSCCONbits.IRCF1 = 1;
            OSCCONbits.IRCF2 = 1;
            break;
       
          
        
    }
}
