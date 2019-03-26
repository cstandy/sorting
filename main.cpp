/*
 * Program: Read input and write output file for sorting algorithm.
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
#include <string>

#include "mgsort.h" // merge sort header
#include "issort.h" // insertion sort header

using namespace std;


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


#ifdef INSERTION_SORT
	/* insertion sort */
	issort(keys, keyNum);
#endif

#ifdef MERGE_SORT
	/* merge sort */
	mgsort(keys, 0, keyNum - 1);
#endif

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
