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
//���Ķ���
typedef struct Stack
{
	PRoot data[MaxSize];
	int top;
}ST;
//ջ�Ķ���
ST Initstack(ST stk);
//��ʼ��ջ
int StkEmpty(ST stk);
//�ж�ջ�Ƿ�Ϊ��
void push(ST stk,PRoot root);
//��ջ
PRoot pop(ST stk,PRoot root);
//��ջ
PRoot Create_Bin_Tree();
//�ݹ鴴�������������������������Ӧ��ֵ
void levelorder(PRoot root);
//�������
void perorder(PRoot root);
//�������
void inorder(PRoot root);
//�������
void postorder(PRoot root);
//�������
void operation(int x, PRoot root);
//��������
int height(PRoot root);
//�����ĸ߶�
int countnode(PRoot root);
//�������
int countsignalnode(PRoot root);
//���Ϊ1�Ľڵ�ĸ���
int countdoublenode(PRoot root);
//���Ϊ2�Ľڵ�ĸ���
#endif // !_TREECREAT_

