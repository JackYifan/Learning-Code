#include<cstdio>
#include<queue>
using namespace std;
int pixel[1290][130][61];
bool inq[1290][130][61]={false};
//操作
int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};
struct node
{
    int x,y,z;
}Node;
int n,m,slice,T;
bool judge(int x,int y,int z)
{
    //判断边界
    if(x>=n||x<0||y>=m||y<0||z>=slice||z<0) return false;
    //判断是否如果队列
    if(inq[x][y][z]==true||pixel[x][y][z]==0) return false;
    return true;
    
}
int BFS(int x,int y,int z)
{
    int tot=0;
    queue<node>q;
    //处理以(x,y,z)为中心的块
    Node.x=x;
    Node.y=y;
    Node.z=z;
    //队列初始化
    q.push(Node);
    inq[x][y][z]=true;
    while(!q.empty())
    {
        node top=q.front();
        q.pop();
        tot++;
        //向外扩展一格
        for(int i=0;i<6;i++)
        {
            //新的坐标
            int newx=top.x+X[i];
            int newy=top.y+Y[i];
            int newz=top.z+Z[i];
            //如果向外扩展的一格的坐标是符合条件的就进队列
            if(judge(newx,newy,newz)==true)
            {
                Node.x=newx;
                Node.y=newy;
                Node.z=newz;
                q.push(Node);
                inq[newx][newy][newz]=true;
            }
        }
    }
    if(tot>=T) return tot;
    else return 0;
}
int main()
{
   
    scanf("%d%d%d%d",&n,&m,&slice,&T);
    for(int z=0;z<slice;z++)
    {
        for(int x=0;x<n;x++)
        {
            for(int y=0;y<m;y++)
            {
                scanf("%d",&pixel[x][y][z]);
            }
        }
    }
    int ans=0;
    for(int z=0;z<slice;z++)
    {
        for(int x=0;x<n;x++)
        {
            for(int y=0;y<m;y++)
            {
                if(pixel[x][y][z]==1&&inq[x][y][z]==false)
                {
                    ans+=BFS(x,y,z);
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}