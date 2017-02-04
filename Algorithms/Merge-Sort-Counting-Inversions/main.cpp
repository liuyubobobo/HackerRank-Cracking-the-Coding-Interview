/// Source: https://www.hackerrank.com/challenges/ctci-merge-sort
/// Author: liuyubobobo
/// Time:   2017-02-04

#include <iostream>

using namespace std;


/// Using merge method to merge arr[l...mid] and arr[mid+1...r]
/// During the merge process,
/// we can calculate the inversion number in arr[l...r]
/// Return the inversion number in arr[l...r]
long long __merge( int arr[], int l, int mid, int r){

    int aux[r-l+1];
    for( int i = l ; i <= r ; i ++ )
        aux[i-l] = arr[i];

    long long res = 0;
    int j = l, k = mid + 1;
    for( int i = l ; i <= r ; i ++ ){
        if( j > mid ){
            arr[i] = aux[k-l];
            k ++;
        }
        else if( k > r ){
            arr[i] = aux[j-l];
            j ++;
        }
        else if( aux[j-l] <= aux[k-l] ){
            arr[i] = aux[j-l];
            j ++;
        }
        else{   // aux[j-l] > aux[k-l]
            arr[i] = aux[k-l];
            k ++;
            // in this case, all the elements in arr[j...mid]
            // form inversion number-pair with arr[i]
            res += (mid - j + 1);
        }
    }

    return res;
}

long long __inversionCount(int arr[], int l, int r){

    if( l >= r )
        return 0;

    int mid = l + (r-l)/2;

    long long res1 = __inversionCount( arr, l, mid);
    long long res2 = __inversionCount( arr, mid+1, r);

    return res1 + res2 + __merge( arr, l, mid, r);
}

long long inversionCount(int arr[], int n){

    return __inversionCount(arr, 0, n-1);
}

int main() {

    int d, n;

    cin>>d;
    while( d -- ){

        int n;
        cin>>n;

        int *arr = new int[n];

        for( int i = 0 ;  i < n ; i ++ )
            cin>>arr[i];

        cout<<inversionCount( arr , n )<<endl;

        delete[] arr;
    }

    return 0;
}