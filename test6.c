#include<stdio.h>
#include<stdlib.h>

int printHex(unsigned char , int );
int readByteStream(FILE *,unsigned char *,int);
int printByteStream(unsigned char *,int);
int printHexWithDecimalValue(unsigned char ,int );
int printHexWithMacAddress(unsigned char ,int );

#define PCAP_GHDR_LN 24
#define PCAP_RHDR_LN 16
#define PCAP_DMAC_LN 6
#define PCAP_SMAC_LN 6
#define PCAP_PACKETTYPE_LN 2
#define PCAP_HARDWARETYPE_LN 2
#define PCAP_PROTOCOLTYPE_LN 2
#define PCAP_HARDWARE_SIZE_LN 1
#define PCAP_PROTOCOL_SIZE_LN 1
#define PCAP_REQUEST_LN 2
#define PCAP_SENDER_MAC_ADDRESS_LN 6
#define PCAP_SENDER_IP_ADDRESS_LN 4
#define PCAP_TARGET_MAC_ADDRESS_LN 6
#define PCAP_TARGET_IP_ADDRESS_LN 4


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

nextPacket:

	//get pcap record header
	packetNumber+=1;
	if(readByteStream(fp,packetData,PCAP_RHDR_LN)==-1){
		putchar('\n');
		return 0;
	}
	printf("\nPacket NO : %03d\n===========\n",packetNumber);
	printf("\nPcap record header print:\n");
	printByteStream(packetData,PCAP_RHDR_LN);


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

	printf("\nPcap Packet Destination Mac Address\n");
    pkt=packetData;
    for(i=0; i<PCAP_DMAC_LN; i++){
		printHex(*pkt++,i);
	}
	putchar('\n');

	printf("\nPcap Packet Source Mac Address\n");
	//pkt=(unsigned int *)(pkt+0);
    for(i=0; i<PCAP_SMAC_LN; i++){
		printHex(*pkt++,i);
	}
	putchar('\n');


	printf("\nPcap Packet Type\n");
	//pkt=(unsigned int *)(pkt+0);
    for(i=0; i<PCAP_PACKETTYPE_LN; i++){
		printHex(*pkt++,i);
	}
	putchar('\n');

	printf("\nPcap Packet Hardware Type\n");
    for(i=0; i<PCAP_HARDWARETYPE_LN; i++){
		printHex(*pkt++,i);
	}
	putchar('\n');

	printf("\nPcap Packet Protocol Type\n");
    for(i=0; i<PCAP_PROTOCOLTYPE_LN; i++){
		printHex(*pkt++,i);
	}
	putchar('\n');

	printf("\nPcap Packet Hardware size \n");
    for(i=0; i<PCAP_HARDWARE_SIZE_LN; i++){
		printHex(*pkt++,i);
	}
	putchar('\n');

	printf("\nPcap Packet Protocol size\n");
    for(i=0; i<PCAP_PROTOCOL_SIZE_LN; i++){
		printHex(*pkt++,i);
	}
	putchar('\n');

	printf("\nPcap Packet Request\n");
    for(i=0; i<PCAP_REQUEST_LN; i++){
		printHex(*pkt++,i);
	}
	putchar('\n');

	printf("\nPcap Packet Sender Mac Address\n");
    for(i=0; i<PCAP_SENDER_MAC_ADDRESS_LN; i++){
		printHex(*pkt++,i);
	}
	putchar('\n');

	printf("\nPcap Packet Sender IP Address\n");
    for(i=0; i<PCAP_SENDER_IP_ADDRESS_LN; i++){
		printHexWithDecimalValue(*pkt++,i);
	}
	putchar('\n');

	printf("\nPcap Packet Target Address\n");
    for(i=0; i<PCAP_TARGET_MAC_ADDRESS_LN; i++){
		printHex(*pkt++,i);
	}
	putchar('\n');

	printf("\nPcap Packet Target IP Address\n");
    for(i=0; i<PCAP_TARGET_IP_ADDRESS_LN; i++){
		printHexWithDecimalValue(*pkt++,i);
	}
	putchar('\n');


    goto nextPacket;



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

int printHexWithDecimalValue(unsigned char c,int i){
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

	printf("%d.", c);
	return 0;

}

int printHexWithMacAddress(unsigned char c,int i){
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
	printf("%02X :", c);
	return 0;

}



