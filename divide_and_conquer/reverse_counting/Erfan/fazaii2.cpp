#include <iostream>
using namespace std;

int print_arr(int* arr, int len) {
    for (int i=0; i<len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int merge(long int* arr,long  int mid,long  int len) {
    // cout << "in merge\n\t";
    // print_arr(arr, len);
    long int left_index = 0;
    long int right_index = mid;
    long int sorted_index = 0;
    long int step = 0;
    long int* sorted = new long int[len];
    for(; left_index < mid && right_index < len; sorted_index++) {
        if(arr[left_index] < arr[right_index])
            sorted[sorted_index] = arr[left_index++];
        else {
            sorted[sorted_index] = arr[right_index++];
            step = ((step%1000000007 + mid%1000000007)%1000000007 - left_index%1000000007)%1000000007;
            // step = step %1000000007;
        }
    }
    while(left_index < mid)
        sorted[sorted_index++] = arr[left_index++];
    while(right_index < len)
        sorted[sorted_index++] = arr[right_index++];
    for(long int i = 0; i < len; i++)
        arr[i] = sorted[i];
    return step;
}

long int merge_sort(long int* arr,long  int len) {
    // cout << "merge_sort\n\t";
    // print_arr(arr, len);
    if(len == 1)
        return 0;
    long int mid = int(len/2);
    long int left_step = merge_sort(arr, mid);
    long int right_step = merge_sort(arr+mid, len-mid);
    long int merge_step = merge(arr, mid, len);
    // return (merge_step + right_step + left_step);
    return ((merge_step%1000000007 + right_step%1000000007)%1000000007 + left_step%1000000007)%1000000007;
}

int main() { 
    long int n;
    cin >> n;
    long int* a = new long  int[n];
    for(int i=0; i<n; i++)
        cin >> a[i];

    // print_arr(a, n);

    cout << merge_sort(a, n)%1000000007<< endl;

    // print_arr(a, n);
}