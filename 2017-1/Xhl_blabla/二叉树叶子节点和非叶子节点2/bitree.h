#include<stdio.h>
#include<stdlib.h>
typedef char  ElemType;
typedef int status;
#define num 30
int number = 0;//定义一个全局变量  用于赋值时的计数
			   //定义二叉树
typedef struct  BiTree
{
	ElemType  date;
	struct  BiTree *lChild;
	struct  BiTree * rChild;
}  BitNode, *BiTree;
status CreatBiTree(BiTree *t, char *x);//先序创立二叉树
int GetCount(BiTree T);//求二叉树的所有结点	
int Leafcount(BiTree T, int *m);//求二叉树叶子结点个数