#include <stdio.h>
#include <stdlib.h>

struct stud_node {
	int    num;
	char   name[20];
	int    score;
	struct stud_node *next;
};

struct stud_node *createlist();
struct stud_node *deletelist(struct stud_node *head, int min_score);

int main()
{
	int min_score;
	struct stud_node *p, *head = NULL;

	head = createlist();
	scanf("%d", &min_score);
	head = deletelist(head, min_score);
	for (p = head; p != NULL; p = p->next)
		printf("%d %s %d\n", p->num, p->name, p->score);

	return 0;
}

/* 你的代码将被嵌在这里 */


/* 你的代码将被嵌在这里 */
struct stud_node *createlist(){
	int id;
	scanf("%d", &id);
	if (id == 0) return NULL;
	struct stud_node* head= (struct stud_node*)malloc(sizeof(struct stud_node));
	head->next = NULL;
	struct stud_node* temp = head;
	head->num = id;
	getchar();
	scanf("%s %d", head->name, &head->score);
	scanf("%d", &id);
	while (id != 0) {
		getchar();
		struct stud_node* node = (struct stud_node*)malloc(sizeof(struct stud_node));
		node->num = id;
		scanf("%s %d", node->name, &node->score);
		node->next = NULL;
		temp->next = node;
		temp = temp->next;
		scanf("%d", &id);
	}
	return head;
}
struct stud_node *deletelist(struct stud_node *head, int min_score) {
	struct stud_node*ans=(struct stud_node*)malloc(sizeof(struct stud_node));
    ans->next=head;
    struct stud_node*p=head,*pre=ans,*temp;
    for(;p!=NULL;){
        if(p->score<min_score){
            temp=p;
            pre->next=p->next;
            p=p->next;
            free(temp);
        }
        else{
            p=p->next;
            pre=pre->next;
        }
    }
    return ans->next;
}
/*
1 aaa 78
0
80
*/