#include <ace/Malloc.h>
#include <ace/Malloc_T.h>

typedef char MEMORY_BLOCK[1024];
typedef ACE_Cached_Allocator<MEMORY_BLOCK, ACE_SYNCH_MUTEX> Allocator;

class Message_Manager {
public:
    Message_Manager(int n_blocks)
    : allocator_(n_blocks)
    , message_count_(0) {
        mesg_array_ = new char *[n_blocks];
    }
    void allocate_msg(const char *msg) {
        mesg_array_[message_count_] = (char *)allocator_.malloc(ACE_OS::strlen(msg) + 1);
        ACE_OS::strcpy(mesg_array_[message_count_], msg);
    }
    void free_all_msg() {

    }
    void display_all_msg() {

    }
private:
    char **mesg_array_;
    Allocator allocator_;
    int message_count_;
};