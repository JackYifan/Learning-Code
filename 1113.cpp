#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    sort(v.begin(),v.end());
    int min=0;
    for(int i=0;i<n/2;i++)
    {
        min+=v[i];
    }
    cout<<n%2<<" "<<sum-2*min;
}