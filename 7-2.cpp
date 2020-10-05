#include<stdio.h>
struct complex
{
    double x;
    double y;
};

int main()
{
	struct complex result,m,n;
    scanf("%lf %lf %lf %lf",&m.x,&m.y,&n.x,&n.y);
    result.x=m.x+n.x;
    result.y=m.y+n.y;
    printf("addition of complex is %.6f+%.6fi\n",result.x,result.y);
    result.x=(m.x*n.x-m.y*n.y); 
    result.y=(m.x*n.y+n.x*m.y);
    printf("product of complex is %.6f+%.6fi\n",result.x,result.y);
	
}
