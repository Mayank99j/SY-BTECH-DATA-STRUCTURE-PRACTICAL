// WAP to create  of an array containing square of elements of the given array . 
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int square_arr[10];

        for (int i = 0; i < 10; i++)
         {
            square_arr[i] = arr[i] * arr[i];
    }

       cout << "Array of squares: ";
            for (int j = 0; j < 10; j++) 
            {
              cout << square_arr[j] << " ";
    }
    cout << endl;
    return 0;
}