/**
 * Title: ATTiny Morse Code BAE
 * Date: March 25, 2012
 * Developers: Russel Shomberg & Christopher Woodall 
 * License: MIT License 
 *
 * Generate the morse code message for BAE, which is -... .- .
 * The function morseCode(code, size) takes a string with the following formatting:
 *   * '.' represents a single time unit, aka, a short, dot or dit 
 *   * '-' represents 3 time units, also known as a long, dash or dah (3 dits)
 *   * ',' represents the spacing between two letters
 *   * ' ' represesnts the spacing between words
 */
#include <string.h>

#define SHORT 75
#define LONG  3*SHORT
#define LED 2

void sendMorseCode(char *code, int size, int pin);
void dash(int state, int pin);
void dot(int state, int pin);

void setup() 
{
    pinMode(LED, OUTPUT);
}

void loop() 
{
    char *code = "-...,.-,. ";
    sendMorseCode(code, strlen(code), LED);
}

void dash(int state, int pin) 
{
    if (state) {
        digitalWrite(pin, HIGH);
        delay(LONG);
        digitalWrite(pin, LOW);
    } else {
        digitalWrite(pin, LOW);
        delay(LONG);
    }
}

void dot(int state, int pin) 
{
    if (state) {
        digitalWrite(pin, HIGH);
        delay(SHORT);
        digitalWrite(pin, LOW);
    } else {
        digitalWrite(pin, LOW);
        delay(SHORT);
    }
}

void sendMorseCode(char *code, int size, int pin)
{                                                                               
    int i;                                                                      
    for (i = 0; i <= size; i++)                                                 
    {                                                                           
        if (code[i] == '-') {
            dash(1, pin);
            dot(0, pin);
        } else if (code[i] == '.') {                                           
            dot(1, pin);
            dot(0, pin);         
        } else if (code[i] == ',') {
            dot(0, pin); 
            dot(0, pin);
        } else if(code[i] == ' ') {
            dash(0, pin);
            dash(0, pin);
        }
    }
}
