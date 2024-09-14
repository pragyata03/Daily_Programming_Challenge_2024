#include <iostream>

using namespace std;

void find_Leaders(int arr[], int n)
{
    cout<<"The leaders are: ";
    /*Rightmost is the leader*/
    int max_element_right =  arr[n-1];
    cout << max_element_right << " ";
    
    for (int i = n-2; i >= 0; i--)
    {
        if (max_element_right < arr[i]) 
        {           
            max_element_right = arr[i];
            //Printing the Leaders
            cout << max_element_right << " ";
        }
    }    
}

//Main Function
int main()
{
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr)/sizeof(int);
    find_Leaders(arr, n);
    return 0;
}    
