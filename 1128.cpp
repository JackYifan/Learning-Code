#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        vector<int>v(k);
        bool res=true;
        for(int j=0;j<k;j++){
            cin>>v[j];
            for(int ii=0;ii<j;ii++){
                if(v[j]==v[ii]||abs(v[j]-v[ii])==abs(j-ii)) {
                    res=false;
                    break;  
                }
            }
        }
        cout<<(res==true?"YES\n":"NO\n");
    }
}