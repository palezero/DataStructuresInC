#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct TreeNode* PtrToNode;
typedef PtrToNode Tree;
typedef char ElementType;
struct TreeNode//二叉树节点
{
	ElementType Element;
	Tree left;
	Tree right;
};
typedef struct StackNode* Stack;//堆栈
struct StackNode
{
	Tree Element;
	Stack Next;
};
Stack New_Stack();
Tree Make_Tree(ElementType Seed_Element);
void Print_Tree(Tree T, int Depth);
Tree Pop(Stack S);
void Push(Tree T, Stack S);
bool Isletter(char ch);
Tree Front2Tree(char s[], Stack S);//前缀表达式转表达式树
// Tree Mid2Tree(char s[], Stack S);
Tree Last2Tree(char s[], Stack S);
void Tree2Front(Tree T);//表达式树转前缀表达式
void Tree2Mid(Tree T);//表达式树转中缀表达式
void Tree2Last(Tree T);//表达式树转后缀表达式
int main() 
{
    char s[40];
    scanf("%s", s);
    Stack S = New_Stack();
    Tree T = Front2Tree(s, S);
    T = Pop(S);
    Print_Tree(T, 0);
    Tree2Mid(T);
    return 0;
}
// Tree Mid2Tree(char s[], Stack S)
// {
// 	int i;
// 	static Tree T;
//     Tree T_left;
//     Tree T_right;
//     Tree New_T;
//     Tree load_T1,load_T2;
//     int count = 0;
//     for(i = 0; i < strlen(s); i++)
//     {
//     	if(s[i] == '(')
//     		count++;
//     	else if(s[i] == ')')
// 			count--;
// 		else
// 		{
// 			New_T = Make_Tree(s[i]);
// 			if(!Isletter(s[i]))//读到运算符
// 			{
// 				load_T1 = Pop(S);
// 				New_T->right = load_T1;
// 				Push(New_T, S);
// 			}
// 			else//读到未知数
// 			{
// 				if(S->Next != NULL)//如果不是空栈
// 				{
// 					load_T1 = Pop(S);//取出一个
// 					if(!Isletter(load_T1->Element))//如果是运算符
// 						load_T1->left = New_T;
// 					Push(load_T1, S);
// 				}
// 				else
// 					Push(New_T, S);
// 			}
// 		}
// 	}
//     return T;
// }

Tree Last2Tree(char s[], Stack S)
{
	int i;
	static Tree T;
    Tree T_left;
    Tree T_right;
    Tree New_T;
    Tree load_T1,load_T2;
    T = Make_Tree(s[0]);
    Push(T, S);
    for(i = 1; i < strlen(s); i++)
    {
    	New_T = Make_Tree(s[i]);
    	if(Isletter(s[i]))
    		Push(New_T, S);
    	else
    	{
    		load_T1 = Pop(S);
    		load_T2 = Pop(S);
    		New_T->right = load_T1;
    		New_T->left = load_T2;
    		Push(New_T, S);
    	}
    }
    return T;
}
Tree Front2Tree(char s[], Stack S)
{
	int i;
	static Tree T;
    Tree T_left;
    Tree T_right;
    Tree New_T;
    Tree load_T1,load_T2;
    T = Make_Tree(s[0]);
    Push(T, S);
    for(i = 1; i < strlen(s); i++)
    {
    	New_T = Make_Tree(s[i]);
    	if(Isletter(s[i]))
    		Push(New_T, S);
    	else
    	{
    		load_T1 = Pop(S);
    		load_T2 = Pop(S);
    		New_T->left = load_T1;
    		New_T->right = load_T2;
    		Push(New_T, S);
    	}
    }
    return T;
}
void Tree2Front(Tree T)
{
	printf("%c", T->Element);
	if(T->left != NULL)
		Tree2Front(T->left);
	if(T->right != NULL)
		Tree2Front(T->right);
}
void Tree2Last(Tree T)
{
	if(T->left != NULL)
		Tree2Last(T->left);
	if(T->right != NULL)
		Tree2Last(T->right);
	printf("%c", T->Element);
}
void Tree2Mid(Tree T)
{
	if(!Isletter(T->Element))
			printf("(");
	if(T->left != NULL)
		Tree2Mid(T->left);
	printf("%c", T->Element);
	if(T->right != NULL)
		Tree2Mid(T->right);
	if(!Isletter(T->Element))
			printf(")");
}
void Print_Tree(Tree T, int Depth)
{
	int i;
	for(i = 0; i < Depth; i++)
		printf("--");
	printf("%c\n", T->Element);
	if(T->left != NULL)
	{
		printf("---");
		Print_Tree(T->left, Depth + 1);
	}
	if(T->right != NULL)
	{
		printf("---");
		Print_Tree(T->right, Depth + 1);
	}
}
bool Isletter(char ch)
{
	if(ch <= 'Z' && ch >= 'A')
		return true;
	else if(ch <= 'z' && ch >= 'a')//区分大小写
		return true;
	return false;
}
void Push(Tree T, Stack S)
{
	Stack New_Element;
	New_Element = (Stack)malloc(sizeof(StackNode));
	New_Element->Element = T;
	New_Element->Next = S->Next;
	S->Next = New_Element;
}
Tree Pop(Stack S)
{
	Tree temp;
	Stack FreePointer;
	if(S->Next!=NULL)
	{
		FreePointer = S->Next;
		temp = FreePointer->Element;
		S->Next = FreePointer->Next;
		free(FreePointer);
		return temp;
	}
	else printf("StackBelowFlow\n");
	return 0;
}
Tree Make_Tree(ElementType Seed_Element)
{
	static Tree T;
	T = (Tree)malloc(sizeof(TreeNode));
	T->Element = Seed_Element;
	T->left = NULL;
	T->right = NULL;
	return T;
}
Stack New_Stack()
{
	static Stack S;
	S = (Stack)malloc(sizeof(StackNode));
	S->Next = NULL;
	return S;
}