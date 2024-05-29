
#include<stdio.h>
#include<pcap.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet/ether.h>
#include <ctype.h>
#include <time.h>
#include<netinet/ip.h>
#include "F1.H"

int main(int argc ,char *argv[]){
    char *dev;
    pcap_t *handle; //session details
    char error[PCAP_BUF_SIZE];
    if(argc == 2){
        dev = argv[2];
    }else{
        dev = pcap_lookupdev(error);
        if(dev==NULL){
            printf("device is not found \n");
            printf("ERROR %s",error);
        }
    }
    handle = pcap_open_live(dev,BUFSIZ,1,1,error);
    if(handle == NULL){
        printf("cannot open the interface [ERROR : %s]",error);
        exit(-1);
    }
    printf("sniffing device %s",dev);
    pcap_loop(handle,0,get_details,NULL);
    pcap_close(handle);//session close
}
