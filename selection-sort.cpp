#include <iostream>
#include <limits>
#include <new>
using namespace std;

int integerInput();
int getSize();
void selectionSort(int[], int);
void displayArray(int[], int);

int main()
{
	int size, * arr, * sortedArr;

	cout << "Enter the size of the array: ";
	size = getSize();
	arr = new (nothrow) int[size];
	sortedArr = new (nothrow) int[size];
	if (arr == nullptr || sortedArr == nullptr)
	{
		cout << endl << "Failed to allocate memory! Please restart the application.";
		exit(0);
	}

	cout << endl << "Enter all the elements of the array: ";
	for (int i = 0; i < size; i++)
	{
		arr[i] = integerInput();
		cout << "Elements remaining to be entered: " << size - i - 1 << endl;
	}
	
	selectionSort(arr, size);
	

	return 0;

}

int integerInput()
{
	int n;

	while (!(cin >> n))
	{
		cin.clear();
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		cout << endl << "Invalid integer input! Please try again with correct input: ";
	}

	return n;
}

int getSize()
{
	int size = integerInput();

	if (size <= 0)
	{
		cout << endl << "Invalid size! Please try again: ";
		size = getSize();
	}

	return size;
}

void selectionSort(int arr[], int size)
{
	int max, swap, indexOfMax;

	for (int i = size - 1; i >= 0; i--)
	{
		max = arr[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[j] < arr[i])
				max = arr[j];
			indexOfMax = j;
		}

		if (max != arr[i])
		{
			swap = arr[i];
			arr[i] = arr[indexOfMax];
			arr[indexOfMax] = swap;
		}
	}
}

void displayArray(int arr[], int size)
{
	cout << endl << "The sorted array is: ";

	for (int i = size - 1; i >= 0; i--)
	{
		cout << "|" << arr[i] << "|";
		if (i % 24 == 0)
			cout << endl;
	}
}