#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int tot[110];
struct Node
{
    int id;
    int ge, gi, sum;
    int zhiyuan[6];
    int rank;
    /* data */
}node[40010];
vector<int>v[110];
bool cmp(Node a, Node b)
{
    if (a.sum != b.sum) return a.sum > b.sum;
    else return a.ge > b.ge;
}
bool cmp1(int x, int y)
{
    return node[x].id < node[y].id;
}
int main()
{
    int n, m, zhiyuanshu;
    scanf("%d%d%d", &n, &m, &zhiyuanshu);
    for (int i = 0; i < n; i++)
    {
        node[i].id = i;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &tot[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &node[i].ge, &node[i].gi);
        node[i].sum = node[i].ge + node[i].gi;
        for (int j = 0; j < zhiyuanshu; j++)
        {
            scanf("%d", &node[i].zhiyuan[j]);
        }
    }
    sort(node, node + n, cmp);
    node[0].rank = 0;
    for (int i = 1; i < n; i++)
    {
        if (node[i].sum == node[i - 1].sum && node[i].ge == node[i - 1].ge) node[i].rank = node[i - 1].rank;
        else node[i].rank = i;
    }
    //i为排序后，并不是id 
    for (int i = 0; i < n; i++)
    {
        //printf("%d ",node[i].id);
        //对于每一个学生遍历其每一个志愿
        for (int j = 0; j < zhiyuanshu; j++)
        {
            int schoolid = node[i].zhiyuan[j];
            if (tot[schoolid] > 0)
            {
                v[schoolid].push_back(i);
                tot[schoolid]--;
                break;
            }
            else
            {
                if (v[schoolid].size() > 0)
                {
                    int laststuid = v[schoolid].back();
                    if (node[laststuid].rank == node[i].rank)
                    {
                        v[schoolid].push_back(i);
                        break;
                    }
                }

            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (v[i].size() == 0) printf("\n");
        sort(v[i].begin(), v[i].end(), cmp1);
        for (int j = 0; j < v[i].size(); j++)
        {
            printf("%d", node[v[i][j]].id);
            if (j < v[i].size() - 1) printf(" ");
            else printf("\n");
        }
    }
    

}