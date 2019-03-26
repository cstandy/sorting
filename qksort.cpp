/*
 * Program: Quick Sort implementation
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
using namespace std;

/* partition in quick sort */
int partition(int *keys, int start, int end)
{
	int pivot = keys[end];
	int i = start - 1;
	int exc; // for exchange

	for (int j = start; j < end; j++)
	{
		if (keys[j] <= pivot)
		{
			i++;

			/* exchange keys[i] & keys[j] */
			exc     = keys[i];
			keys[i] = keys[j];
			keys[j] = exc;
		}
	}

	/* exchange keys[i + 1] & keys[end] */
	exc         = keys[i + 1];
	keys[i + 1] = keys[end];
	keys[end]   = exc;

	return (i + 1);
}

/* quick sort algorithm */
void qksort(int *keys, int start, int end)
{
	if (start < end)
	{
		int mid = partition(keys, start, end);
		qksort(keys, start, mid - 1);
		qksort(keys, mid + 1, end);	
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

	/* quick sort */
	qksort(keys, 0, keyNum - 1);

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
