#include <iostream>

using namespace std;

//Array display after being sorted
void select_arr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<< arr[i]<<" ";
    }
}

//Sorting of the array with 0(n) complexity
void sort_arr(int arr[], int n){
    //Taking the count of the elements and creating an array out of scratch.
    int i, count_0=0, count_1=0, count_2=0;
    for(i=0; i<n; i++){
        switch(arr[i]){
            case 0:
            count_0++;
            break;
            case 1:
            count_1++;
            break;
            case 2:
            count_2++;
            break;
        }
    }
    i= 0;
    while (count_0 > 0){
        arr[i++]= 0;
        count_0--;
    }
    while(count_1 > 0){
        arr[i++]= 1;
        count_1--;
    }
    while(count_2 > 0){
        arr[i++]= 2;
        count_2--;
    }
    select_arr(arr, n);
}

//Main function. Array provided.
int main(){
    int arr[]= {0,1,2,1,0,2,1,0};
    int n= sizeof(arr)/sizeof(int);
    sort_arr(arr, n);
    return 0;
}