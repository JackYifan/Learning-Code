#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char str[10];
char map[10][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char wei[5][5]={"Shi","Bai","Qian","Wan","Yi"};
void printduan(int& left,int& right,int& n)
{
    bool flag=false ;
    bool hasprint=false;
    int cnt=right-left-1;
    while(left<right)
    {
        if(str[left]=='0')
        {
            flag=true;
            left++;
            cnt--;
        }
        else
        {
            if(left==0)
            {
                printf("%s %s",map[str[left++]-'0'],wei[cnt--]);
            }
            else 
            {
                if(flag==true) 
                {
                    printf(" ling");
                    flag=false;
                }
                printf(" %s %s",map[str[left++]-'0'],wei[cnt--]);
            }
            hasprint=true;
        }
    }
    if(left==right) 
    {
        if(str[left]=='0'&&left==0)
        {
            printf("ling");
        }
        else if(str[left]!='0')
        {
            if(flag==true) printf(" ling");
            if(left==0) printf("%s",map[str[right]-'0']);
            else printf(" %s",map[str[right]-'0']);
            hasprint=true;
        }
    }
    
    if(hasprint) 
    {
        if(n==3) printf(" Yi");
        else if(n==2) printf(" Wan");
    }
}
int main()
{
    cin.getline(str,11);
    int len=strlen(str);
    int left=0;
    int right=len-1;
    if(str[left]=='-') 
    {
        printf("Fu");
        left++;
    }
    int duanshu=1;
    while(left+4<=right)
    {
        right-=4;
        duanshu++;
    }
    while(left<len)
    {
        printduan(left,right,duanshu);
        left=left+1;
        right=right+4;
        duanshu--;
    }
}