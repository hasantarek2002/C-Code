// A C++ Program to find length of the Longest Common
// Increasing Subsequence (LCIS)
#include<bits/stdc++.h>
using namespace std;

// find maximum length of LCIS of two given array
int LCIS(int arr1[], int n, int arr2[], int m)
{
    // table[j] is going to store length of LCIS
    // ending with arr2[j]. We initialize it as 0,
    int table[m];
    for (int j=0; j<m; j++)
        table[j] = 0;

    for (int i=0; i<n; i++)
    {
        int current = 0;
        for (int j=0; j<m; j++)
        {
            // If both the array have same elements.
            // Note that we don't break the loop here.
            if (arr1[i] == arr2[j])
                if (current + 1 > table[j])
                    table[j] = current + 1;

            /* Now seek for previous smaller common
               element for current element of arr1 */
            if (arr1[i] > arr2[j])
                if (table[j] > current)
                    current = table[j];
        }
    }
    int result = 0;
    for (int i=0; i<m; i++)
        if (table[i] > result)
           result = table[i];

    return result;
}

int main()
{
    int arr1[] = {3, 4, 9, 1};
    int arr2[] = {5, 3, 8, 9, 10, 2, 1};

    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);

    cout << "Length of LCIS is "
         << LCIS(arr1, n, arr2, m);
    return (0);
}
