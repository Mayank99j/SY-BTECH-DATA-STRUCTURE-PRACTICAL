#include <iostream>
using namespace std;

int main() {
    int n, pos, value;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];   // assuming max size 100

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter position to insert (1 to " << n + 1 << "): ";
    cin >> pos;

    cout << "Enter value to insert: ";
    cin >> value;

    // Check valid position
    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position!";
        return 0;
    }

    // Shift elements to the right
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert value
    arr[pos - 1] = value;
    n++;

    cout << "Array after insertion:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}