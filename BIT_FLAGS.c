#include "BIT_FLAGS.h"

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits)
{
    int bytes = 0;
    struct data_structure * instance = (struct data_structure *) malloc (sizeof(struct data_structure));
    bytes = ceil((float)number_of_bits/8.0);
    instance->FLAGS = (unsigned char *) malloc (bytes);
    instance->size = bytes;
    memset(instance->FLAGS,0,ceil((float)number_of_bits/8.0));
    instance->data = 0;
    
    return instance;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    int overflow = flag_position/(hBit_flags->size*8);
    int flush_reallocation_index = 0;
    if (overflow){
       hBit_flags->FLAGS = realloc(hBit_flags->FLAGS, hBit_flags->size + overflow);
       if (hBit_flags->FLAGS == NULL){
           return FAILURE;
       }
       for (flush_reallocation_index=hBit_flags->size; flush_reallocation_index < hBit_flags->size + overflow; flush_reallocation_index++){
           hBit_flags->FLAGS[flush_reallocation_index] = 0;
       }
       hBit_flags->size += overflow;
    }
    hBit_flags->FLAGS[flag_position/8] |= (0x01) << (flag_position % 8);
    hBit_flags->data++;
    return SUCCESS;
}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    int overflow = flag_position/(hBit_flags->size*8);
    int flush_reallocation_index = 0;

    if (overflow){
        hBit_flags->FLAGS = realloc(hBit_flags->FLAGS, (hBit_flags->size) + overflow);
        if (hBit_flags->FLAGS == NULL){
            return FAILURE;
        }
        for (flush_reallocation_index=(hBit_flags->size); flush_reallocation_index < (hBit_flags->size) + overflow; flush_reallocation_index++){
            hBit_flags->FLAGS[flush_reallocation_index] = 0;
        }
       hBit_flags->size += overflow;
    }

    hBit_flags->FLAGS[flag_position/8] &= ~( (0x01) << (flag_position % 8) );
    hBit_flags->data++;
    return SUCCESS;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    if (flag_position/8 >= (hBit_flags->size)) return -1;
    return (hBit_flags->FLAGS[flag_position/8] & ~((0x01) << (flag_position % 8 -1))) >> (flag_position % 8);
}

int bit_flags_get_size(BIT_FLAGS hBit_flags){
    return hBit_flags->data;
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags){
    return (hBit_flags->size) * 8;
}

void bit_flags_destroy(BIT_FLAGS* hBit_flags)
{
    free((*hBit_flags)->FLAGS);
    free(*hBit_flags);
}