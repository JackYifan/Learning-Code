#include<cstdio>
#include<cstring>
struct Student
{
    char name[20];
    char gender;
    char id[20];
    int grade;
    bool flag;
}stu[20];

int main()
{
    Student bestgirl;
    bestgirl.grade=0;
    bestgirl.flag=false;
    Student worstboy;
    worstboy.grade=100;
    worstboy.flag=false;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        
        getchar();
        scanf("%s %c %s %d",stu[i].name,&stu[i].gender,stu[i].id,&stu[i].grade);
        stu[i].flag=true;
        if(stu[i].gender=='M')
        {
            if(stu[i].grade<worstboy.grade) 
            {
                worstboy=stu[i];
            }
        }
        if(stu[i].gender=='F')
        {
            if(stu[i].grade>bestgirl.grade) 
            {
                bestgirl=stu[i];
            }
        }
    }
    if(bestgirl.flag)
    {
        printf("%s %s\n",bestgirl.name,bestgirl.id);
    }
    else printf("Absent\n");
    if(worstboy.flag)
    {
        printf("%s %s\n",worstboy.name,worstboy.id);
    }
    else printf("Absent\n");
    if(bestgirl.flag&&worstboy.flag)
    {
        printf("%d\n",bestgirl.grade-worstboy.grade);
    }
    else printf("NA\n");

}