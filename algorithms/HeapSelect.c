/* ========================================================================= *
 * HeapSelect
 * Implementation of the HeapSelect algorithm
 * ========================================================================= */

#include <stddef.h>
#include "Select.h"

static void build_min_heap(void *array, size_t length, size_t k,
                           int (*compare)(const void *, size_t i, size_t j),
                           void (*swap)(void *array, size_t i, size_t j))
{
    size_t smallest = k;
    size_t left = 2 * k + 1;
    size_t right = 2 * k + 2;

    // Vérifier et mettre à jour le plus petit entre le nœud et son fils gauche
    if (left < length && compare(array, left, smallest) < 0)
    {
        smallest = left;
    }

    // Vérifier et mettre à jour le plus petit entre le nœud et son fils droit
    if (right < length && compare(array, right, smallest) < 0)
    {
        smallest = right;
    }

    // Si le plus petit n'est pas le nœud actuel, échanger et propager
    if (smallest != k)
    {
        swap(array, k, smallest);
        // Récursivement ajuster le sous-arbre affecté
        build_min_heap(array, length, smallest, compare, swap);
    }
}

size_t select(void *array, size_t length, size_t k,
              int (*compare)(const void *, size_t i, size_t j),
              void (*swap)(void *array, size_t i, size_t j))
{

    // Construire un min-heap avec tous les éléments du tableau
    for (size_t i = length / 2; i > 0; i--)
    {
        build_min_heap(array, length, i - 1, compare, swap);
    }

    build_min_heap(array, length, 0, compare, swap);

    // Extraire les k plus petits éléments
    for (size_t i = 0; i < k; i++)
    {
        // Échanger le premier élément (minimum) avec le dernier non traité
        swap(array, 0, length - 1 - i);
        // Reconstruire le heap en excluant les éléments déjà extraits
        build_min_heap(array, length - 1 - i, 0, compare, swap);
    }
    return 0;
}