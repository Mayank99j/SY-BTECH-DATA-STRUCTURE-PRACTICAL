// wap to find the sum of all the elements in the array , consider the size of the rray be 10 . 
#include <iostream>
using namespace std;
int main() {
    int arr[10]= {1,2,3,4,5,6,7,8,9,10};
    int sum = 0;

    for (int i = 0; i < 10; i++) {
        sum += arr[i];
    }

    cout << "The sum of all elements: " << sum << endl;

    return 0;
}
