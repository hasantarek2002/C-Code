
#include <bits/stdc++.h>
using namespace std;

int block;
int cnt[1000005];

struct Query
{
    int L, R;
};
bool compare(Query x, Query y)
{
    if (x.L/block != y.L/block)
        return x.L/block < y.L/block;
    return x.R < y.R;
}
int distinct=0;

void queryResults(int a[], int n, Query q[], int m)
{
    block = (int)sqrt(n);
    sort(q, q + m, compare);
    int prevL = 0, prevR = 0;
    int currSum = 0;
    memset(cnt,0,sizeof(cnt));

    for (int i=0; i<m; i++)
    {

        int currL = q[i].L, currR = q[i].R;
        while (prevL < currL)
        {
            cnt[a[prevL]]--;
            if(cnt[a[prevL]]==0)  distinct++;
            //currSum -= a[prevL];
            prevL++;
        }

        // Add Elements of current Range
        while (prevL > currL)
        {
            cnt[a[prevL-1]]++;
            if(cnt[a[prevL-1]]==1)  distinct++;
            //currSum += a[prevL-1];
            prevL--;
        }
        while (prevR <= currR)
        {
            cnt[a[prevR]]++;
            if(cnt[a[prevR]]==1)  distinct++;
            //currSum += a[prevR];
            prevR++;
        }

        // Remove elements of previous range.  For example
        // when previous range is [0, 10] and current range
        // is [3, 8], then a[9] and a[10] are subtracted
        while (prevR > currR+1)
        {
            cnt[a[prevR-1]]--;
            if(cnt[a[prevR-1]]==0)  distinct++;
            //currSum -= a[prevR-1];
            prevR--;
        }

        // Print sum of current range
        cout << "Distinct value of [" << currL << ", " << currR
             << "] is "  << distinct << endl;
    }
}

// Driver program
int main()
{

    int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
    int n = sizeof(a)/sizeof(a[0]);
    Query q[] = {{0, 4}, {1, 3}, {2, 4}};       // 3 2 3
    //Query q[] = {{0, 1}, {1, 4}, {3, 5}};
    int m = sizeof(q)/sizeof(q[0]);
    queryResults(a, n, q, m);
    return 0;
}

