/* ========================================================================= *
 * QuickSelect
 * Implementation of the QuickSelect algorithm
 * ========================================================================= */

#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include "Select.h"

static size_t quickSelect(void *array, size_t p, size_t r, size_t k,
                          int (*compare)(const void *, size_t i, size_t j),
                          void (*swap)(void *array, size_t i, size_t j));

static size_t partition(void *array, size_t p, size_t r,
                        int (*compare)(const void *, size_t i, size_t j),
                        void (*swap)(void *array, size_t i, size_t j));

static size_t partition(void *array, size_t p, size_t r,
                        int (*compare)(const void *, size_t i, size_t j),
                        void (*swap)(void *array, size_t i, size_t j))
{
    size_t pivot = p + rand() % (r - p + 1); // pivot aléatoirement choisi

    swap(array, pivot, r); // pivot placé à la fin du tableau

    size_t i = p; // on commence au début du tableau
    for (size_t j = p; j < r; j++)
    {
        if (compare(array, j, r) < 0)
        {
            swap(array, i, j);
            i++; // cette boucle s'oocupe de "partitionner" le tableau en mettant les éléments plus petits que notre pivot avant le pivot et ceux plus grands, après
        }
    }
    swap(array, i, r);

    return i;
}

static size_t quickSelect(void *array, size_t p, size_t r, size_t k,
                          int (*compare)(const void *, size_t i, size_t j),
                          void (*swap)(void *array, size_t i, size_t j))
{

    while (p <= r)
    {
        size_t pivot_index = partition(array, p, r, compare, swap);

        if (pivot_index == k) // Si le pivot est l'élément recherché
            return pivot_index; 
        else if (pivot_index > k) // Recherche dans la partie gauche
            r = pivot_index - 1;
        else    // Recherche dans la partie droite
            p = pivot_index + 1;   
    }
    return k;   // Retourne la position du k-ième plus petit élément
}

size_t select(void *array, size_t length, size_t k,
              int (*compare)(const void *, size_t i, size_t j),
              void (*swap)(void *array, size_t i, size_t j))
{

    return quickSelect(array, 0, length - 1, k, compare, swap);
}
