#include <fstream>
#include "BSTUtils.h"
#include <algorithm>
#include <vector>

string *file_to_array(string f_name, int *l)
{
	fstream inputFile(f_name);
	vector<string> tempVec;
	string line;

	while (getline(inputFile, line))
	{
		tempVec.push_back(line);
	}

	int size = tempVec.size();

	cout << size << endl;

	*l = size;
	string *fileArray = new string[size];

	for (int i = 0; i < size; i++)
	{
		fileArray[i] = tempVec[i];
	}

	return fileArray;
}

void array_to_bst(string key_arr[], int len, BSTree *i_bst)
{
	for (int i = 0; i < len; i++)
	{
		i_bst->addNode(key_arr[i]);
	}
}

string *presort_array(string in_arr[], int len)
{
	sort(in_arr, in_arr + len);

	return in_arr;
}
