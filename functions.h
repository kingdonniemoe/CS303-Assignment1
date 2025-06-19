
#include <iostream>

using namespace std;

struct UpdateResult
{
    int oldValue;
    int newValue;
};

// Searches for a value
int searchArray(int *arr, int size, int value);
// Updates array and returns old/new value
UpdateResult updateArray(int *arr, int size, int index, int value);
//Appends to array
int *addToEnd(int *arr, int size, int value);
//Deletes element at index
int *deleteAtIndex(int* arr, int size, int index);
//Displays main menu
string displayMenu();