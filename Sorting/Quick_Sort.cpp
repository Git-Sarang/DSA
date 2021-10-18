#include <iostream>

void swap(int &a, int &b) {
    int tmp = a; a=b; b=tmp;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // take pivot as last element
    int k=low;
    //Don't include pivot in the loop as we are comparing to it
    for(int i=low; i<high; i++) {
        // moves element to left side if it's less than pivot
        if(arr[i] < pivot){
            swap(arr[i], arr[k]);
            k++;
        }
    }
    // finally puts pivot element to the left side and returns it's index
    swap(arr[k], arr[high]);
    return k;
}
void quickSort(int arr[], int low, int high) {
    if(low>=high) return;
    int part = partition(arr, low, high);

    // We do not include the pivot, so that it can backtrack
    quickSort(arr, low, part-1);
    quickSort(arr, part+1, high);
}
int main()
{   
    int n = 11;
    int a[] = {4, 1, 0, 8, 9, 2, 6, 3, 5, 7, -96};

    quickSort(a, 0, n-1);

    for(int i=0; i<n; i++) std::cout<<a[i]<<" ";
    return 0;
}
