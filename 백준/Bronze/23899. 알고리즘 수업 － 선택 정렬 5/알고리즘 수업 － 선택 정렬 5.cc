#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int* array = new int[n]; 
    int* array2 = new int[n];
    int temp;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        array[i] = temp;
    }

    for (int i = 0; i < n; i++) {
        cin >> temp;
        array2[i] = temp;
    }

    bool flag = 0;
    for (int i = 0; i < n; i++) {
        if (equal(array, array + n, array2)) {
            cout << 1;
            flag = 1;
            break;
        }
        int* max = max_element(array, array + n - i);
        int max_index = max - array;
        if (max_index != n - 1 - i) {
            swap(array[max_index], array[n - 1 - i]);
        }
    }

    if (flag == 0) {
        cout << 0;
    }

    delete array, array2;

    return 0;
}
