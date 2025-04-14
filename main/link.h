#ifndef LINK_H
#define LINK_H
class Link{
    public:
        char read();
        void send(char* cmd);
        void send(float val);
        void send(int val);
        void sendAck();
        void sendNack();
};
#endif