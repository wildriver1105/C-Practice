#include <stdint.h>
// #define MM_MAX_STRUCT_NAME (SYSTEM_PAGE_SIZE - sizeof(vm_page_for_families_t *)) / sizeof(vm_page_family_t)
#define MM_MAX_STRUCT_NAME 64

#define offset_of(container_structure, field_name) ((size_t) &((container_structure *)0)->field_name)

#define MM_GET_PAGE_FROM_META_BLOCK(block_meta_data_ptr) ((void *)((char *)block_meta_data_ptr - block_meta_data_ptr->offset))

#define NEXT_META_BLOCK(block_meta_data_ptr) (block_meta_data_ptr->next_block)

#define NEXT_META_BLOCK_BY_SIZE(block_meta_data_ptr) (block_meta_data_t *)((char *) (block_meta_data_ptr + 1) + block_meta_data_ptr->block_size)

#define PREV_META_BLOCK(block_meta_data_ptr) (block_meta_data_ptr->prev_block)

#define mm_bind_blocks_for_allocation(allocated_meta_block, free_meta_block)

#define ITERATE_PAGE_FAMILIES_BEGIN(first_vm_page_for_families, vm_page_family_curr) for (vm_page_family_curr = first_vm_page_for_families->vm_page_family; vm_page_family_curr < &first_vm_page_for_families->vm_page_family[MAX_FAMILIES_PER_VM_PAGE]; vm_page_family_curr++)

#define ITERATE_PAGE_FAMILIES_END(first_vm_page_for_families, vm_page_family_curr)

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