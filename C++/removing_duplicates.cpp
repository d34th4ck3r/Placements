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
   public:
      int value;
      Node *next;
      Node(){} //handling implicit Copy Constructor
      Node(int val): value(val),next(NULL){}
      Node(int val,Node *next): value(val),next(next){}

      void addToList(Node *node){
         Node *pointer = this;
         while(pointer->next != NULL){
            pointer = pointer->next;
         }
         pointer->next = node;
         return;
      }

      static Node* convertArrayToLinkedList(int *array,int N){
	      Node *start = new Node(array[0]);
	      Node *end = start;
	      for(int i=1;i<N;i++){                                                
		      Node *node = new Node(array[i]);              
		      end->next = node;              
		      end = end->next;
	      }
	      return start;  
      }

      void print(){
	      Node *current = this;
	      while(current!=NULL){
		      cout << current->value <<" ";
		      current = current->next;
	      }
	      cout << endl;
      }

      void remove_duplicates(){
	      map<int,bool> Hash;
	      Node *prev = this;
	      Hash[prev->value] = true;
	      Node *curr = this->next;
	      while(curr!=NULL){
		      if(Hash.find(curr->value) == Hash.end()){
			      Hash[curr->value] = true;
			      prev = curr;
			      curr = curr->next;
		      }else{
			      prev->next = curr->next;
			      Node *temp = curr;
			      curr = curr->next;
			      delete temp;
		      }
	      }
      }
};

class BinaryTree{
   public:
      int value;
      BinaryTree *left;
      BinaryTree *right;
      BinaryTree(){} //handling implicit Copy Constructor
      BinaryTree(int val): value(val){}
      BinaryTree(int val, BinaryTree *left, BinaryTree *right): value(val),left(left), right(right){}
};

int main()
{
   int array[] = {2,3,4,5,2,2,2,2,3,2,12,2,12,3,3,2,23,1};
   Node* list = Node::convertArrayToLinkedList(array,sizeof(array)/sizeof(array[0]));
   list->print();
   list->remove_duplicates();
   list->print();
   return 0;
}

