#include <iostream>
using namespace std;

struct node{
node* next;
int data;
};

struct Dnode{
Dnode* next;
Dnode* prev;
int data;
};
class DLinkedList{
	private:
		Dnode *first;
	public:	
DLinkedList(){
first=NULL;		
	     }
void addNode(int x){
	Dnode* newNode=new Dnode;
	newNode->data=x;
if( first == NULL ){
	first=newNode;
	newNode->prev=NULL;
	newNode->next=NULL;
}else{
Dnode* temp=first;
while(temp->next != NULL )
	temp=temp->next;
temp->next=newNode;
newNode->prev=temp;
}}
void display(){
Dnode* temp=first;
while(temp != NULL ){
cout<<(temp->data)<<"   ";
temp=temp->next;    }
             }
void concatanate(Dnode* f1,Dnode* f2,Dnode* f3){

	Dnode* temp=f1;
while(temp->next != NULL)
	temp=temp->next;
temp->next=f2;
f2->prev=temp;
Dnode* temp2=f2;
while(temp2->next != NULL)
	temp2=temp2->next;
temp2->next=f3;
f3->prev=temp2;
}
void deleteLast(){
	Dnode* temp=first;
while((temp->next->next) != NULL)
	temp=temp->next;
temp->next->prev=NULL;
delete (temp->next);
display();
temp->next=NULL;
}};
int main(){
DLinkedList a;
a.display();
cout<<endl;
a.addNode(1);
a.addNode(2);
a.addNode(3);
a.display();
a.deleteLast();
cout<<endl;
a.display();

return 0;
}
