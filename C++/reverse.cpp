#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string>
#include<map>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<limits.h>
#include<set>
#include<stack>
#include<queue>
using namespace std;

#define P(s) printf("%s\n",s)
#define Pint(n) printf("%d",n)
#define Sint(n) scanf("%d",&n)
#define TEST printf("Test Called!")
#define NL printf("\n")

class Node{
	int value;
	Node *next;
	Node(){} //handling implicit Copy Constructor
	Node(int val): value(val){}
	Node(int val,Node *next): value(val),next(next){}
};

class BinaryTree{
	int value;
	BinaryTree *left;
	BinaryTree *right;
	BinaryTree(){} //handling implicit Copy Constructor
	BinaryTree(int val): value(val){}
	BinaryTree(int val, BinaryTree *left, BinaryTree *right): value(val),left(left), right(right){}
};

void swap(char *a, char *b){
	*a=*a+*b-(*b=*a);
}

void reverse(char *str){
	int start=0,end=0;
	while(str[end+1]!='\0')
		end++;
	while(start<end){
		swap(&str[start],&str[end]);
		start++;
		end--;
	}
}

int main()
{
	char str[] = "Hello";
	reverse(str);
	cout << str <<endl;
	return 0;
}

