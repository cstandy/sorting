/*
 * Program: Insertion Sort implementation
 * Author: cst.andy, EE depart., NCKU
 *
 */

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
