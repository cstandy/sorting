/*
 * Program: Quick Sort implementation with run time measure.
 *          Combine insertion sort when n is small.
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
#define BOUND_NUM 500

#include <fstream>
#include <iostream>
#include <cstdlib> // for atoi(), which changes a string to integer
#include <string>
#include <chrono>  // for run time measure
using namespace std;

/* insertion sort algorithm */
void issort(int *keys, int length)
{
	int key;
	int index;

	for (int i = 0; i < length; i++)
	{
		key = keys[i];

		/* insert keys[i] into the sorted sequence keys[0...i-1] */
		index = i - 1;
		
		while (index >= 0 && keys[index] > key)
		{
			keys[index + 1] = keys[index];
			index--;
		}

		keys[index + 1] = key;
	}
}

/* partition in quick sort */
int partition(int *keys, int start, int end)
{
	int exc; // for exchange
	int pivot = keys[end];
	int i = start - 1;

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
		if (end - start > BOUND_NUM) {
			int mid = partition(keys, start, end);
			qksort(keys, start, mid - 1);
			qksort(keys, mid + 1, end);	
		} else {
			issort(keys + start, end - start + 1);
		}
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

	/* record the time point before sorting */
	auto begin = chrono::high_resolution_clock::now();

	/* quick sort */
	qksort(keys, 0, keyNum - 1);

	/* record the time point after sorting */
	auto stop = chrono::high_resolution_clock::now();

	/* print the run time to screen */
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - begin);
	cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

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
