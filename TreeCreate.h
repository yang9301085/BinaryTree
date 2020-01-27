#pragma once
#ifndef _TREECREAT_H_
#define _TREECREAT_H_

#define MaxSize 100
typedef struct TreeCreate
{
	int data;
	struct TreeCreate* left;
	struct TreeCreate* right;
}TRoot, * PRoot;
//树的定义
typedef struct Stack
{
	PRoot data[MaxSize];
	int top;
}ST;
//栈的定义
ST Initstack(ST stk);
//初始化栈
int StkEmpty(ST stk);
//判断栈是否为空
void push(ST stk,PRoot root);
//入栈
PRoot pop(ST stk,PRoot root);
//出栈
PRoot Create_Bin_Tree();
//递归创建二叉树，按现序次序输入相应的值
void levelorder(PRoot root);
//层序遍历
void perorder(PRoot root);
//先序遍历
void inorder(PRoot root);
//中序遍历
void postorder(PRoot root);
//后序遍历
void operation(int x, PRoot root);
//操作函数
int height(PRoot root);
//求树的高度
int countnode(PRoot root);
//求结点个数
int countsignalnode(PRoot root);
//求度为1的节点的个数
int countdoublenode(PRoot root);
//求度为2的节点的个数
#endif // !_TREECREAT_

