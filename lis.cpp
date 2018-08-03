/////Longest Increasing Subsequence

#include<bits/stdc++.h>

using namespace std;

int LIS( int arr[], int n )
{
    int i, j, max = 0;
    int lis[n];


    /* Initialize msis values for all indexes */
    for ( i = 0; i < n; i++ ){
        lis[i] = 1;
    }


    /* Compute maximum sum values in bottom up manner */
    for ( i = 1; i < n; i++ ){
        for ( j = 0; j < i; j++ ){
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1){
                lis[i] = lis[j] + 1;
            }
        }
    }

    /* Pick maximum of all lis values */
    for ( i = 0; i < n; i++ ){
        if ( max < lis[i] )
            max = lis[i];
    }



    return max;
}

int main()
{
    int arr[] = {1, 4, 2 ,4, 3};

    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Sum of maximum sum increasing subsequence is %d\n",
    LIS( arr, n ) );
    return 0;
}
