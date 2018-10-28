#include <iostream>
using namespace std;

int print_arr(int* arr, int len) {
    for (int i=0; i<len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int merge(int* arr, int mid, int len) {
    // cout << "in merge\n\t";
    // print_arr(arr, len);
    int left_index = 0;
    int right_index = mid;
    int sorted_index = 0;
    int step = 0;
    int* sorted = new int[len];
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
    for(int i = 0; i < len; i++)
        arr[i] = sorted[i];
    return step;
}

int merge_sort(int* arr, int len) {
    // cout << "merge_sort\n\t";
    // print_arr(arr, len);
    if(len == 1)
        return 0;
    int mid = int(len/2);
    int left_step = merge_sort(arr, mid);
    int right_step = merge_sort(arr+mid, len-mid);
    int merge_step = merge(arr, mid, len);
    // return (merge_step + right_step + left_step);
    return ((merge_step%1000000007 + right_step%1000000007)%1000000007 + left_step%1000000007)%1000000007;
}

int main() { 
    int n;
    cin >> n;
    int* a = new int[n];
    for(int i=0; i<n; i++)
        cin >> a[i];

    // print_arr(a, n);

    cout << merge_sort(a, n)%1000000007<< endl;

    // print_arr(a, n);
}