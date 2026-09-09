#ifndef SELECT_H
#define SELECT_H
#include <stddef.h>
size_t select(void *array, size_t length, size_t k,
              int (*compare)(const void *, size_t i, size_t j),
              void (*swap)(void *array, size_t i, size_t j));
#endif
