#include <stdio.h>
#include <string.h>
#define SIZE 8 

struct INVEN{
	struct INVEN *next;
	char name[SIZE];
};

int NodeLen(struct INVEN *list)
{
	int count = 0;
	struct INVEN *cur = list;
	while (cur!=NULL)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

int len_ck(int a1, int a2, int len)
{
	if (a1 <= len && a1 > 0 && a2 <= len && a2 > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void reader(struct INVEN *curr)
{
	printf("inven: ");
	while (curr != NULL)
	{
		printf("%s ", curr->name);
		curr = curr->next;
	}	
}

void i_reader(struct INVEN *curr)
{
	int i=1;
	printf("(");
	while (curr != NULL)
	{
		printf("%d.%s ", i, curr->name);
		curr = curr->next;
		i++;
	}
	printf(")\n\n");
}

void delete_m(struct INVEN *ls)
{
	struct INVEN *cur = ls;
	struct INVEN *next = malloc(sizeof(struct INVEN));
	
	while(cur!=NULL)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(next);
}

int add_q()
{
	int ans;
	
	while(1)
	{
		printf("1.�� 2.��\n");
		scanf("%d",&ans);
		if(ans==1 || ans==2)
		break;
		else
		printf("Error: Invalid answer. Try 1 or 2.\n");
	}
	
	return ans;
}

void switcher(struct INVEN *arr, int from, int to, int ct)
{
	int i;
	struct INVEN *tp = malloc(sizeof(struct INVEN));
	char tparr[SIZE], tparr2[SIZE];
	
	tp = arr;
	
	for (i=1; i<=ct; i++)
	{
		tp = tp->next;

		if (i==from)
		{
			strcpy(tparr, tp->name);
		}
		else if(i==to)
		{
			strcpy(tparr2, tp->name);
		}			
	}
	//printf("process 2 completed.\n");
	tp = arr;
	for (i=1; i<=ct; i++)
	{
		//printf("process 3-%d completed.\n",i);
		tp = tp->next;

		//printf("process 4 completed.\n");
		if (i==from)
		{
			strcpy(tp->name, tparr2);
		}
		else if(i==to)
		{
			strcpy(tp->name, tparr);
		}
		//printf("process 5 completed.\n");		
	}	
}

void arrange(struct INVEN *arr, int nd_len)
{
	int ct, i, dt, j, k;
	struct INVEN *tp = malloc(sizeof(struct INVEN));
	char tparr[SIZE];
	
	
	ct=0;
	for(i=0; i<nd_len; i++)
	{
		tp = arr;
		ct=0;
		for(k=0; k<nd_len; k++)
		{
			dt=0;
			tp = tp->next;
			if(tp->next == NULL)
			break;			
			
			for(j=0; j<SIZE; j++)
			{
				if(tp->name[dt] > tp->next->name[dt])
				{
					strcpy(tparr, tp->name);
					strcpy(tp->name, tp->next->name);
					strcpy(tp->next->name, tparr);
					break;
				}
				else if (tp->name[dt] == tp->next->name[dt])
				{
					dt++;
				}
				else
				{
					break;
				}
			}		
		}
		/*
		if(arr->name[dt] > arr->next->name[dt])
		{

			strcpy(tp, arr->name);
			strcpy(arr->name, arr->next->name);
			strcpy(arr->next->name, *tp);

			

			tparr->next = arr->next;
			arr->next = arr->next->next;
			arr->next->next = tparr->next;

			arr->next = arr->next->next;
			arr->next->next = arr->next;
			
			ct++;
		}
		else
		{
			dt++;
		}
		*/	
	}
}

void add_m(struct INVEN *target, char *n)    // ���� ��� �ڿ� ��带 �߰��ϴ� �Լ�
{
    struct INVEN *newNode = malloc(sizeof(struct INVEN));    // �� ��� ����
    struct INVEN *tget = target->next;

    if (target->next->next == NULL)
    {
    	newNode->next = target->next->next;
    	target->next->next = newNode;    // ���� ����� ���� ��忡 �� ��带 ����
    	puts("oh!");
	}
	else
	{
		newNode->next = target->next;    // �� ����� ���� ��忡 ���� ����� ���� ��带 ����
		target->next = newNode;    // ���� ����� ���� ��忡 �� ��带 ����
	}
    strcpy(newNode->name, n);            // ������ ����


}

void remove_m(struct INVEN *target)    // ���� ��� �ڿ� ��带 �߰��ϴ� �Լ�
{
    struct INVEN *removeNode = target->next;    // �� ��� ����
	target->next = removeNode->next;
			
	free(removeNode);
}

void targetmanager(struct INVEN *curr, char *n, int ch)    // ���� ��� �ڿ� ��带 �߰��ϴ� �Լ�
{
	int ans = add_q();
	struct INVEN *target;
    struct INVEN *newNode = malloc(sizeof(struct INVEN));    // �� ��� ����

	if (ans == 1)
	{
		target = curr;
	}
	else
	{
		while (1)
		{
			target = curr;
			curr = curr->next;
			if (curr->next == NULL)
			{
				puts("wow!");
				
				break;
			}
	        //printf("%s ", curr->name);			
		}    
	}
    
    if(ch==1)
    {
    	add_m(target,n);
	}
	else
	{
		remove_m(target);
	}
}

int main()
{
	int ch, nd_len, a1, a2;
	char add[8];
	
	struct INVEN *head = malloc(sizeof(struct INVEN)); // Head Node: Not saving datas 
	
	struct INVEN *node1 = malloc(sizeof(struct INVEN));
	head->next = node1;
	strcpy(node1->name, "spear");
	
	struct INVEN *node2 = malloc(sizeof(struct INVEN));
	node1->next = node2;
	strcpy(node2->name, "hammer");
	
	struct INVEN *node3 = malloc(sizeof(struct INVEN));
	node2->next = node3;
	strcpy(node3->name, "sw'o'rd");
	
	node3->next = NULL;
	
	while(1)
	{
		nd_len = NodeLen(head)-1;
		printf("len:%d\n",nd_len);
		reader(head->next);
	
		puts("\n1.���� 2.���� 3.���� 4.�̵�");
		scanf("%d",&ch);
		
		if(ch==1)
		{
			printf("�߰��� ���� �Է�(7�� ����): ");
			scanf("%s",add);
			targetmanager(head,add,1);
		} 
		else if(ch==2)
		{
			targetmanager(head,add,2);
		}
		else if(ch==3)
		{
			arrange(head, nd_len);
		}
		else if(ch==4)
		{
			while(1)
			{
				printf("�ٲ� ���� ��ȣ �Է� (1~%d)\n",nd_len);
				i_reader(head->next);
				printf("��ȣ 1, 2: ");
				scanf("%d %d",&a1, &a2);
				if(len_ck(a1,a2,nd_len))
				{
					break;
				}		
				else
				{
					printf("���� ���� ���ڸ� �Է����ּ���.\n");
				}	
			}
			//printf("process 1 completed.\n");
			switcher(head,a1,a2,nd_len);
		}
	}

	
	delete_m(head);
		
	return 0;
}
