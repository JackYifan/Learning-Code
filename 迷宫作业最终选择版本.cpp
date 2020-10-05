#include<stdio.h>
#define MAXN 25
int nextStep[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int n;
int map[MAXN][MAXN];
bool visit[MAXN][MAXN];
int path[MAXN*MAXN][2];  //存放路线 
int last = 0;  //栈顶 
int cnt = 1;//找到解的累加器
void printPath() {
	printf("第%d条路线：", cnt++);//找到一组解累加一次
	for (int i = 0; i <= last; i++) {
		if (i < last) printf("%d,%d -> ", path[i][0], path[i][1]);
		else printf("%d,%d  ", path[i][0], path[i][1]);
	}
	printf("\n");
}
/*
函数作用：试探迷宫的所有路线
函数参数：人当前的位置X,Y
无返回值
*/
void findPath(int x, int y) {
	if (x == n - 2 && y == n - 2) {
		//如果走到出口，打印出迷宫的当前解  
		printPath();
	}
	else {           	//下右上左依次试探
		int next_x, next_y;
		for (int i = 0; i < 4; i++) {
			next_x = x + nextStep[i][0];
			next_y = y + nextStep[i][1];
			//如果该方向能走且没走过
			if (map[next_x][next_y] && !visit[next_x][next_y]) {   
				//访问该点
				visit[next_x][next_y] = true;
				last++;
				path[last][0] = next_x;
				path[last][1] = next_y;
				//递归下一个点
				findPath(next_x, next_y);
				//回溯
				visit[next_x][next_y] = false;
				last--;    //出栈 
			}
		}

	}

}
void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}
int main(void) {
	scanf("%d", &n);
	init();
	path[0][0] = 1;
	path[0][1] = 1; //入口（1,1）先入栈 
	map[1][1] = 0;
	findPath(1, 1);
}
