#include <fstream>
#include "functions.h"

using namespace std;

int main()
{
    ifstream inFile("A1input.txt");

    int size = 100;
    int *arr1 = new int[size];
    int value, i = 0;

    while (inFile >> value)
    {
        arr1[i] = value;
        i++;
    }

    while (true)
    {
        string userChoice = displayMenu();

        if (userChoice == "5")
        {
            cout << "Exiting...\n";
            break;
        }

        if (userChoice == "1")
        {
            int searchParam;
            cout << "Enter the number you want to search for: ";
            cin >> searchParam;

            int result = searchArray(arr1, size, searchParam);

            if (result != -1)
            {
                cout << "\nThe number " << searchParam << " was found at index position " << result << "\n\n";
            }
            else
            {
                cout << "\nThe number " << searchParam << " was not found.\n\n";
            }
        }
        else if (userChoice == "2")
        {
            try
            {

                int index, value;
                cout << "Enter the index you want to update: ";
                cin >> index;

                if (!cin)
                {
                    throw runtime_error("Input error: Please enter digits only.\n");
                }

                cout << "Enter the updated value: ";
                cin >> value;

                if (!cin)
                {
                    throw runtime_error("Input error: Please enter digits only.\n");
                }

                cout << endl;

                UpdateResult result = updateArray(arr1, size, index, value);

                cout << "Old value: " << result.oldValue << endl;
                cout << "New value: " << result.newValue << endl;
            }
            catch (runtime_error &e)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << e.what() << "\n\n";
            }
            catch (out_of_range &e)
            {
                cout << "Error: " << e.what() << "\n\n";
            }
        }
        else if (userChoice == "3")
        {
            try
            {

                int value;
                cout << "Enter the value you want to add to the array: ";
                cin >> value;

                if (!cin)
                {
                    throw runtime_error("Input error: Please enter digits only.\n");
                }

                arr1 = addToEnd(arr1, size, value);
                size++;

                cout << "\n"
                     << value << " added to the end of the array.\n";
            }
            catch (runtime_error &e)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << e.what() << "\n\n";
            }
        }
        else if (userChoice == "4")
        {
            int index;
            cout << "Enter the index you want to delete from the array: ";
            cin >> index;

            arr1 = deleteAtIndex(arr1, size, index);
            size--;

            cout << "\n";
            cout << "Position " << index << " removed from the array.\n";
        }
    }

    delete[] arr1;
}