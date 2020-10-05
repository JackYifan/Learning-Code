#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int n;
int pos[maxn];

int main()
{

    scanf("%d", &n);
    int left = n - 1;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        pos[x] = i;
        if (pos[x] == x && x != 0) left--;
    }
    int cnt = 0;

    int i = 1;
    while (left>0)
    {
        while (pos[0] != 0)
        {
            swap(pos[0], pos[pos[0]]);
            //int x = pos[pos[0]];//2
            //int y = pos[0];//7
            //pos[y] = y;
            //pos[0] = x;
            cnt++;
            left--;
        }
        if (pos[0] == 0) {
            for (; i < n;i++ )
            {
                if (pos[i] != i)
                {
                    swap(pos[i], pos[0]);
                    cnt++;
                    break;
                }
            }
        }
    }

    printf("%d", cnt);



}