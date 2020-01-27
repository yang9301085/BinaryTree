#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TreeCreate.h"
static void levelorder(PRoot root)//层序遍历
{
	typedef struct Queue
	{
		PRoot arr[MaxSize];
		int front, rear;
	}Que;//定义队列结构，利用队列辅助存储数据
	int x = 0;
	Que que;
	que.front = que.rear = 0;//将队头队尾标志位设置为0
	if (root != NULL)//如果树不为空
	{
		que.arr[que.rear++] = root;
		while (que.front < que.rear)//如果队尾指针大于队头指针，则表示队列不空

		{
			printf("%d",que.arr[que.front++]->data);
			if (root->left != NULL)que.arr[que.rear++] = root->left;
			if (root->right != NULL)que.arr[que.rear++] = root->right;
		}
	}
}
static void perorder(PRoot root)//前序遍历
{
	if (root != NULL)
	{
		printf("%d",root->data);
		perorder(root->left);
		perorder(root->right);
	}
}
static void inorder(PRoot root)//中序遍历
{
	if (root != NULL)
	{
		perorder(root->left);
		printf("%d", root->data);
		perorder(root->right);
	}	
}
static void postorder(PRoot root)//后序遍历
{
	if (root != NULL)
	{
		perorder(root->left);
		perorder(root->right);
		printf("%d", root->data);
	}
}
static int height(PRoot root)//求树的高度
{
	if (root == NULL)return 0;
	else return height(root->left) > height(root->right) ? height(root->left) + 1 : height(root->right) + 1;
}
static int countnode(PRoot root)
{
	if (root == NULL)return 0;
	else if (root->left == NULL && root->right == NULL)return 1;
	else return countnode(root->left) + countnode(root->right);
}//求结点个数
static int countsignalnode(PRoot root)
{
	if(root==NULL)return 0;
	if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))
		return (countsignalnode(root->left) + countsignalnode(root->right) + 1);
	else 
		return (countsignalnode(root->left) + countsignalnode(root->right));
}//求度为1的结点个数
static int countdoublenode(PRoot root)
{
	if (root == NULL)return 0;
	else if (root->left != NULL && root->right != NULL)
		return (countdoublenode(root->left) + countdoublenode(root->right) + 1);
	else return (countdoublenode(root->left) + countdoublenode(root->right));
}//求度为2的节点的个数
static ST Initstack(ST stk)
{
	stk.top = -1;
	return stk;
}//初始化栈
static int StkEmpty(ST stk)
{
	return stk.top == -1 ? 0 : 1;
}//判断栈是否为空
static void push(ST stk, PRoot root)
{
	if (stk.top == MaxSize - 1)return;
	stk.top++;
	stk.data[stk.top] = root;
}//入栈
static PRoot pop(ST stk, PRoot root)
{
	if (stk.top == -1)printf("栈空\n");
	stk.top--;
	return stk.data[stk.top];
}//出栈
PRoot Create_Bin_Tree()
{
	PRoot root = (PRoot)malloc(sizeof(TRoot));
	if (!root)exit(0);//如果申请节点失败，退出程序
	else
	{
		root->left = root->right = NULL;
	}
	return root;
}//递归创建二叉树，按现序次序输入相应的值
void operation(int x, PRoot root)//操作函数
{
	switch (x)
	{
	case 1:levelorder(root);	//选1层序遍历
		break;
	case 2:perorder(root);		//选2先序遍历
		break;
	case 3:inorder(root);		//选3中序遍历
		break;
	case 4:postorder(root);		//选4后续遍历
		break;
	case 5:printf("%d", height(root));		//选5求树的高度
		break;
	case 6:printf("%d", countnode(root));		//选6求结点个数
		break;
	case 7:printf("%d", countsignalnode(root));		//选7求度为1的结点个数
		break;
	case 8:printf("%d", countdoublenode(root));		//选8求度为2的结点个数
		break;
	default:printf("Input Error\n");	//其他输出错误
		break;
	}
}
