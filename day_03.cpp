#include <iostream>
using namespace std;

//Function for repeating number
int duplicate_number(int n, int arr[])
{
    for (int i = 0; i < n; i++) {
        int j;
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j])
                return arr[i];
        }
    }
    return -1;
}

//Main Function
int main()
{
    int arr[] = {3, 1, 3, 4, 2};
    int n = sizeof(arr) / sizeof(int);
    cout << "The number in the array that is getting repeated: "<< endl<< duplicate_number(arr, n);
    return 0;
}
