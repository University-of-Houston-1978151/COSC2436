#include "HashTable.h"
#include <iostream>

HashTable::HashTable()
{
	bucketArray = new HashBucket[10];
	maxBuckets = 10;
}

HashTable::~HashTable()
{
	//free memory related to the table
	for (int i = 0; i < maxBuckets; i++)
	{
		while (bucketArray[i].head != nullptr)
		{
			BucketNode *temp = bucketArray[i].head;
			bucketArray[i].head = bucketArray[i].head->next;
			delete (temp);
			temp = nullptr;
		}
	}
	delete[] bucketArray;
}

int HashTable::hashFunc(string password)
{
	int hashval = 0;
	for (unsigned int i = 0; i < password.size(); i++)
	{
		hashval = hashval + ((char)password[i]);
	}
	hashval = hashval % 10;
	return hashval;
}

int HashTable::numElementsInBucket(int bucketIndex)
{
	//return number of passwords in specified bucket of hash table
	int count = 0;
	BucketNode *temp = bucketArray[bucketIndex].head;
	while (temp != nullptr)
	{
		temp = temp->next;
		count++;
	}
	return count;
}

void HashTable::addElement(string password, bool actualPassword)
{
	//add password to correct bucket in hash table; also, indicate if password was from the actualPassword.txt file or attemptedPassword.txt file
	int key = hashFunc(password);
	BucketNode *temp = new BucketNode();
	temp->password = password;
	temp->actualPassword = actualPassword;

	if (bucketArray[key].head == nullptr)
	{
		bucketArray[key].head = temp;
		return;
	}
	bucketArray[key].head->prev = temp;
	temp->next = bucketArray[key].head;
	bucketArray[key].head = temp;
}

void HashTable::removeElements()
{
	//print all nodes in buckets consisting of only one element, then delete that element
	for (int i = 0; i < maxBuckets; i++)
	{
		if (numElementsInBucket(i) == 1)
		{
			cout << bucketArray[i].head->password << " deleted" << endl;
			bucketArray[i].head = nullptr;
		}
	}
}

void HashTable::printCollisions()
{
	//print all compromised passwords
	for (int i = 0; i < maxBuckets; i++)
	{
		if (numElementsInBucket(i) > 1)
		{
			int j = 0;
			BucketNode *temp = bucketArray[i].head;
			while (temp != nullptr)
			{
				if (temp->next == nullptr && temp->actualPassword == true)
				{
					cout << temp->password << ": " << j << " collisions" << endl;
				}
				j++;
				temp = temp->next;
			}
		}
	}
}