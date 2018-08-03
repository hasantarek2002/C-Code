#include<stdio.h>

/////////////finding maximum sum interval

int main()
{
    int n=15;
    int arr[]= {9,-3,1,7,-15,2,3,-4,2,-7,6,-2,8,4,-9};
    int sum=0,maxSum=-7887878;

    int i;
    for(i=0; i<n; i++)
    {
        if(sum > 0)
        {
            sum+=arr[i];
        }
        else
            sum=arr[i];
        if(sum>maxSum)
        {
            maxSum=sum;
        }
    }
    printf("%d\n",maxSum);
}



/*

n= number of elements
maxsum=-INF; INF=it's the element minimum of all posibles cases
sum=0;
for(int i=0;i<n;i++){
scanf("%d",&element);
if(sum>0){ sum+=element; }
else{ sum=element; }

if(sum>maxsum){maxsum=sum;}
}
maxsum it's the maximum sum!!!

*/
