#include<stdio.h>
#include<stdlib.h>

int printHex(unsigned char , int );
int readByteStream(FILE *,unsigned char *,int);
int printByteStream(unsigned char *,int);

#define PCAP_GHDR_LN 24
#define PCAP_PHDR_LN 16

int main()
{
	int i,data,pktLength;
	unsigned char c;
	unsigned char *pkt,packetData[2048];
	
	FILE *fp;
	fp=fopen("arp.pcap","rb");
	
	if(fp==NULL){
		printf("\ncan not open file:\n");	
		exit(-1);
	
	}
	else{
		printf("\nreading file:\n");	
	}
	
	
	//get pcap global header
	
	if(readByteStream(fp,packetData,PCAP_GHDR_LN)==-1){
		putchar('\n');
		return 0;	
	}
	
	printf("\nPcap global header print:\n");	
	
	printByteStream(packetData,PCAP_GHDR_LN);
	int packetNumber=0;
NextPacket:
	//get pcap record header
	packetNumber+=1;
	if(readByteStream(fp,packetData,PCAP_PHDR_LN)==-1){
		putchar('\n');
		return 0;	
	}
	printf("\nPacket NO : %03d\n===========\n",packetNumber);
	printf("\nPcap record header print:\n");
	printByteStream(packetData,PCAP_PHDR_LN);
	
	
	// Get Packet Length
	pkt=packetData;
	pktLength= *( (unsigned int *)(pkt+8) );
	//printf("\nPacket length : %d\n",pktLength);
	
	//get Packet
	
	if(readByteStream(fp,packetData,pktLength)==-1){
		putchar('\n');
		return 0;	
	}
	
	printf("\nPcap Packet DATA (%d bytes):\n",pktLength);	
	pkt=packetData;
	
	printByteStream(packetData,pktLength);
	
	
	
	
	
	goto NextPacket;
	
	return 0;	
}

int readByteStream(FILE *fp,unsigned char *dst,int noOfByte){

	int i,data;
	for(i=0; i<noOfByte; i++){
		//data=getchar();
		data=fgetc(fp);
		//if(feof(fp))		
		if(feof(fp)){
			return (-1);
		}
		dst[i]=(unsigned char)(data & 0xFF);
	}
	return 0;

}


int printByteStream(unsigned char *pkt,int noOfByte){
	int i;
	for(i=0; i<noOfByte; i++){
		printHex(*pkt++,i);
	}
	putchar('\n');
	

}



int printHex(unsigned char c,int i){
	if(i==0){
		printf("%06X\t",i);
	}
	else{
		if(i%16==0){
			printf("\n%06X\t",i);
		}
		else if(i%16==8){
			printf(" - ");
		}
		else{
			printf(" ");
		}	
	}
	
	printf("%02X", c);
	return 0;

}



