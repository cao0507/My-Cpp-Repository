#ifndef _STRING_H_
#define _STRING_H_

#include <cstring>
#include <cassert>


void* memcpy(void* dest, const void* src, size_t count){
	char *tmp = (char*)dest;
	const char* s = (char*)src;

	while (count--)
		*tmp++ = *s++;
	return dest;
}

char* strcpy(char *dst, const char *src){
	assert(dst != NULL && src != NULL);
	char *ret = dst;
	while ((*dst++ = *src++) != '\0');
	return ret;
}

char* strcat(char *dst, const char* src){
	assert(dst != NULL && src != NULL);
	char *tmp = dst;
	while (*tmp != '\0'){
		tmp++;
	}
	
	while ( (*tmp++ = *src++) != '\0' );

	return dst;
}

char* strncat(char* dst, char* src, size_t num){
	assert(dst != NULL && src != NULL);
	char *tmp = dst;
	while (*tmp != '\0')
		++tmp;

	while (num-- && *src != '\0'){
		*tmp++ = *src++;
	}
	*tmp = '\0';
	return dst;
}

int strcmp(const char* str1, const char* str2){
	while (*str1 == *str2){
		if (*str1 == '\0')
			return 0;
		++str1;
		++str2;
	}
	return *str1 - *str2;
}

#endif
