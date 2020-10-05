#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    vector<int> v1,v2,v3;
    int x;
    scanf("%d",&x);
    while(x!=-1)
    {
        v1.push_back(x);
        scanf("%d",&x);
    }
    scanf("%d",&x);
    while(x!=-1)
    {
        v2.push_back(x);
        scanf("%d",&x);
    }
    // for(int i=0;i<v1.size();i++)
    // {
    //     for(int j=0;j<v2.size();j++)
    //     {
    //         if(v1[i]==v2[j])
    //         {
    //             v3.push_back(v1[i]);
    //         }
    //     }
    // }
    int i=0,j=0;
    while(i<v1.size()&&j<v2.size())
    {
        if(v1[i]<v2[j])
        {
            i++;
        }
        else if(v1[i]>v2[j])
        {
            j++;
        }
        else 
        {
            v3.push_back(v1[i]);
            i++;
            j++;
        }
            
    }
    if(v3.size()==0) printf("NULL");
    else 
    {
        for(int i=0;i<v3.size();i++)
        {
            printf("%d",v3[i]);
            if(i!=v3.size()-1) printf(" ");
        }
    }
}