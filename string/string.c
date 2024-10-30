// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	int i = 0;

	while (source[i] != '\0') {
		destination[i] = source[i];
		i++;
	}

	destination[i] = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	size_t i = 0;
	int ok = 1;

	size_t len1 = strlen(source);

	if (len >= len1) {
		ok = 0;
		len = len1;
	}

	while (i < len) {
		destination[i] = source[i];
		i++;
	}

	if (!ok)
		destination[i] = '\0';

	return destination;
}

char *strcat(char *destination, const char *source)
{
	size_t dest_len = strlen(destination);
	size_t source_len = strlen(source);
	size_t i = 0;

	while (i < source_len) {
		destination[dest_len + i] = source[i];
		i++;
	}

	destination[dest_len + i] = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	size_t dest_len = strlen(destination);
	size_t i = 0;

	while (i < len) {
		destination[dest_len + i] = source[i];
		i++;
	}

	destination[dest_len + i] = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	size_t len_1 = strlen(str1);
	size_t len_2 = strlen(str2);
	size_t i = 0;

	while (i < len_1 || i < len_2) {
		if (str1[i] > str2[i]) {
			return 1;
		} else if (str1[i] < str2[i]) {
			return -1;
		}
        i++;
	}


	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
    size_t i = 0;


	while (i < len) {
		if (str1[i] > str2[i]) {
			return 1;
		} else if (str1[i] < str2[i]) {
			return -1;
		}

		i++;
	}

	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	size_t i = 0;

	while (str[i] != '\0') {
		if (str[i] == c)
			return (char *) str + i;
		i++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	size_t i = strlen(str);

	while (i > 0) {
		if (str[i - 1] == c)
			return (char *) str + i - 1;
		i--;
	}

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	size_t needle_len = strlen(needle);
	size_t i = 0;

	while (haystack[i] != '\0') {
		if (strncmp(haystack + i, needle, needle_len) == 0) {
			return (char *) haystack + i;
		}

        i++;
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	size_t i = strlen(haystack);
    size_t needle_len = strlen(needle);

	while (i > 0) {
		if (strncmp(haystack + i - 1, needle, needle_len) == 0)
			return (char *) haystack + i - 1;
		i--;
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *d = (char *)destination;
	char *s = (char *)source;

	size_t i = 0;

	while (i < num) {
		d[i] = s[i];
		i++;
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *destination_pointer = (char *)destination;
	const char *source_pointer = (const char *)source;
	size_t i = 0;

	if (destination_pointer < source_pointer) {
		while (i < num) {
			destination_pointer[i] = source_pointer[i];
			i++;
		}
	} else {
		i = num;
		while (i > 0) {
			destination_pointer[i - 1] = source_pointer[i -1];
			i--;
		}
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t i = 0;

	char *str1 = (char *)ptr1;
	char *str2 = (char *)ptr2;

	while (i < num) {
		if (str1[i] > str2[i]) {
			return 1;
		} else if (str1[i] < str2[i]) {
			return -1;
		}

		i++;
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	char *s = (char *)source;
	size_t i = 0;

	while (i < num) {
		s[i] = value;
		i++;
	}

	return source;
}
