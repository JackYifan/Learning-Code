#include<stdio.h>
#include<string.h>
int main(){
    int n,m;
    char s[100][100];
    scanf("%d %d",&n,&m);
    getchar();
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
        getchar();
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n-1-i;j++){
            if(strcmp(s[j],s[j+1])>0){
                char t[100];
                strcpy(t,s[j]);
                strcpy(s[j],s[j+1]);
                strcpy(s[j+1],t);
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%s\n",s[i]);
    }

}