#include <WiFiUdp.h>
#include <led/led.h>

const short packet_size_byte = 7;

class Task {
  public:
    short X;
    short Y;
    short R;
    short G;
    short B;
};

Task parseTaskFromUDP(char data[packet_size_byte]);

void handleUDP(WiFiUDP udp) {
    int packetSize = udp.parsePacket();
    if (packetSize) {
      char incomingPacket[20];
      int len = udp.read(incomingPacket, packet_size_byte + 1);
      if (len == packet_size_byte) {
        Task req = parseTaskFromUDP(incomingPacket);
        setLED(req.X, req.Y, req.R, req.G, req.B);
      }
    }
}

Task parseTaskFromUDP(char data[packet_size_byte + 1]) {
    Task task;

    task.X = ((uint8_t)data[0] << 8) | (uint8_t)data[1];
    task.Y = ((uint8_t)data[2] << 8) | (uint8_t)data[3];  
    task.R = (uint8_t)data[4];
    task.G = (uint8_t)data[5];
    task.B = (uint8_t)data[6];
    
    return task;
}