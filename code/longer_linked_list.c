#include <stdint.h>

uint32_t test_complete = 0 ;

typedef struct {
    uint8_t status ;
    uint8_t ptr ;
    uint16_t data ;
} node ;

#define NODE_STATUS_FREE 0
#define NODE_STATUS_USED 1
#define NODE_STATUS_RESERVED 2

#define N_NODES 0xf0

node all_available_nodes [N_NODES] ;

void reserve_nodes_for_debug () {

    all_available_nodes[0x00].status = NODE_STATUS_RESERVED ;
    all_available_nodes[0x00].data = 0xffff ;
    all_available_nodes[0x00].ptr = 0x00 ;

    all_available_nodes[N_NODES-1].status = NODE_STATUS_RESERVED ;
    all_available_nodes[N_NODES-1].data = 0xffff ;
    all_available_nodes[N_NODES-1].ptr = 0x00 ;
    
}

uint8_t get_free_node () {
    for (int i = 0; i < N_NODES; i++) {
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
        if (all_available_nodes[curr_ptr].ptr != 0x00) {
            curr_ptr = all_available_nodes[curr_ptr].ptr ;
        } else {
            reached_end = 1 ;
            all_available_nodes[curr_ptr].ptr = new_node_ptr ;
            all_available_nodes[new_node_ptr].data = data ;
            all_available_nodes[new_node_ptr].ptr = 0x00 ;
            all_available_nodes[new_node_ptr].status = NODE_STATUS_USED ;
        }
    }
}

void remove_node_by_index (uint8_t head_ptr, int n) {
    if (n < 0) return ; // Invalid index
    
    uint8_t curr_ptr = head_ptr ;
    uint8_t prev_ptr = 0xff ; // Invalid pointer to indicate no previous node
    
    // Traverse to the nth node
    for (int i = 0; i < n; i++) {
        if (all_available_nodes[curr_ptr].ptr == 0x00) {
            return ; // Index out of bounds
        }
        prev_ptr = curr_ptr ;
        curr_ptr = all_available_nodes[curr_ptr].ptr ;
    }
    
    // Remove the node
    if (prev_ptr == 0xff) {
        // Removing the first node (head)
        all_available_nodes[curr_ptr].status = NODE_STATUS_FREE ;
        all_available_nodes[curr_ptr].ptr = 0xff ;
        all_available_nodes[curr_ptr].data = 0x0000 ;
    } else {
        // Removing a middle or last node
        all_available_nodes[prev_ptr].ptr = all_available_nodes[curr_ptr].ptr ;
        all_available_nodes[curr_ptr].status = NODE_STATUS_FREE ;
        all_available_nodes[curr_ptr].ptr = 0xff ;
        all_available_nodes[curr_ptr].data = 0x0000 ;
    }
}

void clear_list (uint8_t head_ptr) {
    uint8_t curr_ptr = head_ptr ;
    uint8_t next_ptr ;
    
    while (curr_ptr != 0x00) {
        next_ptr = all_available_nodes[curr_ptr].ptr ;
        all_available_nodes[curr_ptr].status = NODE_STATUS_FREE ;
        all_available_nodes[curr_ptr].ptr = 0xff ;
        all_available_nodes[curr_ptr].data = 0x0000 ;
        curr_ptr = next_ptr ;
    }
}

uint16_t base_data [192] = {
    0x1234, 0x5678, 0x9ABC, 0xDEF0, 0x2468, 0x1357, 0x9BDF, 0xACEF, 0x3579, 0x2468, 0x8ACE, 0x1357, 0x9BDF, 0x2468, 0x1357, 0x9BDF,
    0x1A2B, 0x3C4D, 0x5E6F, 0x7890, 0xABCD, 0xEF12, 0x3456, 0x789A, 0xBCDE, 0xF012, 0x3456, 0x789A, 0xBCDE, 0xF012, 0x3456, 0x789A,
    0x7A1C, 0x8D4E, 0x2B5F, 0x9E3A, 0x4C7D, 0x1F8B, 0xA6E2, 0x5D9C, 0x3B7A, 0xC8E4, 0x6F2D, 0x9A1E, 0x4E8C, 0x2D6F, 0xB3A7, 0x8F1D,
    0x5791, 0x6802, 0x7913, 0x8024, 0x9135, 0x0246, 0x1357, 0x2468, 0x3579, 0x4680, 0x5791, 0x6802, 0x7913, 0x8024, 0x9135, 0x0246,
    0x5E2A, 0x9F3B, 0x1C7D, 0x8A4E, 0x6D2F, 0x3B9C, 0xF7A1, 0x4E8D, 0x2C6B, 0xA9F3, 0x7D1E, 0x8B4C, 0x1F6A, 0x5C9D, 0xE3B7, 0x4A8F,
    0x7913, 0x8024, 0x9135, 0x0246, 0x1357, 0x2468, 0x3579, 0x4680, 0x5791, 0x6802, 0x7913, 0x8024, 0x9135, 0x0246, 0x1357, 0x2468,
    0xB4D8, 0x2E6A, 0x7F1C, 0xA9D3, 0x5C8E, 0x1B7F, 0xE4A9, 0x6D2C, 0x3F8B, 0x9C7E, 0x4A1D, 0x8E5C, 0x2D9F, 0x6B3A, 0xF1E7, 0x5D8C,
    0x9135, 0x0246, 0x1357, 0x2468, 0x3579, 0x4680, 0x5791, 0x6802, 0x7913, 0x8024, 0x9135, 0x0246, 0x1357, 0x2468, 0x3579, 0x4680,
    0x3E7A, 0x9B1D, 0x6F4C, 0x2A8E, 0xD5B7, 0x8C3F, 0x1E9A, 0x4D7B, 0xA6E2, 0x5F8D, 0xC9B3, 0x7A4E, 0x2D1F, 0x9E6C, 0x4B8A, 0xF3D7,
    0x1357, 0x2468, 0x3579, 0x4680, 0x5791, 0x6802, 0x7913, 0x8024, 0x9135, 0x0246, 0x1357, 0x2468, 0x3579, 0x4680, 0x5791, 0x6802,
    0x8F2C, 0x4A7E, 0x1D9B, 0x5E3A, 0xB7C4, 0x2F8D, 0x9A6E, 0x3C1F, 0xE7B4, 0x6D9A, 0x1F5C, 0x8B3E, 0x4C7A, 0x9D2F, 0x3E6B, 0xA1F8,
    0x3579, 0x4680, 0x5791, 0x6802, 0x7913, 0x8024, 0x9135, 0x0246, 0x1357, 0x2468, 0x3579, 0x4680, 0x5791, 0x6802, 0x7913, 0x8024
} ;
uint8_t init_ll_head_ptr [4] = {0x45, 0x7A, 0x2B, 0x8C} ;
uint8_t random_add_sequence [192] = {
    1, 0, 2, 3, 0, 2, 1, 3, 1, 3, 0, 2, 0, 1, 3, 2,
    2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1,
    3, 1, 2, 0, 1, 3, 2, 0, 3, 2, 1, 0, 2, 1, 0, 3,
    2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1,
    0, 2, 3, 1, 3, 0, 1, 2, 1, 3, 2, 0, 2, 0, 3, 1,
    2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1,
    1, 0, 3, 2, 2, 1, 0, 3, 3, 2, 1, 0, 0, 3, 2, 1,
    2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1,
    2, 1, 0, 3, 0, 3, 1, 2, 3, 0, 2, 1, 1, 2, 0, 3,
    2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1,
    3, 2, 1, 0, 1, 0, 2, 3, 0, 1, 3, 2, 2, 3, 1, 0,
    2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1
} ;
uint8_t random_remove_sequence [32] = {0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3} ;
uint8_t remove_indices [32] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1} ;

void setup_head_nodes () {
    all_available_nodes[init_ll_head_ptr[0]].ptr = 0x00 ;
    all_available_nodes[init_ll_head_ptr[0]].data = 0x0000 ;
    all_available_nodes[init_ll_head_ptr[0]].status = NODE_STATUS_USED ;
    all_available_nodes[init_ll_head_ptr[1]].ptr = 0x00 ;
    all_available_nodes[init_ll_head_ptr[1]].data = 0x0000 ;
    all_available_nodes[init_ll_head_ptr[1]].status = NODE_STATUS_USED ;
    all_available_nodes[init_ll_head_ptr[2]].ptr = 0x00 ;
    all_available_nodes[init_ll_head_ptr[2]].data = 0x0000 ;
    all_available_nodes[init_ll_head_ptr[2]].status = NODE_STATUS_USED ;
    all_available_nodes[init_ll_head_ptr[3]].ptr = 0x00 ;
    all_available_nodes[init_ll_head_ptr[3]].data = 0x0000 ;
    all_available_nodes[init_ll_head_ptr[3]].status = NODE_STATUS_USED ;
}

int main (void) {

    reserve_nodes_for_debug () ;
    setup_head_nodes () ;

    // First phase: Add first 96 elements
    for (int i = 0; i < 96; i++) {
        add_ll_node (init_ll_head_ptr[random_add_sequence[i]], base_data[i]) ;
    }

    
    // Remove 16 elements
    for (int i = 0; i < 16; i++) {
        remove_node_by_index (init_ll_head_ptr[random_remove_sequence[i]], remove_indices[i]) ;
    }
    
    // Second phase: Add next 96 elements (96-191)
    for (int i = 96; i < 192; i++) {
        add_ll_node (init_ll_head_ptr[random_add_sequence[i]], base_data[i]) ;
    }

    // Remove another 16 elements
    for (int i = 16; i < 32; i++) {
        remove_node_by_index (init_ll_head_ptr[random_remove_sequence[i]], remove_indices[i]) ;
    }

    /*

    // Clear all four lists
    clear_list (init_ll_head_ptr[0]) ;
    clear_list (init_ll_head_ptr[1]) ;
    clear_list (init_ll_head_ptr[2]) ;
    clear_list (init_ll_head_ptr[3]) ;
    */

    test_complete = 0xdeadbeef ;
    
}
