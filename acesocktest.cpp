#include <ace/SOCK_Acceptor.h>
#include <ace/SOCK_Stream.h>
#include <ace/Log_Msg.h>
#define SIZE_BUF 1024
#define SIZE_DATA 18
#define NO_ITERATIONS 5

class Server {
public:
    Server(int port): server_addr_(port), peer_acceptor_(server_addr_) {
        data_buf_ = new char[SIZE_BUF];
    }

    int accept_connections() {
        if(peer_acceptor_.get_local_addr(server_addr_) == 1) {
            ACE_ERROR_RETURN((LM_ERROR, "%p\n", "error in get_local_addr"), 1);
        }
        ACE_DEBUG((LM_DEBUG, "start server at port : %d\n", server_addr_.get_port_number()));
        while (1) {
            // ACE_Time_Value timeout(ACE_DEFAULT_TIMEOUT);
            if(peer_acceptor_.accept(new_stream_, &client_addr_)== -1) {
                ACE_ERROR((LM_ERROR, "%p\n", "accept"));
                continue;
            }else {
                ACE_DEBUG((LM_DEBUG, "connection established with rmote %s:%d\n", client_addr_.get_host_name(), client_addr_.get_port_number()));
                handle_connection();
            }
        }
        
    }

private:
    int handle_connection() {
        for(int i = 0; i < NO_ITERATIONS; ++i) {
            int byte_count = 0;
            if(byte_count = new_stream_.recv_n(data_buf_, SIZE_DATA, 0) == -1) {
                ACE_ERROR((LM_ERROR, "%p\n", "error in recv"));
            }else {
                data_buf_[byte_count] = 0;
                ACE_DEBUG((LM_DEBUG, "byte_count : %d\n", byte_count));
                ACE_DEBUG((LM_DEBUG, "server received %s \n", data_buf_));
            }
        }
        if(new_stream_.close() == -1) {
            ACE_ERROR((LM_ERROR, "%p\n", "close"));
        }
        return 0;
    }

    char *data_buf_;
    ACE_INET_Addr server_addr_;
    ACE_INET_Addr client_addr_;
    ACE_SOCK_Acceptor peer_acceptor_;
    ACE_SOCK_Stream new_stream_;
};


int main(int argc, char *argv[]) {
    if(argc < 2) {
        ACE_ERROR((LM_ERROR, "usage %s <port_num>", argv[0]));
        ACE_OS::exit(1);
    }
    Server server(ACE_OS::atoi(argv[1]));
    server.accept_connections();
}