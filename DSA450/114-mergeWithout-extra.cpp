#include <iostream>
using namespace std;
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
void merge(int arr1[], int arr2[], int n, int m) {
	int p1=0, p2=0, k=n-1;
	while(p1<=k && p2<m) {
	    if(arr1[p1] < arr2[p2]) {
	        p1++;
        } else {
	        swap(arr1[k], arr2[p2]);
	        k--;
	        p2++;
	    }
	}
	sort(arr1, arr1+n);
	sort(arr2, arr2+m);
}
int main() {
    int n=4, m=5;
    int a[] = {1,3,5,7};
    int b[] = {2,4,6,8,10};
    merge(a, b, 4, 5);

    for(auto x: a) cout<<x<<" ";
    for(auto x: b) cout<<x<<" ";
    return 0;
}