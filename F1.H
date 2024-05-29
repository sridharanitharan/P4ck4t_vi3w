#ifndef F1_H
#define F1_H
#include "F2.H"
void get_details(u_char *argv, const struct pcap_pkthdr *header , const u_char *packets){
    char err[PCAP_ERRBUF_SIZE];
    struct ether_header *eth_header;
    struct ip *ip_header;
    char source[INET_ADDRSTRLEN];
    char destination[INET_ADDRSTRLEN];

    // get ether header 
    eth_header = (struct ether_header*)packets;
    // check if its ip header 
    if(ntohs(eth_header->ether_type)== ETHERTYPE_IP){
    //get ip header 
        ip_header = (struct ip*)(packets + sizeof(struct ether_header));

        // inet_ntop - convert IPv4 and IPv6 addresses from binary to text form
        inet_ntop(AF_INET,&(ip_header->ip_src),source,INET_ADDRSTRLEN);
        inet_ntop(AF_INET,&(ip_header->ip_dst),destination,INET_ADDRSTRLEN);
        printf("packet's length %d\n",header->len);
        printf("packet's no.of byte's  %d\n",header->caplen);
        printf("Recived at %s\n",ctime((const time_t*)&header->ts.tv_sec));
        printf("Source MAC address [%s]\n",ether_ntoa(( struct ether_addr*)eth_header->ether_shost));
        printf("Sourcr IP address %s\n",source);
        printf("destination MAC address[%s]\n",ether_ntoa(( struct ether_addr*)eth_header->ether_dhost));
        printf("Destination IP address %s\n",destination);
        print_data(packets,header->caplen);
    }else{
        printf("cannot open the devices try or check the interface connection \n");
        printf("ERROR %s\n",err);
    }
}
#endif 
