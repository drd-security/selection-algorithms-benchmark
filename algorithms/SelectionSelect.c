/* ========================================================================= *
 * SelectionSelect
 * Implementation of the SelectionSelect algorithm
 * ========================================================================= */

#include <stddef.h>
#include "Select.h"

size_t select(void *array, size_t length, size_t k,
              int (*compare)(const void *, size_t i, size_t j),
              void (*swap)(void *array, size_t i, size_t j))
{
    size_t i, j, min;
    for (i = 0; i <= k; i++) // Boucle pour sélectionner les k plus petits éléments
    {
        min = i;

        for (j = i + 1; j < length; j++)
        {
            if (compare(array, j, min) < 0)
            {
                min = j;
            }
        }

        if (min != i) // Éviter un swap inutile
        {
            swap(array, i, min);
        }
    }
    return k; // Retourne la position du k-ième plus petit élément
}
