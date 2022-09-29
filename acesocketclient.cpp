#include <ace/SOCK_Connector.h>
#include <ace/INET_Addr.h>
#include <ace/SOCK_Stream.h>
#include <ace/Log_Msg.h>

#define SIZE_BUF 108
#define NO_ITERATIONS 5

class Client {
public:
    Client(char *hostname, int port)
        : remote_addr_(port, hostname) {
        data_buff_ = "hello from client.";
    }
    int connect_to_server() {
        if(connector_.connect(client_stream_, remote_addr_) == -1) {
            ACE_ERROR_RETURN((LM_ERROR, "(%P | %t) %p\n", "connection failed"), -1);
        }else {
            ACE_DEBUG((LM_DEBUG, "(%P | %t) connected to %s\n",
                       remote_addr_.get_host_name()));
            return 0;
        }
    }
    int close() {
        if(client_stream_.close() == -1) {
            ACE_ERROR_RETURN((LM_ERROR, "(%P|%t) %p\n", "close"), -1);
        }else {
            return 0;
        }
    }
    int send_to_sever() {
        for(int i = 0; i < NO_ITERATIONS; ++i) {
            if(client_stream_.send_n(data_buff_, ACE_OS::strlen(data_buff_) + 1, 0) == -1) {
                ACE_ERROR_RETURN((LM_ERROR, "(%P|%t) %p\n", "send_n"), 0);
                break;
            }
        }
        close();
    }
private:
    ACE_SOCK_Stream client_stream_;
    ACE_INET_Addr remote_addr_;
    ACE_SOCK_Connector connector_;
    char *data_buff_;
};

int main(int argc, char *argv[]) {
    if(argc < 3) {
        ACE_DEBUG((LM_DEBUG,"Usage %s <hostname> <port_number>\n", argv[0]));
        ACE_OS::exit(1);
    }
    Client client(argv[1], ACE_OS::atoi(argv[2]));
    client.connect_to_server();
    client.send_to_sever();
}