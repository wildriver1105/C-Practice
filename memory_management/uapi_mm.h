#ifndef __UAPI_MM__
#define __UAPI_MM__

#include <stdint.h>

void mm_init();

void mm_instantiate_new_page_family(char *struct_name, uint32_t struct_size);

#endif // __UAPI_MM__