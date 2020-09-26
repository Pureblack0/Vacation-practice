#include<stdio.h>
#include<stdlib.h>
struct Node;
typedef struct Node *PNode;
struct Node{
	float ceof;
	int exp;
	PNode next;
};
PNode createpoly()
{
	PNode h = NULL,p = NULL,q;
	float c;
	int e;
	printf("输入系数和指数（指数从大到小）：\n");
	scanf("%f %d",&c,&e);
	while(c!=0||e!=0)
	{
		p=(PNode)malloc(sizeof(struct Node));
		p->ceof = c;
		p->exp = e;
		p->next = NULL;
		if(h == NULL)
			h = p;
		else
			q->next = p;
		q = p;
		printf("输入系数和指数：\n");
		scanf("%f%d",&c,&e);
	}
	return h;
}
PNode addpoly(PNode h1,PNode h2)
{
	PNode p,r = NULL,s1,s2,s = NULL;
	float c;
	int e;
	s1 = h1;
	s2 = h2;
	while(s1 != NULL && s2 != NULL)
	{
		if(s1->exp == s2->exp)
		{
			c = s1->ceof+s2->ceof;
			e = s1->exp;
			s1 = s1->next;
			s2 = s2->next;
		}
		else if(s1->exp > s2->exp)
		{
			c = s1->ceof;
			e = s1->exp;
			s1 = s1->next;
		}
		else
		{
            c = s2->ceof;
			e = s2->exp;
			s2 = s2->next;
		}
		if(c != 0)
		{
			p=(PNode)malloc(sizeof(struct Node));
		    p->ceof = c;
		    p->exp = e;
		    p->next = NULL;
			if(s == NULL)
				s = p;
			else
				r->next = p;
			r = p;
		}
	}
	while(s1 != NULL)
	{
			c = s1->ceof;
			e = s1->exp;
			s1 = s1->next;
			if(c != 0)
		{
			p=(PNode)malloc(sizeof(struct Node));
		    p->ceof = c;
		    p->exp = e;
		    p->next = NULL;
			if(s == NULL)
				s = p;
			else
				r->next = p;
			r = p;
		}
	}
	while(s2 != NULL)
	{
			c = s2->ceof;
			e = s2->exp;
			s2 = s2->next;
			if(c != 0)
		{
			p=(PNode)malloc(sizeof(struct Node));
		    p->ceof = c;
		    p->exp = e;
		    p->next = NULL;
			if(s == NULL)
				s = p;
			else
				r->next = p;
			r = p;
		}
	}
	return s;
}
void outputpoly(PNode h)
{
	PNode p;
	p = h;
	while(p != NULL)
	{
		if(p->exp == 0)
			printf("%.2f",p->ceof);
		else
		{ 
			printf("%.2fx^%d",p->ceof,p->exp);
		}
		p = p->next;
		if(p != NULL)
			printf("+");
	}
	printf("\n");
}
void deletepoly(PNode h)
{
	PNode p,r = h;
	while(r != NULL)
	{
		p = r->next;
		free(r);
		r = p;
	}
}
void main()
{
	PNode head1,head2,head;
	printf("创建第一个多项式：\n");
	head1 = createpoly();
	printf("创建第二个多项式：\n");
	head2 = createpoly();
	printf("两个多项式相加：\n");
	head = addpoly(head1,head2);
	outputpoly(head);
	deletepoly(head);
}

