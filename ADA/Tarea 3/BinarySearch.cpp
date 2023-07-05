#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // Si el elemento está presente en el medio
        if (arr[mid] == target)
            return mid;

        // Si el elemento es más pequeño que el valor medio, buscar en la mitad izquierda del arreglo
        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);

        // Si el elemento es más grande que el valor medio, buscar en la mitad derecha del arreglo
        return binarySearch(arr, mid + 1, right, target);
    }

    // Si el elemento no está presente en el arreglo
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result == -1)
        cout << "El elemento no está presente en el arreglo." << endl;
    else
        cout << "El elemento está presente en el índice " << result << "." << endl;

    return 0;
}
