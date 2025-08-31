#include <stdint.h>

uint32_t test_complete = 0 ;

typedef struct {
    uint8_t status ;
    uint8_t ptr ;
    uint16_t data ;
} node ;

#define NODE_STATUS_FREE 0
#define NODE_STATUS_USED 1

node all_available_nodes [0x80] ;

uint8_t get_free_node () {
    for (int i = 0; i < 0x40; i++) {
        if (all_available_nodes[i].status == NODE_STATUS_FREE) {
            all_available_nodes[i].status = NODE_STATUS_USED ;
            return i ;
        }
    }
    return 0xff ;
}

void add_ll_node (uint8_t head_ptr, uint16_t data) {
    int reached_end = 0 ;
    uint8_t curr_ptr = head_ptr ; 
    uint8_t new_node_ptr = get_free_node () ;
    while (reached_end == 0) {
        if (curr_ptr != 0) {
            curr_ptr = all_available_nodes[curr_ptr].ptr ;
        } else {
            all_available_nodes[curr_ptr].ptr = new_node_ptr ;
            all_available_nodes[new_node_ptr].data = data ;
        }
    }
}

uint16_t base_data [16] = {0x1234, 0x5678, 0x9ABC, 0xDEF0, 0x2468, 0x1357, 0x9BDF, 0xACEF, 0x3579, 0x2468, 0x8ACE, 0x1357, 0x9BDF, 0x2468, 0x1357, 0x9BDF} ;
uint8_t init_ll_head_ptr [2] = {0x45, 0x7A} ;
uint8_t random_sequence [0x10] = {1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1} ;

int main (void) {

    for (int i = 0; i < 0x10; i++) {
        add_ll_node (init_ll_head_ptr[random_sequence[i]], base_data[i]) ;
    }

    test_complete = 0xdeadbeef ;
    
}
