#include <stdio.h>
#include <stdint.h>

#define MAX_PACKET_DATA_LENGTH (50)


typedef struct data_packet_T {


uint8_t id;
uint8_t data_length;
uint8_t data[MAX_PACKET_DATA_LENGTH];
uint16_t crc;
} data_packet_T;

// CRC  =  Cyclic Redundancy Check

int check_PacketCorrupted(const data_packet_T* packet) {

// Calculating CRC for packet data.


uint16_t calculated_crc = 0;


for (int i = 0; i < packet->data_length; i++) {


calculated_crc += packet->data[i];
}


//comparing the calculated crc with packets of field crc



return calculated_crc != packet->crc;
}

int main() {


data_packet_T packet;

packet.id = 1;

packet.data_length = 10;

for (int i = 0; i < packet.data_length; i++) { 

packet.data[1] = i + 1;

}



packet.crc = 55;


if (check_PacketCorrupted (&packet)) { // Packet is corrupted

printf("Packet is corrupted\n");

} else {

// Packet is not corrupted

printf("Packet is not corrupted\n");

}


return 0;
}