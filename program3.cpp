// WAP to create an array of all odd numbers from 1 to 50 and print them 
#include <iostream>
using namespace std;
int main () {
    int odd_n[25];
    int index = 0;
    for (int i=1; i<=50 ; i+=2)
     {
        odd_n[index] =i;
        index++;
    }
    cout << "Odd numbers 1 to 50 : " << endl;
    for (int j=0; j<25; j++) {
        cout << odd_n[j] << " "; 
    }
    return 0;
}