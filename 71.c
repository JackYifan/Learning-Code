#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,m;
    int *a,*b;
    scanf("%d",&n);
    a=(int*)malloc((n+1)*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    b=(int*)malloc((m+1)*sizeof(int));
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    int cnt=0;
    int i,j;
    int tot=(n+m+1)/2;
    for(i=0,j=0;i<n&&j<m;){
        if(a[i]<b[j]){
            i++;cnt++;
            if(cnt>=tot) {
                printf("%d",a[i-1]);
                return 0;
            }
        }
        else if(a[i]>b[j]){
            j++;cnt++;
            if(cnt>=tot) {
                printf("%d",b[j-1]);
                return 0;
            }
        }
        else{
            cnt+=2;i++;j++;
            if(cnt>=tot) {
                printf("%d",a[i-1]);
                return 0;
            }
        }
        
    }
    while(i<n){
        i++;cnt++;
        if(cnt>=tot) {
            printf("%d",a[i-1]);
            return 0;
        }
    }
    while(j<m){
        j++;cnt++;
        if(cnt>=tot) {
            printf("%d",b[j-1]);
            return 0;
        }
    }
}