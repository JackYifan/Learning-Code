#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node
{
    /* data */
    char name[30];
    int month;
    int day;
    int hour;
    int minute;
    bool flag;
}node[1010];
int cost[25];
int n;
bool cmp(Node a,Node b)
{
    if(strcmp(a.name,b.name)!=0) return strcmp(a.name,b.name)<0;
    else if(a.month!=b.month) return a.month<b.month; 
    else if(a.day!=b.day) return a.day<b.day;
    else if(a.hour!=b.hour) return a.hour<b.hour;
    else return a.minute<b.minute;
}
int main()
{
    for(int i=0;i<24;i++)
    {
        scanf("%d",&cost[i]);
    }
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        char temp[10];
        scanf("%s %d:%d:%d:%d %s",node[i].name,&node[i].month,&node[i].day,&node[i].hour,&node[i].minute,temp);
        if(strcmp(temp,"on-line")==0) node[i].flag=true;
        else node[i].flag=false;
        getchar();
    }
    sort(node,node+n,cmp);
    char temp[20]="";
    int flag=0;
    for(int i=0;i<n;i++)
    {
        printf("%s %02d\n",node[i].name,node[i].month);
        strcpy(temp,node[i].name);
        double tot=0;
        while(strcmp(temp,node[i].name)==0)
        {
            if(node[i].flag==true&&node[i+1].flag==false&&i<n-1)
            {
                printf("%02d:%02d:%02d ",node[i].day,node[i].hour,node[i].minute);
                int start=node[i].day*24*60+node[i].hour*60+node[i].minute;
                printf("%02d:%02d:%02d ",node[i+1].day,node[i+1].hour,node[i+1].minute);
                int end=node[i+1].day*24*60+node[i+1].hour*60+node[i+1].minute;
                int time=end-start;
                printf("%d",time);
                double money=0;
                
                money+=cost[node[i].hour]*(60-node[i].minute);
                if(node[i].day==node[i+1].day)
                {
                    for(int j=node[i].hour+1;j<node[i+1].hour;j++)
                    {
                        money+=cost[j]*60;
                    }
                }
                else 
                {
                    for(int j=node[i].hour+1;j<=23;j++)
                    {
                        money+=cost[j]*60;
                    }
                    int day=node[i+1].day-node[i].day-1;
                    
                    int temp=0;
                    for(int i=0;i<=23;i++)
                    {
                        temp+=cost[i]*60;
                    }
                    money+=temp*day;
                    
                    for(int j=0;j<node[i+1].hour;j++)
                    {
                        money+=cost[j]*60;
                    }
                }
                money+=cost[node[i+1].hour]*node[i+1].minute;
                money=money*1.0/100;
                tot+=money;
                printf(" $%.2f\n",money);
            }
            
            i++;
        }
        printf("Total amount: $%.2f\n",tot);
        i--;
        
    }

}