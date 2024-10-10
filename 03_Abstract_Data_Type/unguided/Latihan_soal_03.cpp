#include <iostream>
using namespace std;

void tampilArray(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray(int arr1[3][3], int arr2[3][3], int x, int y)
{
    int temp = arr1[x][y];
    arr1[x][y] = arr2[x][y];
    arr2[x][y] = temp;
}

void tukarPointer(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int arr1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arr2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    cout << "Array 1 sebelum pertukaran:" << endl;
    tampilArray(arr1);
    cout << "Array 2 sebelum pertukaran:" << endl;
    tampilArray(arr2);

    tukarArray(arr1, arr2, 1, 1);

    cout << "\nArray 1 setelah pertukaran:" << endl;
    tampilArray(arr1);
    cout << "Array 2 setelah pertukaran:" << endl;
    tampilArray(arr2);

    int a = 10, b = 20;
    int *ptrA = &a;
    int *ptrB = &b;

    cout << "\nSebelum pertukaran pointer: a = " << *ptrA << ", b = " << *ptrB << endl;
    tukarPointer(ptrA, ptrB);
    cout << "Setelah pertukaran pointer: a = " << *ptrA << ", b = " << *ptrB << endl;

    return 0;
}