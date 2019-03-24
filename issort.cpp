/*
 * Program: Insertion Sort implementation
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

/* insertion sort algorithm */
void issort(int *keys, int length)
{
	int key;
	int index;

	for (int i = 1; i < length; i++)
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

	/* insertion sort */
	issort(keys, keyNum);

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
