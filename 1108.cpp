#include<cstdio>
#include<cstring>
int main()
{
    int n;
    char a[100],b[100];
    scanf("%d",&n);
    double sum=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        scanf("%s",a);
        double temp;
        sscanf(a,"%lf",&temp);
        sprintf(b,"%.2f",temp);
        bool flag=false ;
        int len=strlen(a);
        for(int i=0;i<len;i++)
        {
            if(a[i]!=b[i]) 
            {
                flag=true;
                break;
            }
        }
        if(flag||temp<-1000||temp>1000)
        {
            printf("ERROR: %s is not a legal number\n",a);
            continue;
        }
        else
        {
            sum+=temp;
            cnt++;
        }
    }
    if(cnt==1)
    {
        printf("The average of 1 number is %.2f\n",sum);
    }
    else if(cnt>1)
    {
        printf("The average of %d numbers is %.2f\n",cnt,sum/cnt);
    }
    else 
    {
        printf("The average of 0 numbers is Undefined\n");
    }
}
/*
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38

*/