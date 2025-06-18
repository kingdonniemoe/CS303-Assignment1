
#include <iostream>

using namespace std;

struct UpdateResult
{
    int oldValue;
    int newValue;
};

// Search Function that accepts array of size 100 and a search value
int searchArray(int *arr, int size, int value);

UpdateResult updateArray(int *arr, int size, int index, int value);

int *addToEnd(int *arr, int size, int value);

int *deleteAtIndex(int* arr, int size, int index);

string displayMenu();