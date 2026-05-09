#ifndef __UAPI_MM__
#define __UAPI_MM__

#include <stdint.h>

void mm_init();

void mm_instantiate_new_page_family(char *struct_name, uint32_t struct_size);

#define MM_REG_STRUCT(struct_name) (mm_instantiate_new_page_family(#struct_name, sizeof(struct_name)))

typedef struct block_meta_data_ {
    vm_bool_t is_free;
    uint32_t block_size;
    uint32_t offset;
    struct block_meta_data_ *prev_block;
    struct block_meta_data_ *next_block;
} block_meta_data_t;

#endif // __UAPI_MM__