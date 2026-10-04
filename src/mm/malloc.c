// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	if (mem_list_num_items() == 0) {
		mem_list_init();
	}

	void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ptr == MAP_FAILED) {
		return NULL;
	}
	mem_list_add(ptr, size);
	return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *ptr = malloc(nmemb * size);
	if (!ptr)
		return NULL;
	memset(ptr, 0, nmemb * size);
	return ptr;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr == NULL) {
		return;
	}

	struct mem_list *block = mem_list_find(ptr);
	if (block != NULL) {
		munmap(block->start, block->len);
		mem_list_del(ptr);
	}
}

void *realloc(void *ptr, size_t size)
{
    /* TODO: Implement realloc(). */
	struct mem_list *list_elem = mem_list_find(ptr);
    if (list_elem == NULL) {
        return NULL;
    }
    void *new_ptr = malloc(size);
    memcpy(new_ptr, ptr, list_elem->len);
    free(ptr);
	list_elem = new_ptr;
    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	return realloc(ptr, nmemb * size);
}
