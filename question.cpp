#include <stdio.h>
#include <stdlib.h>
typedef struct node  
{	int number;       
	int mydata;       
	struct node *next; 
} linklist;
linklist *CreateCircle( int n );
linklist *DeleteNext(linklist *p);  

linklist*rhead;
linklist *CreateCircle( int n ){
	int i,nn;
	linklist*head,*tail,*p;
	head=tail=NULL;
	for(i=1;i<=n;i++){
		scanf("%d",&nn);
		p=(linklist*)malloc(sizeof(linklist));
		p->number=i;
		p->mydata=nn;
		p->next=NULL;
		if(head==NULL)head=p;
		else tail->next=p;
		tail=p;
		if(i==1)rhead=p;
	}
	return tail;
}
linklist *Delete(linklist*head,int y){
	linklist*ptr1,*ptr2;
	ptr1=head;
	ptr2=head->next;
	if(ptr1->number==y){
	  rhead=head=head->next;
      free(ptr1);
	  return head;
	  }
	while(ptr2!=NULL){
		if(ptr2->number==y){
			ptr1->next=ptr2->next;
			free(ptr2);
			return ptr1;
		}
		else ptr1=ptr2;
		ptr2=ptr1->next;
	}	
}
linklist *DeleteNext(linklist *p){
	int i,x,y;
	linklist*q;
	y=p->number;
    printf("Delete No:%d\n",p->number);
    x=p->mydata;
    p=Delete(rhead,y);  
    for(i=1;i<=x;i++){
    	if(p->next!=NULL)
    	     p=p->next;   
    	else
    	      p=rhead;
    }
	return p;
}
int KingOfMonkey(int n,linklist *head){
      int q;
      linklist*p=rhead;
      for(q=1;q<head->mydata;q++){
      	 if(p!=NULL)p=p->next;
      	 else p=rhead;
      }
      for(q=1;q<n;q++)
		 p=DeleteNext(p);
	     return p->number;
}
int main(){
    linklist *head;
    int i,n;
    scanf("%d",&n); 
    head = CreateCircle(n); 
    printf("The king is monkey[%d].\n", KingOfMonkey(n,head));
    return 0;
}