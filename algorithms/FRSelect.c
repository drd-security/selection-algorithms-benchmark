/* ========================================================================= *
 * FRSelect
 * Implementation of the Floyd-Rivest algorithm
 * ========================================================================= */

 #include <stddef.h>
 #include <math.h>
 #include "Select.h"


static int sign(double x){
    if(x > 0){
        return 1;
    }else if(x < 0){
        return -1;
    }

    return 0;
}

static size_t FRSelect(void *array, size_t left, size_t right, size_t k,
    int (*compare)(const void *, size_t i, size_t j),
    void (*swap)(void *array, size_t i, size_t j))
{
    while (right > left){
        // Si la taille du sous-tableau est grande, on échantillonne
        if((right - left) > 600){
            size_t n = (right - left) + 1;
            size_t i = k - left + 1;
            size_t z = log(n);
            double s = 0.5 * exp(2 * z/3);
            double sd = 0.5 * sqrt(z * s * (n - s) / n) * sign(i - n/2);

            size_t newLeft = fmax(left, k - i * s/n + sd);
            size_t newRight = fmin(right, k + (n - i) * s / n + sd);

            FRSelect(array, newLeft, newRight, k, compare, swap);

        }

        // Pivot
        swap(array, left, k);
        size_t pivotIndex = left;
        
        // Assurer que array[right] > array[left]
        if(compare(array, right, left) < 0){
            swap(array, left, right);
        }
        // Partition
        size_t i = left + 1;
        size_t j = right - 1;

        while (i <= j){
            while(i <= j && compare(array, i, pivotIndex) < 0)
                i++;
            while(i <= j && compare(array, pivotIndex, j) < 0)
                j--;
            if(i <= j){
                swap(array, i, j);
                i++;
                j--;
            }
        }

        swap(array, pivotIndex, j);
        // Continuer avec la moitié qui contient le k-ième élément

        if(j < k)
            left = j + 1; // Recherche dans une partie
        else if (k < j)
            right = j - 1; // on cherche dans l'autre
        else
            return k;// j == k, élément trouvé
    }
    return k;

}


size_t select(void *array, size_t length, size_t k,
              int (*compare)(const void *, size_t i, size_t j),
              void (*swap)(void *array, size_t i, size_t j))
{
    return FRSelect(array, 0, length - 1, k, compare, swap);
}

