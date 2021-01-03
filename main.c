#include "BIT_FLAGS.h"

int main(){
    BIT_FLAGS data_handler = bit_flags_init_number_of_bits(20);

    bit_flags_set_flag(data_handler,1);
    bit_flags_unset_flag(data_handler,2);
    bit_flags_set_flag(data_handler,10);
    bit_flags_set_flag(data_handler,28);

    printf("Byte 0: %X\n", data_handler->FLAGS[0]);
    printf("Byte 1: %X\n", data_handler->FLAGS[1]);
    printf("Byte 2: %X\n", data_handler->FLAGS[2]);
    printf("Byte 3: %X\n", data_handler->FLAGS[3]);
    printf("Flag 28: %X\n", bit_flags_check_flag(data_handler,28));
    printf("Flag 10: %X\n", bit_flags_check_flag(data_handler,10));
    printf("Flag 2: %X\n", bit_flags_check_flag(data_handler,2));
    printf("Checking size: %d\n", bit_flags_get_size(data_handler));
    printf("Checking capacity: %d\n", bit_flags_get_capacity(data_handler));

    bit_flags_destroy(data_handler);

    return 0;
}