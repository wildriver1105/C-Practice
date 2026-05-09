#include <stdint.h>
// #define MM_MAX_STRUCT_NAME (SYSTEM_PAGE_SIZE - sizeof(vm_page_for_families_t *)) / sizeof(vm_page_family_t)
#define MM_MAX_STRUCT_NAME 64

typedef enum {
    MM_FALSE,
    MM_TRUE
} vm_bool_t;

struct vm_page_family_;

typedef struct vm_page_family_ {
    char struct_name[MM_MAX_STRUCT_NAME];
    uint32_t struct_size;
} vm_page_for_family_t;

typedef struct vm_page_for_families_ {
    struct vm_page_for_families *next;
    vm_page_for_family_t vm_page_family[0];
} vm_page_for_families_t;

typedef struct block_meta_data_ {
    vm_bool_t is_free;
    uint32_t block_size;
    uint32_t offset;
    struct block_meta_data_ *prev_block;
    struct block_meta_data_ *next_block;
} block_meta_data_t;