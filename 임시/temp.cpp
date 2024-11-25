#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num;

    cin >> num;

    int a = 0, b = num;

    do {
        b /= 10;
        a++;
    } while (b != 0);

    int arr[a];

    for (int i = 0; i < a; i++) {
        arr[i] = num % 10;
        num /= 10;
    }

    sort(arr, arr + a, greater<int>());

    for (int i = 0; i < a; i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}