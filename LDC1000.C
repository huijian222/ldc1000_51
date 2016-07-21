/*
   main中调用初始化程序	LDC1000_int()；
   调用GetInductance 获得U16的返回电感AD值；
	main.c 中 include LDC1000.H
											*/

#include "LDC1000.H"
u8 DATA[6];

u8  spiwrite( u8 address,u8 number){
	u8 i;
	SS=1;	
	SPICLK=0;	
	SS=0;
	for(i=0;i<8;i++){ 	
		SPICLK=0;
		if((address&0x80)==0x80)		OUT=1;			  
		else  OUT=0;	 
		address=(address<<1);
		SPICLK=1;	
	}
	for(i=0;i<8;i++){
		SPICLK=0;	
		if((number&0x80)==0x80)	OUT=1;		  
		else  OUT=0;	 
		number=(number<<1);
		SPICLK=1;
	 }
  SPICLK=0;
  SS=1;
return 0; 
}

///=============================================================
u8  spiread(u8 address){
	u8 i,nb=0;
	SPICLK=0;
	SS=0;
	address=(address|0x80);
	for(i=0;i<8;i++){
		SPICLK=0;
		if((address&0x80)==0x80)	OUT=1;
		else  OUT=0;
		address=(address<<1);
		SPICLK=1;
	}
	for(i=0;i<8;i++){ 	
		SPICLK=0;	
		nb=nb<<1;
		if(IN==1) nb=nb|0X01;
		else nb=nb&0xfe;	
		SPICLK=1;	
	}
	SS=1;
	SPICLK=0;	
	return nb;
}

void LDC1000_int(){
	spiwrite(Rpmax,0x11);
	spiwrite(Rpmin,0x3c);
	spiwrite(Sensor,0x94);
	spiwrite(LDC,0x17);
	spiwrite(CLOCK,0x00);
	spiwrite(Com_Thr_HLSB,  0x50);
	spiwrite(Com_Thr_HMSB,  0x14);
	spiwrite(Com_Thr_LLSB,  0xC0);
	spiwrite(Com_Thr_LMSB,  0x12);
	spiwrite(INTB,0x02);
	spiwrite(POWER,0x01);
}

u16 GetInductance(void){
	u16 inductance;
	DATA[0]=spiread(STATUS);
	DATA[1]=spiread(Pro_DLSB);
	DATA[2]=spiread(Pro_DMSB);
	inductance=DATA[2];
	inductance=(inductance<<8)+DATA[1];
	return inductance;
}

