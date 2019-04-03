/*
 * Program: Test if the output file sorted. 
 * Author: cst.andy, EE depart., NCKU
 * 
 * Input file form:
 *     First line: the number of sorted keys.
 *     Following line: the list of the keys, one line for each.
 */

#define IFILENAME "output.txt"

#include <fstream>
#include <iostream>

using namespace std;

int main ()
{
	ifstream iFile;
	int key_num;
	int prev = 0;
	int curt = 0;

	cout << "File reading ...\n";
	iFile.open(IFILENAME, ios::in);

	if (!iFile) {
		cerr << "Error: File reading error.\n";
		exit(1);
	}

	/* read the number of keys */
	iFile >> key_num;
	cout << "Sorted sequence length is " << key_num << " long.\n";

	for (int i = 0; i < key_num; i++)
	{
		iFile >> curt;

		if (curt < prev) {
			cout << "Error: unsorted pair found: prev = "
			     << prev << ", curt = " << curt << "\n";
		}

		prev = curt;
	}

	return 0;
}
