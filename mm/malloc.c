// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void* block = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (block == MAP_FAILED)
		return NULL;

	mem_list_add(block, size);

	return block;
}

void *calloc(size_t nmemb, size_t size)
{
	void* block = malloc(nmemb * size);

	if (block == NULL)
		return NULL;

	memset(block, 0, nmemb * size);

	return block;
}

void free(void *ptr)
{
	struct mem_list *block = mem_list_find(ptr);

	munmap(ptr, block->len);

	mem_list_del(block->start);
}

void *realloc(void *ptr, size_t size)
{
	void *new_ptr = malloc(size);

	if (new_ptr == NULL)
		return NULL;

	memcpy(new_ptr, ptr, mem_list_find(ptr)->len);

	if (munmap(ptr, mem_list_find(ptr)->len) == -1)
		return NULL;

	if (mem_list_del(ptr) == -1)
		return NULL;

	return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	void *new_ptr = realloc(ptr, nmemb * size);

	if (new_ptr == NULL)
		return NULL;

	return new_ptr;
}
