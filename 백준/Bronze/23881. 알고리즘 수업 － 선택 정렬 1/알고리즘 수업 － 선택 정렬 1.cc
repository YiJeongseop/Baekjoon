#include <iostream>
using namespace std;

int main()
{
    int a, k;
    cin >> a >> k;

    int* array = new int[a]; // 동적할당
    int temp;

    for (int i = 0; i < a; i++) {
        cin >> temp;
        array[i] = temp;
    }

    int count = 0;
    for (int i = a - 1; i > -1; i--) {
        int biggest = array[0];
        temp = 0;
        for (int j = 0; j < i + 1; j++) {
            if (biggest < array[j]) {
                biggest = array[j];
                temp = j;
            }
            if (j == i) {
                if (array[j] != biggest) {
                    swap(array[j], array[temp]);
                    //cout << array[j] << " " << array[temp] << endl;
                    count++;
                    if (count == k) {
                        cout << array[temp] << " " << array[j];
                    }
                }
            }
        }
    }

    if (count < k) {
        cout << -1;
    }

    delete array; // 해제

    return 0;
}
