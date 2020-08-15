struct node{
node* next;
int data;
};

struct Dnode{
Dnode* next;
Dnode* prev;
int data;
};
node* concatanate(node* f1,node* f2,node* f3){

	node* temp=f1;
while(temp->next =! NULL)
	temp=temp->next;
temp->next=f2;
node* temp2=f2;
while(temp2->next =! NULL)
	temp2=temp2->next;
temp2->next=f3;
return f1;
}
void deleteLast(Dnode* head){
	Dnode* temp=head;
while(temp->next->next =! NULL)
	temp=temp->next;
temp->next=NULL;
}
