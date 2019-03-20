/*
 * Program: Merge Sort implementation
 * Author: cst.andy, EE depart., NCKU
 *
 * Input file form:
 *     First line: the number of keys to be sorted.
 *     Following line: the list of the keys, one line for each.
 * 
 * Output file form:
 *     First line: the number of keys to be sorted.
 *     Following line: the list of the keys, one line for each.
 */

#define OFILENAME "output.txt"

#include <fstream>
#include <iostream>
#include <cstdlib> // for atoi(), which changes a string to integer
#include <limits>  // for max(), which gives the maximun value of a type
#include <string>
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

/* main function aims to fit the requirements of input and output file form */
int main(int argc, char* argv[])
{
    int inputNum;
    char* iFileName;
    string iString;
    ifstream iFile;
    ofstream oFile;

    /* check if the input filename is entered */
    if (argc == 2)
    {
        iFileName = argv[1];
    }
    else {
        printf("Error: no source entered, input file failed.\n");
        exit(1);
    }

    iFile.open(iFileName, ios::in);

    /* check if the input file is opened correctly */
    if (!iFile)
    {
        printf("Error: input file open failed.");
        exit(1);
    }

    getline(iFile, iString);

    /* get the number of key */
    int keyNum = atoi(iString.c_str());
    int *keys = new int[keyNum];

    /* read the key list in */
    for (int i = 0; i < keyNum; i++)
    {
        getline(iFile, iString);
        keys[i] = atoi(iString.c_str());
    }

    /* close the input file after read */
    iFile.close();

    mgsort(keys, 0, keyNum - 1);

    oFile.open(OFILENAME, ios::out);

    /* check if the output file is opened correctly */
    if (!oFile)
    {
        printf("Error: output file open failed.");
        exit(1);
    }

    /* output the number of keys */
    oFile << keyNum;

    /* output sorted keys */
    for (int i = 0; i < keyNum; i++)
    {
        oFile << "\n" << keys[i];
    }

    oFile.close();
    
    delete[] keys;

    return 0;
}
