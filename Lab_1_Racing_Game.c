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
 * Countdown timer con un 7SD y 3 leds y una serie de leds que se prenden deacuerdo a cuantas veces el usuario presiona el boton
 * El primero en llegar al ultimo led gana y se muestra el numero del jugador ganador en el 7SD
 * 
 * 
 * Asignacion de Pins:
 * Puerto B = LEDs del Jugador 2
 * Puerto A= LEDs del Jugador 1
 * Puerto C= Pines del 7SD (catodo comun)
 * Puerto D, D3 y D2= Botones de Input de los jugadores
 * Puerto D, D0= Boton de inicio
 * Puerto D, D7 y D1 = Leds que indican si el juego esta prendido o apagado
 * 
 * 
 ****************************************/
//Lineas con los bits de configuracion en donde se utiliza el contador interno, y se apaga todo lo demas
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
#pragma config BOR4V = BOR21V   // Brown-out Reset Selection bit (Brown-out Reset set to 2.1V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#include <xc.h>

/*LEDs del Jugador 1*/
#define LP1_1 PORTAbits.RA6
#define LP1_2 PORTAbits.RA7
#define LP1_3 PORTAbits.RA5
#define LP1_4 PORTAbits.RA4
#define LP1_5 PORTAbits.RA3
#define LP1_6 PORTAbits.RA2
#define LP1_7 PORTAbits.RA1
#define LP1_8 PORTAbits.RA0
/*LEDs del Jugador 2*/
#define LP2_1 PORTBbits.RB0
#define LP2_2 PORTBbits.RB1
#define LP2_3 PORTBbits.RB2
#define LP2_4 PORTBbits.RB3
#define LP2_5 PORTBbits.RB4
#define LP2_6 PORTBbits.RB5
#define LP2_7 PORTBbits.RB6
#define LP2_8 PORTBbits.RB7
/*Botones de Juego*/
#define BP1 PORTDbits.RD3
#define BP2 PORTDbits.RD2
/*Salidas para los LED de countdown*/
#define LCD_1 PORTDbits.RD6
#define LCD_2 PORTDbits.RD5
#define LCD_3 PORTDbits.RD4
/*Entradas del Display de 7 Segmentos (1 = BC),(2=ABGED), (3= ABGCD)*/ 
#define S7B PORTCbits.RC0
#define S7F PORTCbits.RC2
#define S7G PORTCbits.RC3
#define S7E PORTCbits.RC4
#define S7D PORTCbits.RC5
#define S7C PORTCbits.RC6
#define S7A PORTCbits.RC1
#define S7P PORTCbits.RC7
/*Start Button y LEDs de On y Off*/
#define START_B PORTDbits.RD0
#define ON_LED PORTDbits.RD1
#define OFF_LED PORTDbits.RD7


// Se declaran las funciones y variables a ser utilizadas
void Start(void);// Configuracion inicial donde se declaran las entradas y salidas de los puertos y se inicia con todos los LEDs apagados
void delay(int del);// Funcion de delay usando dos contadores
unsigned char caso_p1;// Variable en donde se guarda la posicion del LED en el que se esta para P1
unsigned char caso_p2;// Variable en donde se guarda la posicion del LED en el que se esta para P2
unsigned char BP1_O;// Variable que Guarda el estado previo del boton del Jugador 1
unsigned char BP2_O;// Variable que Guarda el estado previo del boton del Jugador 2
void Countdown(void);

void main(void){
    Start();
    x:
    if(START_B == 1){
        ON_LED = 1;
        OFF_LED =0;
        Countdown();
        
        goto begin;
                    }
    else{
        OFF_LED = 1;
        ON_LED = 0;
        goto x;
    }
    begin:
    while(1){
        delay(1);
        if(BP1==0&&BP1_O==1){
            caso_p1 ++;
            switch (caso_p1){
                case 1: 
                    PORTA = 0;
                    LP1_1=1;
                    LP1_2=0;
                    LP1_3=0;
                    LP1_4=0;
                    LP1_5=0;
                    LP1_6=0;
                    LP1_7=0;
                    LP1_8=0;
                    
                    break;
                case 2: 
                    LP1_1=0;
                    LP1_2=1;
                    LP1_3=0;
                    LP1_4=0;
                    LP1_5=0;
                    LP1_6=0;
                    LP1_7=0;
                    LP1_8=0;
                
                break;
                case 3:
                    LP1_1=0;
                    LP1_2=0;
                    LP1_3=1;
                    LP1_4=0;
                    LP1_5=0;
                    LP1_6=0;
                    LP1_7=0;
                    LP1_8=0;
                
                break;
                case 4:
                    LP1_1=0;
                    LP1_2=0;
                    LP1_3=0;
                    LP1_4=1;
                    LP1_5=0;
                    LP1_6=0;
                    LP1_7=0;
                    LP1_8=0;
                
                break;
                case 5:
                    LP1_1=0;
                    LP1_2=0;
                    LP1_3=0;
                    LP1_4=0;
                    LP1_5=1;
                    LP1_6=0;
                    LP1_7=0;
                    LP1_8=0;
                
                break;
                case 6:
                    LP1_1=0;
                    LP1_2=0;
                    LP1_3=0;
                    LP1_4=0;
                    LP1_5=0;
                    LP1_6=1;
                    LP1_7=0;
                    LP1_8=0;
                
                break;
                case 7:
                    LP1_1=0;
                    LP1_2=0;
                    LP1_3=0;
                    LP1_4=0;
                    LP1_5=0;
                    LP1_6=0;
                    LP1_7=1;
                    LP1_8=0;
                
                break;
                case 8:
                    LP1_1=0;
                    LP1_2=0;
                    LP1_3=0;
                    LP1_4=0;
                    LP1_5=0;
                    LP1_6=0;
                    LP1_7=0;
                    LP1_8=1;
                    
                    S7B = 1;//Writes a 1 on the display
                    S7C = 1;
                    S7A = 0;
                    S7D = 0;
                    S7E = 0;
                    S7G = 0;
                    S7F =0;
                    S7P = 1;
                    while (1){
                        //Stops the race
                    }
                
                break;
                default:PORTA=0;
                break;
                    
                   
                    
                   
                
            }
        }
        else if(BP2==0&& BP2_O==1){
            
            caso_p2 ++;
            switch (caso_p2){
                case 1:
                    PORTB=0;
                    LP2_1=1;
                    LP2_2=0;
                    LP2_3=0;
                    LP2_4=0;
                    LP2_5=0;
                    LP2_6=0;
                    LP2_7=0;
                    LP2_8=0;
                    
                break;
                case 2: 
                    LP2_1=0;
                    LP2_2=1;
                    LP2_3=0;
                    LP2_4=0;
                    LP2_5=0;
                    LP2_6=0;
                    LP2_7=0;
                    LP2_8=0;
                
                break;
                case 3:
                    LP2_1=0;
                    LP2_2=0;
                    LP2_3=1;
                    LP2_4=0;
                    LP2_5=0;
                    LP2_6=0;
                    LP2_7=0;
                    LP2_8=0;
                
                break;
                case 4:
                    LP2_1=0;
                    LP2_2=0;
                    LP2_3=0;
                    LP2_4=1;
                    LP2_5=0;
                    LP2_6=0;
                    LP2_7=0;
                    LP2_8=0;
                
                break;
                case 5:
                    LP2_1=0;
                    LP2_2=0;
                    LP2_3=0;
                    LP2_4=0;
                    LP2_5=1;
                    LP2_6=0;
                    LP2_7=0;
                    LP2_8=0;
                
                break;
                case 6:
                    LP2_1=0;
                    LP2_2=0;
                    LP2_3=0;
                    LP2_4=0;
                    LP2_5=0;
                    LP2_6=1;
                    LP2_7=0;
                    LP2_8=0;
                
                break;
                case 7:
                    LP2_1=0;
                    LP2_2=0;
                    LP2_3=0;
                    LP2_4=0;
                    LP2_5=0;
                    LP2_6=0;
                    LP2_7=1;
                    LP2_8=0;
                
                break;
                case 8:
                    LP2_1=0;
                    LP2_2=0;
                    LP2_3=0;
                    LP2_4=0;
                    LP2_5=0;
                    LP2_6=0;
                    LP2_7=0;
                    LP2_8=1;
                    S7B = 1;//Se dibuja el numero 2 en el D7S
                    S7A = 1;
                    S7G = 1;
                    S7E = 1;
                    S7D = 1;
                    S7C = 0; 
                    S7F= 0;
                    S7P =1;
                    while (1){
                        //Stops the race
                    }
                
                break;
                default:PORTB=0;
                break;
            
        }
            
            
        }
        BP1_O= BP1;
        BP2_O= BP2;
    }
    
                    
}

        
   
void Start(void){
    caso_p1=0;
    caso_p2=0;
            
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
    TRISC3= 0;
    TRISC4= 0;
    TRISC5= 0;
    TRISC6= 0;
    TRISC7= 0;
    /*Puerto D*/
    TRISD7= 0;
    TRISD6= 0;
    TRISD5= 0;
    TRISD4= 0;
    TRISD3= 1;
    TRISD2= 1;
    TRISD1= 0;
    TRISD0= 1;
    
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
    S7F =0;
    S7P =0;
    /*Clear los LEDs de Countdown*/
    LCD_1 =1;
    LCD_2 =1; 
    LCD_3 =1; 
    
    
    
    
    
}
void delay(int del){
    for (int i = 0; i<del;i++){
        for (int j = 0; j< 255; j++){
            /*for (int p = 0; p< 255; p++){
                
            }*/
            
        }
    }
    
}
/*void antirebote(unsigned char rebote){
    
}*/
void Countdown(void){
    /*unsigned char display[] = {0x3F, 0x06, 0x5B, 0x4F};
    for (int i = 3; i > 0; i--)
    {
        delay(200);
        PORTB = display[i];
    }*/

    delay(100);
    ON_LED = 1;
    OFF_LED= 0;
    LCD_3 = 0;
    S7B = 1;//Se dibuja el numero 3 en el D7S
    S7A = 1;
    S7G = 1;
    S7C = 1;
    S7D = 1;
    S7E=  0;
    S7F = 0;
    S7P = 0;
    delay(100);
    LCD_2 = 0;
    S7B = 1;//Se dibuja el numero 2 en el D7S
    S7A = 1;
    S7G = 1;
    S7E = 1;
    S7D = 1;
    S7C = 0; 
    S7F = 0;
    S7P = 0;
    delay(100);
    LCD_1 = 0;//Se dibuja el numero 1 en el D7S
    S7B = 1;
    S7C = 1;
    S7A = 0;
    S7D = 0;
    S7E = 0;
    S7G = 0;
    S7F = 0;
    S7P =0;
    delay(100);
    S7B= 1;//Se dibuja el Numero 0
    S7C = 1;
    S7A = 1;
    S7D = 1;
    S7E = 1;
    S7G = 0;
    S7F = 1;
    S7P=0;
    
            
    
}
