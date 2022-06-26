#include<bits/stdc++.h>
using namespace std;

int MCM(int arr[],int lb,int ub, vector<vector<int>> &t)
    {
        if (lb==ub) return 0;
        if (t[lb][ub]!=-1)
          return t[lb][ub];
        int mini=INT_MAX;
        for (int k=lb;k<=ub-1;k++)
        {
            int tempans=MCM(arr,lb,k,t)+MCM(arr,k+1,ub,t)+arr[lb-1]*arr[k]*arr[ub];
            mini=min(mini,tempans);
        }
        return t[lb][ub]=mini;
    }
int main()
{
    int n;
    cout<<"Enter the n:"<<endl;
    cin>>n;
    cout<<"Enter the n number in array:"<<endl;
    int arr[n];
    for (int i=0;i<n;i++)
       cin>>arr[i];
    vector<vector<int>> t(n,vector<int> (n,-1));
    cout<<"Minimum Number of Operations:"<<MCM(arr,1,n-1,t);
}
