#include <iostream>
using namespace std;

int max_Water(int arr[], int n)
{ 
    int left = 0;
    int right = n-1;
    
    // Two pointers for left and right sides
    int l_max = 0;
    int r_max = 0;
 
    int result = 0;
    while (left <= right)
    {
      if(r_max <= l_max)
      {
        result += max(0, r_max-arr[right]);
 
        // Updating right max
        r_max = max(r_max, arr[right]);
 
        // Updating right pointer
        right -= 1;
      }
      
      else
      { 
        result += max(0, l_max-arr[left]);
 
        // Updating left max
        l_max = max(l_max, arr[left]);
 
        // Updating left pointer
        left += 1;
      }
    }
    return result;
}

// Main Function
int main() {
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr)/sizeof(int);
    cout << "Units of water trapped inside the bars: "<<max_Water(arr, n) << endl;
    return 0;
}
