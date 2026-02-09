// write the code for deletion the index 0 fron the given array . 
#include <iostream>
using namespace std;
#define SIZE 10
int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void deleteIndex0()
{
    for (int i = 1; i < SIZE; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[SIZE - 1] = 0; 
}

void display()
{
    cout << "Array elements: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    cout << "Before deletion:\n";
    display();

    deleteIndex0();

    cout << "After deletion of index 0:\n";
    display();

    return 0;
}