#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
struct node{
    string name;
    int status,month,day,hour,minute,time;
};
bool cmp(node a,node b){
    return a.name!=b.name?a.name<b.name:a.time<b.time;
}
//rate[24]记录了一天要多少钱
double billFromZero(node call,int rate[]){
    double tot=rate[call.hour]*call.minute+rate[24]*60*call.day;
    for(int i=0;i<call.hour;i++){
        tot+=rate[i]*60;
    }
    return tot/100.0;
}
int main()
{
    int n;
    int rate[25]={0};
    for(int i=0;i<24;i++){
        cin>>rate[i];
        rate[24]+=rate[i];
    }
    cin>>n;
    vector<node>data(n);
    for(int i=0;i<n;i++){
        cin>>data[i].name;
        scanf("%d:%d:%d:%d",&data[i].month,&data[i].day,&data[i].hour,&data[i].minute);
        string temp;
        cin>>temp;
        data[i].status=(temp=="on-line")?1:0;
        data[i].time=data[i].day*24*60+data[i].hour*60+data[i].minute;
    }
    sort(data.begin(),data.end(),cmp);
    //每一个用户得到一个向量node，话费清单
    map<string,vector<node> >custom;
    for(int i=1;i<n;i++){
        if(data[i].name==data[i-1].name
        &&data[i-1].status==1&&data[i].status==0){
            custom[data[i-1].name].push_back(data[i-1]);
            custom[data[i].name].push_back(data[i]);
        }
    }
    //对每一个用户进行处理
    for(auto it:custom){
        vector<node>temp=it.second;
        cout<<it.first;
        printf(" %02d\n",temp[0].month);
        double tot=0.0;
        //遍历结束时间
        for(int i=1;i<temp.size();i+=2){
            double t=billFromZero(temp[i],rate)-billFromZero(temp[i-1],rate);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n"
            ,temp[i-1].day,temp[i-1].hour,temp[i-1].minute
            ,temp[i].day,temp[i].hour,temp[i].minute
            ,temp[i].time-temp[i-1].time,t);
            tot+=t;
        }
        printf("Total amount: $%.2f\n",tot);
    }
    return 0;

}