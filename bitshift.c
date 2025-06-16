#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
* credit:
* - https://t.me/GNUWeeb/1174879
* - https://gist.githubusercontent.com/ammarfaizi2/e88a21171358b5092a3df412eeb80b2f/raw/59141b48f59b70b1e96208716c45b1703c56daa7/vt_hexdump.h
*/
#ifndef VT_HEXDUMP_H
#define VT_HEXDUMP_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define CHDOT(C) (((32 <= (C)) && ((C) <= 126)) ? (C) : '.')
#define VT_HEXDUMP(PTR, SIZE)                               \
  do {                                                      \
    size_t i, j, k = 0, l, size = (SIZE);                   \
    unsigned char *ptr = (unsigned char *)(PTR);            \
    printf("============ VT_HEXDUMP ============\n");       \
    printf("File\t\t: %s:%d\n", __FILE__, __LINE__);        \
    printf("Function\t: %s()\n", __FUNCTION__);             \
    printf("Address\t\t: 0x%016lx\n", (uintptr_t)ptr);      \
    printf("Dump size\t: %ld bytes\n", (size));             \
    printf("\n");                                           \
    for (i = 0; i < ((size/16) + 1); i++) {                 \
      printf("0x%016lx|  ", (uintptr_t)(ptr + i * 16));     \
      l = k;                                                \
      for (j = 0; (j < 16) && (k < size); j++, k++) {       \
        printf("%02x ", ptr[k]);                            \
      }                                                     \
      while (j++ < 16) printf("   ");                       \
      printf(" |");                                         \
      for (j = 0; (j < 16) && (l < size); j++, l++) {       \
        printf("%c", CHDOT(ptr[l]));                        \
      }                                                     \
      printf("|\n");                                        \
    }                                                       \
    printf("=====================================\n");      \
  } while(0)

#endif


enum {
	EV_BIT_ACCEPT		= (0x0001ULL << 48ULL),
	EV_BIT_EVFD		= (0x0002ULL << 48ULL),
	EV_BIT_TARGET_DATA	= (0x0003ULL << 48ULL),
	EV_BIT_CLIENT_DATA	= (0x0004ULL << 48ULL),
	EV_BIT_TIMER		= (0x0005ULL << 48ULL),
	/* 0xFF 0xFF = 1 byte = 8 bit = 255 */
	TEST			= 0x0001ULL,
	/* 48 bit */
	TEST2			= 48ULL
	/* for 64 bit pointer, there is still more unused space 8 bit (?) */
};

#define ALL_EV_BITS	(EV_BIT_ACCEPT | EV_BIT_EVFD | \
				EV_BIT_TARGET_DATA | EV_BIT_CLIENT_DATA | \
				EV_BIT_TIMER)
#define GET_EV_BIT(X)	((X) & ALL_EV_BITS)
#define CLEAR_EV_BIT(X)	((X) & ~ALL_EV_BITS)

union test {
	char *a;
	uint64_t b;
};

/*
* context of this code:
* https://raw.githubusercontent.com/alviroiskandar/gwproxy/refs/heads/master/gwproxy.c
*
* trying to understand bit shift operator
* by print the enum in binary format from gdb
*/
int main(void)
{
	union test t;
	uint64_t ev_bit;

	// asm volatile("int3");
	memset(&t.a, 0, sizeof(char *));
	t.a = malloc(1);
	// asm volatile("int3");
	VT_HEXDUMP(&t.b, sizeof(uint64_t));
	t.b |= EV_BIT_ACCEPT;
	VT_HEXDUMP(&t.b, sizeof(uint64_t));
	// asm volatile("int3");
	ev_bit = GET_EV_BIT(t.b);
	// asm volatile("int3");
	t.b = CLEAR_EV_BIT(t.b);
	*t.a = 'c';
	printf("a have a ptr = %p\n", t.a);
	printf("value of ptr pointed by a = %c\n", *t.a);
	puts("ev bit extracted from a: ");
	VT_HEXDUMP(&ev_bit, sizeof(uint64_t));

	free(t.a);
	return 0;
}