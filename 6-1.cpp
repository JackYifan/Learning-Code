#include <stdio.h>
#include <string.h>
void fsort(char *color[ ], int n);

int main(void )
{
    int i;
    char *pcolor[5] ;
    pcolor[1]="red";
    pcolor[2]="blue";
    void fsort(char *color[ ], int n);

    //fsort(pcolor, 5);   /* ���ú��� */
    strcpy(pcolor[1],pcolor[2]);
    for(i = 0; i < 5; i++) 
        printf("%s ", pcolor[i]);
    printf("\n");
    return 0;
}    

void fsort(char *color[ ], int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
        	char temp[5];
            if(strcmp(color[j],color[j+1])>0)
            {
                strcpy(temp,color[j]);
                strcpy(color[j],color[j+1]);
                strcpy(color[j+1],temp);
            }
        }
    }

}
