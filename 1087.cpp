#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<vector>
using namespace std;
map<int, string>numToStr;
map<string, int>strToNum;
const int maxn = 500;
vector<int>pre[maxn];
int G[maxn][maxn];
int hp[maxn];
string citystart;
int n, m;
int d[maxn];
int c[maxn];
bool visit[maxn] = { false };
const int inf = 1000000000;
void Dijkstra()
{
    fill(d, d + maxn, inf);
    d[0] = 0;
    for (int j = 0; j < n; j++)
    {
        int min = inf;
        int u = -1;
        for (int i = 0; i < n; i++)
        {
            if (visit[i] == false && d[i] < min)
            {
                min = d[i];
                u = i;
            }
        }
        if (u == -1) return;
        visit[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (visit[v] == false && G[u][v] != inf)
            {
                if (d[u] + G[u][v] < d[v])
                {
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (d[u] + G[u][v] == d[v])
                {
                    pre[v].push_back(u);
                }
            }
        }

    }
}
vector<int>temp, path;
double anshp, ansavg;
int numpath=0;
void DFS(int v)
{
    if (v == 0)
    {
        numpath++;
        temp.push_back(v);
        double temphp = 0, tempavg = 0;
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            temphp += hp[temp[i]];
            tempavg += 1.0 * hp[temp[i]] / (temp.size()-1);
        }
        if (temphp > anshp)
        {
            anshp = temphp;
            ansavg = tempavg;
            path = temp;
        }
        else if (temphp == anshp)
        {
            if (tempavg > ansavg)
            {
                ansavg = tempavg;
                path = temp;
            }
        }
        temp.pop_back();
        return;
    }
    temp.push_back(v);
    for (int i = 0; i < pre[v].size(); i++)
    {
        DFS(pre[v][i]);
    }
    temp.pop_back();
}
int main()
{
    fill(G[0], G[0] + maxn * maxn, inf);
    cin >> n >> m >> citystart;
    strToNum[citystart] = 0;
    numToStr[0] = citystart;
    for (int i = 1; i < n; i++)
    {
        string city;
        int hap;
        cin >> city >> hap;
        strToNum[city] = i;
        numToStr[i] = city;
        hp[i] = hap;
    }
    for (int i = 0; i < m; i++)
    {
        int cost;
        string city1, city2;
        cin >> city1 >> city2 >> cost;
        int x = strToNum[city1];
        int y = strToNum[city2];
        G[x][y] = G[y][x] = cost;
    }
    Dijkstra();
    int v = strToNum["ROM"];
    DFS(v);
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<pre[i].size();i++)
    //     {
    //         cout<<pre[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout << numpath << " " << d[v] << " " << (int)anshp << " " << (int)ansavg << endl;
    //printf("%.0f\n",ansavg);
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << numToStr[path[i]];
        if (i > 0)
        {
            cout << "->";
        }
    }

}