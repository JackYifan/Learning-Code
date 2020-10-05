#include<iostream>
#include <string.h>
using namespace std;

struct node{
	int x;
	int y;
}s[101];
	
bool visited[101];
int flag = 0;
//到达边缘
bool border(int i, int D){
	if(s[i].x<= D - 50 || s[i].x >= 50 - D || s[i].y<= D - 50 || s[i].y >= 50 - D)  return 1;
	else return 0;
}

int first(int i , int D)
{
    if(s[i].x*s[i].x + s[i].y*s[i].y <= (D+7.5)*(D+7.5)) 
        return 1;
    else return 0;
}
//能跳到的范围
int dist(int i, int j , int D){
	if((s[i].x - s[j].x)*(s[i].x - s[j].x) + (s[i].y - s[j].y)*(s[i].y - s[j].y) <= D*D)
    return 1;
    else return 0;
}

int selectdots(int t,int N , int D ){

	visited[t] = 1;
    //判断t是否为递归出口
	if(border(t , D) == 1){
		flag = 1;
	}
    //遍历所有的点，没有到达过且可以到达的递归
	for(int i = 0; i<N ; i++){
		if(!visited[i]&& dist(t , i , D)){
			flag = selectdots(i , N , D );
		}
	}
	return flag;
}

int main(){
	int N , D ;
	cin>>N>>D;
	for(int i=0 ; i<N ;i++){
		cin>>s[i].x>>s[i].y; 
	}
    memset(visited,0,sizeof(visited));
		
	if(D >= 42.5)
    {
        cout << "Yes";
    }
    else
    {
        for(int i=0;i<N;i++)
        {
            if(!visited[i]&&first(i , D))
            {
                selectdots(i , N , D);
            }
        }
        if(flag == 1)
          cout <<"Yes";
        else
          cout <<"No";
    }
    return 0;
}
