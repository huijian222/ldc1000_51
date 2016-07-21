
#ifndef __LDC1000_H__
#define __LDC1000_H__

#include "intrins.h"
#include "main.h"
void TIME_init();
extern u8 DATA[6];

#define Device            0x00
#define Rpmax             0x01	
#define Rpmin             0x02	  
#define Sensor            0x03
#define LDC               0x04
#define CLOCK             0x05
#define Com_Thr_HLSB      0x06  
#define Com_Thr_HMSB      0x07	  
#define Com_Thr_LLSB      0x08
#define Com_Thr_LMSB      0x09
#define INTB              0x0A  
#define POWER             0x0B
#define STATUS            0x20
#define Pro_DLSB          0x21
#define Pro_DMSB          0x22  
#define Fre_CD_LSB        0x23  
#define Fre_CD_Mid        0x24
#define Fre_CD_MSB        0x25
u8  spiread(u8 address);  
u8  spiwrite( u8 address,u8 number) ;
sbit SPICLK=P1^3;  //??
sbit OUT=P1^4;     //????
sbit IN=P1^5;
sbit SS=P1^6;      //??
sbit INT=P1^7;
#endif	   