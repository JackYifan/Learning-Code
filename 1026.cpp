#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct person{
    int arrive,start,time;
    bool vip;
}tempperson;
struct tablenode{
    int end=8*3600,num;//什么时候空闲和服务的人数
    bool vip;
};
int viptable;
//两个向量人和桌
vector<person>player;
vector<tablenode>table;

bool cmp1(person a,person b){
    return a.arrive<b.arrive;
}
bool cmp2(person a,person b){
    return a.start<b.start;
}
//给personid的人分配tableid的桌子
void alloctable(int personid,int tableid){
    if(player[personid].arrive<=table[tableid].end){
        player[personid].start=table[tableid].end;
    }else{
        player[personid].start=player[personid].arrive;//来了就能开始打
    }
    table[tableid].end=player[personid].start+player[personid].time;
    table[tableid].num++;
}
//排在最前面的vip
int  findnextvip(int vipid){
    vipid++;
    while(player[vipid].vip==false&&vipid<player.size()) vipid++;
    return vipid;
}
int main()
{
    int n,m,k;
    cin>>n;
    for(int i=0;i<n;i++){
        int h,m,s,temptime,flag;
        scanf("%d:%d:%d %d %d",&h,&m,&s,&temptime,&flag);
        tempperson.arrive=h*3600+m*60+s;
        tempperson.start=21*3600;
        //如果超过关门时间直接跳过
        if(tempperson.arrive>=21*3600) continue;
        //使用时间是否需要压缩至2小时
        tempperson.time=temptime<=120?temptime*60:7200;
        tempperson.vip=flag==1?true:false ;
        player.push_back(tempperson);//先将数据处理好后放入vector中
    }
    cin>>k>>m;
    table.resize(k+1);
    //设置vip
    for(int i=0;i<m;i++){
        cin>>viptable;
        table[viptable].vip=true;
    }
    //对人排序
    sort(player.begin(),player.end(),cmp1);
    int vipid=-1;
    vipid=findnextvip(vipid);
    for(int i=0;i<player.size();){
        //每个人
        int index=-1,minendtime=9999999;
        //遍历桌子,找到最早空闲的桌子,id从小到大寻找
        for(int j=1;j<=k;j++){
            if(table[j].end<minendtime){
                minendtime=table[j].end;
                index=j;
            }
        }
        if(table[index].end>=21*3600) break;
        //在之前已经给这个vip分配过了
        if(player[i].vip==true&&i<vipid){
            i++;
            continue;
        }
        //最早空闲的是vip桌
        if(table[index].vip==true){
            if(player[i].vip==true){
                alloctable(i,index);
                if(vipid==i) vipid=findnextvip(vipid);//vipid永远是最前面的vip
                i++;
            }else{
                //有vip就让他先来
                if(vipid<player.size()&&player[vipid].arrive<=table[index].end){
                    alloctable(vipid,index);
                    vipid=findnextvip(vipid);
                }else{
                    //没有就让给普通人
                    alloctable(i,index);
                    i++;
                }
            }
        }else{
            if(player[i].vip==false){
                alloctable(i,index);
                i++;
            }else{
                //找最早结束的vip桌子
                int vipindex=-1,minvipendtime=9999999;
                for(int j=1;j<=k;j++){
                    if(table[j].vip==true&&table[j].end<minvipendtime){
                        minvipendtime=table[j].end;
                        vipindex=j;
                    }
                }
                if(vipindex!=-1&&player[i].arrive>=table[vipindex].end){
                    alloctable(i,viptable);
                    if(vipid==i) vipid=findnextvip(vipid);
                }else{
                    alloctable(i,index);
                    if(vipid==i) vipid=findnextvip(vipid);
                    i++;

                }
            }
        }
    }
    sort(player.begin(),player.end(),cmp2);
    for(int i=0;i<player.size()&&player[i].start<21*3600;i++){
        printf("%02d:%02d:%02d ",player[i].arrive/3600,player[i].arrive%3600/60,player[i].arrive%60);
        printf("%02d:%02d:%02d ",player[i].start/3600,player[i].start%3600/60,player[i].start%60);
        printf("%.0f\n",round((player[i].start-player[i].arrive)/60.0));
    }
    for(int i=1;i<=k;i++){
        if(i!=1) printf(" ");
        printf("%d",table[i].num);
    }
    return 0;
}