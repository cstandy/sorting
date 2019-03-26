/*
 * Program: Generate nearly sorted 10000 input for testing.
 * Author: cst.andy, EE depart., NCKU
 * 
 * Output file form:
 *     First line: the number of keys to be sorted.
 *     Following line: the list of the keys, one line for each.
 */

#define OFILENAME "input.txt"

// input number to be generated
#define INPUTNUM  10000

// max switch times
// much less than INPUTNUM to generate nearly sorted sequence
#define MAXSWITCH 1000

#include <fstream>
#include <iostream>
#include <cstdlib> // for rand()
#include <ctime>   // for time()

using namespace std;

/* mess up the sorted sequence to nearly sorted */
void messup(int *keys, int times)
{
	int x, y, z;

	for (int i = 0; i < times; i++)
	{
		x = rand() % 10000;
		y = rand() % 10000;
		
		/* exchange */
		z       = keys[x];
		keys[x] = keys[y];
		keys[y] = z;
	}
}

/* main function aims to fit the requirements of output file form */
int main()
{
    ofstream oFile;
    int keys[INPUTNUM];

    /* generate sorted sequence */
    for (int i = 0; i < INPUTNUM; i++)
    {
        keys[i] = i;
    }

	/* set the seed of random */
	srand(time(NULL));

	/* generate random number */
	int times = rand() % MAXSWITCH;

	/* mess up the sorted sequence to nearly sorted */
	messup(keys, times);

    oFile.open(OFILENAME, ios::out);

    /* check if the output file is opened correctly */
    if (!oFile)
    {
        printf("Error: output file open failed.");
        exit(1);
    }

    /* output the number of keys */
    oFile << INPUTNUM;

    /* output sorted keys */
    for (int i = 0; i < INPUTNUM; i++)
    {
        oFile << "\n" << keys[i];
    }

    oFile.close();

    return 0;
}
