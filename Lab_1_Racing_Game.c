/****************************************
 * File:    Lab_1_Racing_Game.c               *
 * Date:    21/01/2020                   *
 * Author:  Rodrigo Figueroa             *
 * Prof:     Pablo Mazariegos            *
 * Seccion:     20                       *
 * Clase:   Digital 2                    *
 * Compiler:    MPLAB XC8 v2.10          *
 * Arquitectura:    PIC16F887            *
 * Descripcion: Primer Lab Donde se hace un juego de carreras que incluye un
 * Countdown timer y una serie de leds que se prenden deacuerdo a cuantas veces el usuario presiona el boton
 * El primero en llegar al ultimo led gana
 * 
 * 
 * Asignacion de Pins:
 * 
 ****************************************/

// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR21V   // Brown-out Reset Selection bit (Brown-out Reset set to 2.1V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
//#define _XTAL_FREQ 4000000
/*LEDs del Jugador 1*/
#define LP1_1 RA6
#define LP1_2 RA7
#define LP1_3 RA5
#define LP1_4 RA4
#define LP1_5 RA3
#define LP1_6 RA2
#define LP1_7 RA1
#define LP1_8 RA0
/*LEDs del Jugador 2*/
#define LP2_1 RB0
#define LP2_2 RB1
#define LP2_3 RB2
#define LP2_4 RB3
#define LP2_5 RB4
#define LP2_6 RB5
#define LP2_7 RB6
#define LP2_8 RB7
/*Botones de Juego*/
#define BP1 RC3
#define BP2 RC5
/*Salidas para los LED de countdown*/
#define LCD_1 RC0
#define LCD_2 RC1
#define LCD_3 RC2
/*Entradas del Display de 7 Segmentos (1 = BC),(2=ABGED), (3= ABGCD)*/ 
#define S7G RD7
#define S7A RD6
#define S7B RD5
#define S7E RD4
#define S7D RC7
#define S7C RC6
/*Start Button*/
#define START_B RC4
#define ON_LED RD3
#define OFF_LED RD2



void Start(void);
void delay(unsigned char del);
//void antirebote(unsigned char rebote);
//void Countdown(void);

void main(void){
    Start();
    x:
    if(START_B == 1){
        //Countdown();
        ON_LED = 1;
            OFF_LED= 0;
            LCD_3 = 0;
            S7B = 1;//Se dibuja el numero 3 en el D7S
            S7A = 1;
            S7G = 1;
            S7C = 1;
            S7D = 1;
            delay(20);
            LCD_2 = 0;
            S7B = 1;//Se dibuja el numero 2 en el D7S
            S7A = 1;
            S7G = 1;
            S7E = 1;
            S7D = 1;
            delay(20);
            LCD_1 = 0;//Se dibuja el numero 1 en el D7S
            S7B = 1;
            S7C = 1;
            /*Clear los LEDs del Jugador 1*/
            LP1_1 =0;
            LP1_2 =0;
            LP1_3 =0;
            LP1_4 =0;
            LP1_5 =0;
            LP1_6 =0;
            LP1_7 =0;
            LP1_8 =0;
            /*Clear los LEDs del Jugador 2*/
            LP2_1 =0;
            LP2_2 =0;
            LP2_3 =0;
            LP2_4 =0;
            LP2_5 =0;
            LP2_6 =0;
            LP2_7 =0;
            LP2_8 =0;
        goto begin;
                    }
    else{
        goto x;
    }
    begin:
    while(1){
        ON_LED=1;
        /*player 1*/
            if(BP1 == 1&& LP1_1== 0 && LP1_2== 0&& LP1_3==0&&LP1_4==0&&LP1_5==0&&LP1_6==0&&LP1_7==0&&LP1_8==0){
                LP1_1=1;
                LP1_2=0;
                LP1_3=0;
                LP1_4=0;
                LP1_5=0;
                LP1_6=0;
                LP1_7=0;
                LP1_8=0;
            }
            else if(BP1 == 1&&LP1_1==1&&LP1_2==0&&LP1_3==0&&LP1_4==0&&LP1_5==0&&LP1_6==0&&LP1_7==0&&LP1_8==0){
                LP1_1=0;
                LP1_2=1;
                LP1_3=0;
                LP1_4=0;
                LP1_5=0;
                LP1_6=0;
                LP1_7=0;
                LP1_8=0;
            }
            else if(BP1 == 1&&LP1_1==0&&LP1_2==1&&LP1_3==0&&LP1_4==0&&LP1_5==0&&LP1_6==0&&LP1_7==0&&LP1_8==0){
                LP1_1=0;
                LP1_2=0;
                LP1_3=1;
                LP1_4=0;
                LP1_5=0;
                LP1_6=0;
                LP1_7=0;
                LP1_8=0;
            }
            else if(BP1 == 1&&LP1_1==0&&LP1_2==0&&LP1_3==1&&LP1_4==0&&LP1_5==0&&LP1_6==0&&LP1_7==0&&LP1_8==0){
                LP1_1=0;
                LP1_2=0;
                LP1_3=0;
                LP1_4=1;
                LP1_5=0;
                LP1_6=0;
                LP1_7=0;
                LP1_8=0;
            }
            else if(BP1 == 1&&LP1_1==0&&LP1_2==0&&LP1_3==0&&LP1_4==1&&LP1_5==0&&LP1_6==0&&LP1_7==0&&LP1_8==0){
                LP1_1=0;
                LP1_2=0;
                LP1_3=0;
                LP1_4=0;
                LP1_5=1;
                LP1_6=0;
                LP1_7=0;
                LP1_8=0;
            }
            else if(BP1 == 1&&LP1_1==0&&LP1_2==0&&LP1_3==0&&LP1_4==0&&LP1_5==1&&LP1_6==0&&LP1_7==0&&LP1_8==0){
                LP1_1=0;
                LP1_2=0;
                LP1_3=0;
                LP1_4=0;
                LP1_5=0;
                LP1_6=1;
                LP1_7=0;
                LP1_8=0;
            }
            else if(BP1 == 1&&LP1_1==0&&LP1_2==0&&LP1_3==0&&LP1_4==0&&LP1_5==0&&LP1_6==1&&LP1_7==0&&LP1_8==0){
                LP1_1=0;
                LP1_2=0;
                LP1_3=0;
                LP1_4=0;
                LP1_5=0;
                LP1_6=0;
                LP1_7=1;
                LP1_8=0;
            }
            else if(BP1 == 1&&LP1_1==0&&LP1_2==0&&LP1_3==0&&LP1_4==0&&LP1_5==0&&LP1_6==0&&LP1_7==1&&LP1_8==0){
                LP1_1=0;
                LP1_2=0;
                LP1_3=0;
                LP1_4=0;
                LP1_5=0;
                LP1_6=0;
                LP1_7=0;
                LP1_8=1;
                
            }
            else if(BP1 == 1&&LP1_1==0&&LP1_2==0&&LP1_3==0&&LP1_4==0&&LP1_5==0&&LP1_6==0&&LP1_7==0&&LP1_8==1){
                LP1_8=0;
                S7B= 1;
                S7C= 1;
                goto end;
                
            }
            /*Player 2*/
            else if(BP2 == 1&& LP2_1== 0 && LP2_2== 0&& LP2_3==0&&LP2_4==0&&LP2_5==0&&LP2_6==0&&LP2_7==0&&LP2_8==0){
                LP2_1=1;
                LP2_2=0;
                LP2_3=0;
                LP2_4=0;
                LP2_5=0;
                LP2_6=0;
                LP2_7=0;
                LP2_8=0;
            }
            else if(BP2 == 1&&LP2_1==1&&LP2_2==0&&LP2_3==0&&LP2_4==0&&LP2_5==0&&LP2_6==0&&LP2_7==0&&LP2_8==0){
                LP2_1=0;
                LP2_2=1;
                LP2_3=0;
                LP2_4=0;
                LP2_5=0;
                LP2_6=0;
                LP2_7=0;
                LP2_8=0;
            }
            else if(BP2 == 1&&LP2_1==0&&LP2_2==1&&LP2_3==0&&LP2_4==0&&LP2_5==0&&LP2_6==0&&LP2_7==0&&LP2_8==0){
                LP2_1=0;
                LP2_2=0;
                LP2_3=1;
                LP2_4=0;
                LP2_5=0;
                LP2_6=0;
                LP2_7=0;
                LP2_8=0;
            }
            else if(BP2 == 1&&LP2_1==0&&LP2_2==0&&LP2_3==1&&LP2_4==0&&LP2_5==0&&LP2_6==0&&LP2_7==0&&LP2_8==0){
                LP2_1=0;
                LP2_2=0;
                LP2_3=0;
                LP2_4=1;
                LP2_5=0;
                LP2_6=0;
                LP2_7=0;
                LP2_8=0;
            }
            else if(BP2 == 1&&LP2_1==0&&LP2_2==0&&LP2_3==0&&LP2_4==1&&LP2_5==0&&LP2_6==0&&LP2_7==0&&LP2_8==0){
                LP2_1=0;
                LP2_2=0;
                LP2_3=0;
                LP2_4=0;
                LP2_5=1;
                LP2_6=0;
                LP2_7=0;
                LP2_8=0;
            }
            else if(BP2 == 1&&LP2_1==0&&LP2_2==0&&LP2_3==0&&LP2_4==0&&LP2_5==1&&LP2_6==0&&LP2_7==0&&LP2_8==0){
                LP2_1=0;
                LP2_2=0;
                LP2_3=0;
                LP2_4=0;
                LP2_5=0;
                LP2_6=1;
                LP2_7=0;
                LP2_8=0;
            }
            else if(BP2 == 1&&LP2_1==0&&LP2_2==0&&LP2_3==0&&LP2_4==0&&LP2_5==0&&LP2_6==1&&LP2_7==0&&LP2_8==0){
                LP2_1=0;
                LP2_2=0;
                LP2_3=0;
                LP2_4=0;
                LP2_5=0;
                LP2_6=0;
                LP2_7=1;
                LP2_8=0;
            }
            else if(BP2 == 1&&LP2_1==0&&LP2_2==0&&LP2_3==0&&LP2_4==0&&LP2_5==0&&LP2_6==0&&LP2_7==1&&LP2_8==0){
                LP2_1=0;
                LP2_2=0;
                LP2_3=0;
                LP2_4=0;
                LP2_5=0;
                LP2_6=0;
                LP2_7=0;
                LP2_8=1;
                
            }
            else if(BP2 == 1&&LP2_1==0&&LP2_2==0&&LP2_3==0&&LP2_4==0&&LP2_5==0&&LP2_6==0&&LP2_7==0&&LP2_8==1){
                LP2_8=0;
                S7B = 1;//Se dibuja el numero 2 en el D7S
                S7A = 1;
                S7G = 1;
                S7E = 1;
                S7D = 1;
                goto end;
                
            }
            end:
            while(1){
                
            }
            
            
            
        
    }
}
void Start(void){
    /*Puerto B*/
    TRISB0=0;
    TRISB1=0;
    TRISB2=0;
    TRISB3=0;
    TRISB4=0;
    TRISB5=0;
    TRISB6=0;
    TRISB7=0;
    /*Puerto A*/
    TRISA0= 0;
    TRISA1= 0;
    TRISA2= 0;
    TRISA3= 0;
    TRISA4= 0;
    TRISA5= 0;
    TRISA6= 0;
    TRISA7= 0;
    /*Puerto C*/
    TRISC0= 0;
    TRISC1= 0;
    TRISC2= 0;
    TRISC3= 1;
    TRISC4= 1;
    TRISC5= 1;
    TRISC6= 0;
    TRISC7= 0;
    /*Puerto D*/
    TRISD7= 0;
    TRISD6= 0;
    TRISD5= 0;
    TRISD4= 0;
    
    ANSEL = 0;
    ANSELH = 0;
    OFF_LED = 1;
    ON_LED = 0;
    /*Clear los LEDs del Jugador 1*/
    LP1_1 =0;
    LP1_2 =0;
    LP1_3 =0;
    LP1_4 =0;
    LP1_5 =0;
    LP1_6 =0;
    LP1_7 =0;
    LP1_8 =0;
    /*Clear los LEDs del Jugador 2*/
    LP2_1 =0;
    LP2_2 =0;
    LP2_3 =0;
    LP2_4 =0;
    LP2_5 =0;
    LP2_6 =0;
    LP2_7 =0;
    LP2_8 =0;
    /*Clear El Display*/
    S7A =0;
    S7B =0;
    S7C =0;
    S7D =0;
    S7E =0;
    S7G =0;
    /*Clear los LEDs de Countdown*/
    LCD_1 =0;
    LCD_2 =0; 
    LCD_3 =0; 
    
    
    
    
    
}
void delay(unsigned char del){
    for (int i = 0; i<del;i++){
        for (int j = 0; j< 255; j++){
            /*for (int p = 0; p< 255; p++){
                
            }*/
            
        }
    }
    
}
/*void antirebote(unsigned char rebote){
    
}*/
/*void Countdown(void){
            ON_LED = 1;
            OFF_LED= 0;
            LCD_3 = 0;
            S7B = 1;//Se dibuja el numero 3 en el D7S
            S7A = 1;
            S7G = 1;
            S7C = 1;
            S7D = 1;
            delay(20);
            LCD_2 = 0;
            S7B = 1;//Se dibuja el numero 2 en el D7S
            S7A = 1;
            S7G = 1;
            S7E = 1;
            S7D = 1;
            delay(20);
            LCD_1 = 0;//Se dibuja el numero 1 en el D7S
            S7B = 1;
            S7C = 1;
            Clear los LEDs del Jugador 1
            LP1_1 =0;
            LP1_2 =0;
            LP1_3 =0;
            LP1_4 =0;
            LP1_5 =0;
            LP1_6 =0;
            LP1_7 =0;
            LP1_8 =0;
            Clear los LEDs del Jugador 2
            LP2_1 =0;
            LP2_2 =0;
            LP2_3 =0;
            LP2_4 =0;
            LP2_5 =0;
            LP2_6 =0;
            LP2_7 =0;
            LP2_8 =0;
            
    
}*/
