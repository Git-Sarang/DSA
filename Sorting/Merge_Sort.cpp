#include <iostream>
using namespace std;
void merge_arr(int arr[], int start, int mid, int end) {
    int n1 = mid-start+1;
    int n2 = end-mid;
	int *a = new int[n1];
    int *b = new int[n2];
    for(int i=0; i<n1; i++) {
      a[i] = arr[start+i];
    }
    for(int j=0; j<n2; j++) {
      b[j] = arr[mid+1+j];
    }

    // mergeing the two arrays in main array. " k=start " is very imp. step.
    int i=0, j=0, k=start;
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
                arr[k] = a[i];
                i++;
        }else {
                arr[k] = b[j];
                j++;
        }
            k++;
    }
    while(i<n1)
      arr[k++] = a[i++];
    while(j<n2)
      arr[k++] = b[j++];
}

void mergesort(int arr[], int l, int h) {
    if(l>=h) return;
    int mid = l + (h-l)/2;
    mergesort(arr, l, mid);
    mergesort(arr, mid+1, h);

    merge_arr(arr, l, mid, h);
}
int main() {
    int n = 6;
    int arr[] = {4,6,2,1,3,5};
    mergesort(arr, 0, n-1);

    for(int i=0; i<n; i++) cout<<arr[i]<<endl;
    return 0;
}