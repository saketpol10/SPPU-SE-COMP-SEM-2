#include <iostream>
#include<math.h>

using namespace std ;

class bnode {
int data ;
bnode *left;
bnode *right;
friend class bst ;
};

class bst {
public :
int n , x ;
bnode * root ;
bst(){
root = NULL ;
}
bnode * getnode ( int ndata ){
bnode * temp = new bnode;
temp -> data = ndata;
temp -> left = NULL;
temp -> right = NULL;
return temp;
}

bnode *insert ( bnode * temp , int in_data ){
if ( temp == NULL ){
temp = getnode(in_data);

}
else if ( temp->data > in_data){						//temp->data is root here
temp->left = insert( temp -> left , in_data );

}
else if ( temp -> data < in_data ) {
temp->right = insert( temp -> right , in_data);
}
else {
cout <<  "Already existing  data"<<endl;
}
return temp;
}
void input()
     {
       cout<<"ENTER NUMBER OF ELEMENTS IN THE BST : ";
       cin>>n;
       for(int i = 0 ; i < n ; i++)
      {
       cout<<"NUMBER = ";
       cin>>x;
       root = insert(root , x);
      }
     }

void display()
{
int ch ;
do {
cout<<endl<<"-----Menu----"<<endl;
cout<<endl<<"Select Option"<<endl;

cout<<"--- 1. INORDER TRAVERSAL ---"<<endl;
cout<<"--- 2. POSTORDER TRAVERSAL ---"<<endl;
cout<<"--- 3. PREORDER TRAVERSAL ---"<<endl;
cout<<"--- 4. MIN TERM ---"<<endl;
cout<<"--- 5. MAX TERM ---"<<endl;
cout<<"--- 6. DEPTH OF TREE ---"<<endl;
cout<<"--- 7. SEARCH AN ELEMENT ---"<<endl;
cout<<"--- 8. MIRROR TREE ---"<<endl;
cout<<"--- 9. Exit ---"<<endl;
cin>>ch;
 switch(ch){
case 1 :
inorder(root);
cout<<endl;
 break;

 case 2 :
postorder(root);
cout<<endl;
 break ;

 case 3:
preorder(root);
cout<<endl;
 break ;

 case 4:
min(root);
cout<<endl;
 break ;

 case 5:
maxi(root);
cout<<endl;
 break ;

 case 6:
cout<<"Depth "<<depth(root);
 break;

 case 7:
int key;
cout<<"Enter key to search: ";
cin>>key;
search(root, key);
cout<<endl;
 break ;

 case 8:
mirror(root);
inorder(root);
break;
     }
} while (ch!=10);
}

void inorder(bnode *temp)
{
 if(temp != NULL)
 {
  inorder(temp->left);
  cout<<temp->data<<"  ";
  inorder(temp->right);
 }
}

void postorder(bnode *temp)
{
 if(temp != NULL)
 {
  postorder(temp->left);
  postorder(temp->right);
  cout<<temp->data<<" ";
 }
}

void preorder(bnode *temp)
{
 if(temp != NULL)
 {
  cout<<temp->data<<" ";
  preorder(temp->left);
  preorder(temp->right);
 }
}

void min(bnode *temp){
while(temp->left != NULL){
temp= temp->left;
}
cout<<"Minimum value: "<<temp->data;
}

void search(bnode *temp, int key){
int count = 0;
while(temp!=NULL){
if(temp->data == key){
cout<<"Searched after passes: "<<count<<endl;
return;
}
else if(temp->data > key){
temp = temp->left;
}
else{
temp = temp->right;
}
count++;
}
}

void maxi(bnode *temp){
while(temp->right != NULL){
temp= temp->right;
}
cout<<"Maximum value: "<<temp->data;
}

int depth(bnode *temp){
if(temp == NULL){
return 0;
}
return (max((depth(temp->left)),depth(temp->right))+1);
}

void mirror(bnode *temp)
{
if (temp!=NULL)
{
return ;
}
else
{
bnode *ptr;
mirror(temp->left);
mirror(temp->right);
ptr= temp->left;
temp->left = temp->right;
temp->right = ptr;
}

}
};
int main (){
bst obj ;
obj.input();
obj.display();


return 0 ;

}
