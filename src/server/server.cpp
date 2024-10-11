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

Task parseTaskFromUDP(char data[packet_size_byte + 1]);

void handleUDP(WiFiUDP udp) {
    int packetSize = udp.parsePacket();
    if (packetSize) {
      char incomingPacket[20];
      int len = udp.read(incomingPacket, packet_size_byte + 1);
      if (len > 0) {
        incomingPacket[len] = 0;
        Task req = parseTaskFromUDP(incomingPacket);
        setLED(req.X, req.Y, req.R, req.G, req.B);
      }
    }
}

Task parseTaskFromUDP(char data[packet_size_byte + 1]) {
    Task task;

    task.X = ((short)data[0] << 8) | (short)data[1];
    task.Y = ((short)data[2] << 8) | (short)data[3];
    task.R = (short)data[4]; 
    task.G = (short)data[5]; 
    task.B = (short)data[6]; 
    
    return task;
}