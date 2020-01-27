#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TreeCreate.h"
static void levelorder(PRoot root)//�������
{
	typedef struct Queue
	{
		PRoot arr[MaxSize];
		int front, rear;
	}Que;//������нṹ�����ö��и����洢����
	int x = 0;
	Que que;
	que.front = que.rear = 0;//����ͷ��β��־λ����Ϊ0
	if (root != NULL)//�������Ϊ��
	{
		que.arr[que.rear++] = root;
		while (que.front < que.rear)//�����βָ����ڶ�ͷָ�룬���ʾ���в���

		{
			printf("%d",que.arr[que.front++]->data);
			if (root->left != NULL)que.arr[que.rear++] = root->left;
			if (root->right != NULL)que.arr[que.rear++] = root->right;
		}
	}
}
static void perorder(PRoot root)//ǰ�����
{
	if (root != NULL)
	{
		printf("%d",root->data);
		perorder(root->left);
		perorder(root->right);
	}
}
static void inorder(PRoot root)//�������
{
	if (root != NULL)
	{
		perorder(root->left);
		printf("%d", root->data);
		perorder(root->right);
	}	
}
static void postorder(PRoot root)//�������
{
	if (root != NULL)
	{
		perorder(root->left);
		perorder(root->right);
		printf("%d", root->data);
	}
}
static int height(PRoot root)//�����ĸ߶�
{
	if (root == NULL)return 0;
	else return height(root->left) > height(root->right) ? height(root->left) + 1 : height(root->right) + 1;
}
static int countnode(PRoot root)
{
	if (root == NULL)return 0;
	else if (root->left == NULL && root->right == NULL)return 1;
	else return countnode(root->left) + countnode(root->right);
}//�������
static int countsignalnode(PRoot root)
{
	if(root==NULL)return 0;
	if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))
		return (countsignalnode(root->left) + countsignalnode(root->right) + 1);
	else 
		return (countsignalnode(root->left) + countsignalnode(root->right));
}//���Ϊ1�Ľ�����
static int countdoublenode(PRoot root)
{
	if (root == NULL)return 0;
	else if (root->left != NULL && root->right != NULL)
		return (countdoublenode(root->left) + countdoublenode(root->right) + 1);
	else return (countdoublenode(root->left) + countdoublenode(root->right));
}//���Ϊ2�Ľڵ�ĸ���
static ST Initstack(ST stk)
{
	stk.top = -1;
	return stk;
}//��ʼ��ջ
static int StkEmpty(ST stk)
{
	return stk.top == -1 ? 0 : 1;
}//�ж�ջ�Ƿ�Ϊ��
static void push(ST stk, PRoot root)
{
	if (stk.top == MaxSize - 1)return;
	stk.top++;
	stk.data[stk.top] = root;
}//��ջ
static PRoot pop(ST stk, PRoot root)
{
	if (stk.top == -1)printf("ջ��\n");
	stk.top--;
	return stk.data[stk.top];
}//��ջ
PRoot Create_Bin_Tree()
{
	PRoot root = (PRoot)malloc(sizeof(TRoot));
	if (!root)exit(0);//�������ڵ�ʧ�ܣ��˳�����
	else
	{
		root->left = root->right = NULL;
	}
	return root;
}//�ݹ鴴�������������������������Ӧ��ֵ
void operation(int x, PRoot root)//��������
{
	switch (x)
	{
	case 1:levelorder(root);	//ѡ1�������
		break;
	case 2:perorder(root);		//ѡ2�������
		break;
	case 3:inorder(root);		//ѡ3�������
		break;
	case 4:postorder(root);		//ѡ4��������
		break;
	case 5:printf("%d", height(root));		//ѡ5�����ĸ߶�
		break;
	case 6:printf("%d", countnode(root));		//ѡ6�������
		break;
	case 7:printf("%d", countsignalnode(root));		//ѡ7���Ϊ1�Ľ�����
		break;
	case 8:printf("%d", countdoublenode(root));		//ѡ8���Ϊ2�Ľ�����
		break;
	default:printf("Input Error\n");	//�����������
		break;
	}
}
