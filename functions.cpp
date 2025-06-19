#include "functions.h"

//Linear Search: returns index of found vale or -1
int searchArray(int *arr, int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
};
// Update array at given index, return old and new values
UpdateResult updateArray(int *arr, int size, int index, int value)
{
    if (index < 0 || index >= size)
    {
        throw out_of_range("Index is out of range.");
    }

    UpdateResult result;
    result.oldValue = arr[index];
    arr[index] = value;
    result.newValue = arr[index];
    return result;
}
// Add a new element to the end of array
int *addToEnd(int *arr, int size, int value)
{
    int *arr2 = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        arr2[i] = arr[i];
    }
    arr2[size] = value;

    delete[] arr;
    return arr2;
}

//Delete an element at a specified index
int *deleteAtIndex(int *arr, int size, int index)
{
    int *arr2 = new int[size - 1];
    for (int i = 0, j = 0; i < size; i++)
    {
        if (i == index)
            continue;

        arr2[j] = arr[i];
        j++;
    }

    delete[] arr;
    return arr2;
}

// Show menu and get user selection
string displayMenu()
{

    string userInput;

    while (true)
    {
        cout << "\tMain Menu\n";
        cout << "1. Search Array\n";
        cout << "2. Update Array\n";
        cout << "3. Add to End of Array\n";
        cout << "4. Delete from Array\n";
        cout << "5. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> userInput;
        cout << "\n";

        if (userInput == "1" || userInput == "2" || userInput == "3" || userInput == "4" || userInput == "5")
        {
            return userInput;
        }
        else
        {
            cout << "Invalid Selection. Please enter a digit from 1 to 5.\n\n";
        }
    }
}