#include <iostream>
using namespace std;

int main()
{
    int a, k;
    cin >> a >> k;

    int* array = new int[a]; 
    int temp;

    for (int i = 0; i < a; i++) {
        cin >> temp;
        array[i] = temp;
    }

    int count = 0;
    bool endflag = 0;
    for (int i = a - 1; i > -1; i--) {
        int biggest = 0;
        for (int j = 0; j < i + 1; j++) {
            biggest = array[biggest] < array[j] ? j : biggest;
            if (j == i) {
                if (array[j] != array[biggest]) {
                    swap(array[j], array[biggest]);
                    count++;
                    if (count == k) {
                        endflag = 1;
                        for (int k = 0; k < a; k++) {
                            cout << array[k] << " ";
                        }
                        break;
                    }
                }
            }
        }
        if (endflag) {
            break;
        }
    }

    if (count < k) {
        cout << -1;
    }

    delete array;

    return 0;
}
