// SPDX-License-Identifier: BSD-3-Clause
#include <string.h>

char *strcpy(char *destination, const char *source) {
	int i = 0;
	while (source[i] != '\0') {
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len) {
	/* TODO: Implement strncpy(). */
	char *d = destination;
	const char *s = source;
	while (len && *s) {
		*d++ = *s++;
		len--;
	}
	while (len--)
		*d++ = '\0';
	return destination;
}

char *strcat(char *destination, const char *source) {
	/* TODO: Implement strcat(). */
	char *dest = destination;
	while (*dest != '\0')
		dest++;
	for (; *source != '\0'; dest++, source++)
		*dest = *source;
	*dest = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len) {
	/* TODO: Implement strncat(). */
	char *dest = destination;
	while (*dest != '\0')
		dest++;
	size_t i;
	for (i = 0; i < len && source[i] != '\0'; i++)
		dest[i] = source[i];
	dest[i] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2) {
	/* TODO: Implement strcmp(). */
	while (*str1 && (*str1 == *str2)) {
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

int strncmp(const char *str1, const char *str2, size_t len) {
	/* TODO: Implement strncmp(). */
	for (size_t i = 0; i < len; i++) {
		if (str1[i] != str2[i] || str1[i] == '\0' || str2[i] == '\0')
			return str1[i] - str2[i];
	}
	return 0;
}

size_t strlen(const char *str) {
	size_t i = 0;
	for (; *str != '\0'; str++, i++)
		;
	return i;
}

char *strchr(const char *str, int c) {
	/* TODO: Implement strchr(). */
	while (*str) {
		if (*str == (char)c)
			return (char *)str;
		str++;
	}
	if (c == '\0')
		return str;
	else
		return NULL;
}

char *strrchr(const char *str, int c) {
	/* TODO: Implement strrchr(). */
	const char *last = NULL;
	while (*str) {
		if (*str == c)
			last = str;
		str++;
	}
	if (c == '\0')
		return str;
	return last;
}


char *strstr(const char *haystack, const char *needle) {
	/* TODO: Implement strstr(). */
	if (!*needle)
		return (char *)haystack;
	for (; *haystack; haystack++) {
		const char *h = haystack;
		const char *n = needle;
		while (*h && *n && (*h == *n)) {
			h++;
			n++;
		}
		if (!*n)
			return (char *)haystack;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle) {
	/* TODO: Implement strrstr(). */
	if (!*needle)
		return (char *)haystack;
	char *result = NULL;
	for (; *haystack; haystack++) {
		const char *h = haystack;
		const char *n = needle;
		while (*h && *n && (*h == *n)) {
			h++;
			n++;
		}
		if (!*n)
			result = (char *)haystack;
	}
	return result;
}

void *memcpy(void *destination, const void *source, size_t num) {
	/* TODO: Implement memcpy(). */
	unsigned char *d = destination;
	const unsigned char *s = source;
	for (size_t i = 0; i < num; i++)
		d[i] = s[i];
	return destination;
}

void *memmove(void *destination, const void *source, size_t num) {
	/* TODO: Implement memmove(). */
	unsigned char *d = destination;
	const unsigned char *s = source;
	if (d < s) {
		for (size_t i = 0; i < num; i++)
			d[i] = s[i];
	} else if (d > s) {
		for (size_t i = num; i > 0; i--)
			d[i - 1] = s[i - 1];
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
	/* TODO: Implement memcmp(). */
	const unsigned char *a = ptr1;
	const unsigned char *b = ptr2;
	for (size_t i = 0; i < num; i++) {
		if (a[i] != b[i])
			return a[i] - b[i];
	}
	return 0;
}

void *memset(void *source, int value, size_t num) {
	/* TODO: Implement memset(). */
	unsigned char *s = source;
	for (size_t i = 0; i < num; i++)
		s[i] = value;
	return source;
}
