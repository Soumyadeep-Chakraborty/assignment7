
//cpp programme to execute a binary search tree(insertion,search,display and deletion) 

#include <iostream>

using namespace std;

//declaring components of a node : data, parent, left child, right child

class node

{

 public:

 int data;

 node *parent,*left,*right;
 
 //class constructor

 node()

 {

  data=0;

  parent=NULL;

  left=NULL;

  right=NULL;

 }

};

//declaring BST as a data-type with functions such as deletion ,insertion and search

class Tree

{

 public:

 node *root=NULL;
 
 //insert function

 void insert(node *root,int data){

if (root=NULL){	//making the first node the root

node *temp=new node;

temp->data=data;

temp->parent=NULL;

temp->left=NULL;

temp->right=NULL;

root=temp;

}

else if (data < root->data){

if (root->left=NULL){

insertdata (root,data);} //creating a right child

else { 

insert (root->left,data);}} //recursive call



else {

if (root->right=NULL){

insertdata (root,data);} //creating a right child

else {

insert (root->right,data);}}} //recursive call


//function to insert data
void insertdata (node *root,int data){

node *temp=new node;

temp->data=data;

temp->parent =root;

temp->left=NULL;

temp->right=NULL;

}

//delete function

 void deleteN(int key)

 {

  node *p=bsearch(root,key); //calling bsearch function to reach the node to be deleted

  if(p->left == NULL && p->right == NULL) //first case : if node is leaf

  {

   if(p->parent->left == p)

   p->parent->left=NULL;

   else

   p->parent->right=NULL;

  }

  else if(p->left == NULL) //second case : node to be deleted contains one child

  {

   if(p->parent->left == p)

   p->parent->left=p->right;

   else

   p->parent->right=p->right;

  }

  else if(p->right == NULL)	//second case : node to be deleted contains one child

  {

   if(p->parent->left == p)

   p->parent->left=p->left;

   else

   p->parent->right=p->left;

  }

  else //third case : node to be deleted conatins two child

  {

   node *temp=p->left;

   while(temp->right != NULL)

   {

    temp=temp->right;

   }

   if(temp->left != NULL)

   {

    temp->parent->right=temp->left;

    p->data=temp->data;

   }

   else

   {

    temp->parent->right=NULL;

    p->data=temp->data;

   }

  }

 }

//function to search the required node 

 node *bsearch(node *v,int data)

 {

  node *temp=v,*p;

  if(v==NULL)

  {

   cout<<"Not Found\n";

   return NULL;

  }

  else

  {

   if(data < temp->data)

   p=bsearch(temp->left,data);

   else if(data > temp->data)

   p=bsearch(temp->right,data);

   else

   {

    cout<<"Found\n";

    return temp;

   }

   return p;

  }

 }

//function to display

void display (node *temp){

if(temp==NULL){

cout<<"Error";

return ;

}

else {

display (temp->left);

cout << temp->data;

display (temp->right);

}}};

int main(){

Tree b;

int i,k,s;

int p;

int d;

int m=1;

while (m==1){

cout <<" Choose an option : 1.insert 2.display 3.delete 4.search";

cin>>i;



switch (i){

case 1 :

	cout<<"Enter Data : ";

	cin>>d;

	b.insert (b.root,d);

	break;

case 2 :

	b.display (b.root);

	break;

case 3 :
	
	cout<<"Enter Key : ";
	cin>>k;
	b.deleteN (k);
	break;
	
case 4 :
	cout<<"Enter Key : ";
	cin>>s;
	b.bsearch (b.root,d);
	break;
	
default :

	cout<<"Choose a valid option";

	break;

}



cout<<"Do you want to carry out more operations ? Enter y=1 or n=2 ~ ";

cin>>m;

}



return 0;

}

