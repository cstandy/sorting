/*
 * Program: Merge Sort implementation
 * Author: cst.andy, EE depart., NCKU
 *
 */

#include <cstdlib> // for atoi(), which changes a string to integer
#include <limits>  // for max(), which gives the maximun value of a type
using namespace std;

/* merge 2 sorted part in to 1 */
void merge(int *keys, int start, int mid, int end)
{
    int l1 = mid - start + 1;
    int l2 = end - mid;
    int *k1 = new int[l1 + 1];
    int *k2 = new int[l2 + 1];

    /* copy the keys to 2 new arrays */
    for (int i = 0; i < l1; i++)
        k1[i] = keys[start + i];
    for (int i = 0; i < l2; i++)
        k2[i] = keys[mid + i + 1];

    /* set the end of array as maximun value */
    k1[l1] = numeric_limits<int>::max();
    k2[l2] = numeric_limits<int>::max();

    /* start merge */
    int i = 0, j = 0;
    for (int k = start; k <= end; k++)
    {
        if (k1[i] <= k2[j])
        {
            keys[k] = k1[i];
            i++;
        }
        else
        {
            keys[k] = k2[j];
            j++;
        }
    }

    delete[] k1;
    delete[] k2;
}

/* recursive merge sort function */
void mgsort(int *keys, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) >> 1;
        mgsort(keys, start, mid);
        mgsort(keys, mid + 1, end);
        merge(keys, start, mid, end);
    }
}
