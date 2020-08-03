#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node* new_node(int data){
  struct node* node=(struct node*)malloc(sizeof(struct node));
  node->data=data;
  node->left=NULL;
  node->right=NULL;
  return(node);
}
void print_tree(struct node *root,int s){
    int i;
    if (root==NULL){
      return;
    }
    s+=1;
    print_tree(root->right,s);
   if (root!=NULL){
      printf("\n\n");
      for(i=0;i<s;i++)
        printf("\t");
      printf("%d",root->data);
      print_tree(root->left,s);
   }
}

void search(struct node *root,int p){
  if(root!=NULL){
    if(root->data==p)
    {
      return("Element Found");
    }
    else{
      search(root->right,p);
      search(root->left,p);
    }
  }

}


int main(void){
  struct node *root=new_node(1);
  root->left=new_node(2);
  root->right=new_node(3);
  root->left->left=new_node(4);
  root->left->right=new_node(5);
  root->right->left=new_node(6);
  root->right->right=new_node(7);
  print_tree(root,0);
  search(root,5);
}
