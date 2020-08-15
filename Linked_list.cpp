#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    node* gethead()
    {
        return head;
    }

    static void display(node *head)
    {
        if(head == NULL)
        {
            cout << "NULL" << endl;
        }
        else
        {
            cout << head->data << endl;
            display(head->next);
        }
    }

    static void concatenate(node *a,node *b)
    {
        if( a != NULL && b!= NULL )
        {
            if (a->next == NULL)
                a->next = b;
            else
                concatenate(a->next,b);
        }
        else
        {
            cout << "Either a or b is NULL\n";
        }
    }

    void after(node *a, int value)
    {
        node* p = new node;
        p->data = value;
         /*
        if initial linked list is
         _______        _______        _______
        |   1   |____\ |   3   |____\ |   5   |____\ NULL
        |_______|    / |_______|    / |_______|    /
        and new node's value is 10
        then the next line will do something like
         _______        _______        _______
        |   1   |____\ |   3   |____\ |   5   |____\ NULL
        |_______|    / |_______|    / |_______|    /
                        / \
                         |
                         |
                      ___|___
                     |   10  |
                     |_______|
        */
        p->next = a->next;
        a->next = p;
        /*
        now the linked list will look like:
         _______       _______        _______        _______
        |   1   |____\|   10  |____\ |   3   |____\ |   5   |____\ NULL
        |_______|    /|_______|    / |_______|    / |_______|    /
        */
    }

   void reverse(node* rhead){
    if( rhead->next == NULL ){
	    head->next= NULL;
	   head = rhead;
	 cout<<rhead->data<<head->data<<endl;
	
    }else{
    node* temp=rhead->next;
    reverse(rhead->next);
    temp->next =rhead;
         }

    }
  /*  node* reverse(node* head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        * reverse the rest list and put
          the first element at the end *
        node* rest = reverse(head->next);
        head->next->next = head;

        * tricky step -- see the diagram *
        head->next = NULL;

        * fix the head pointer *
        return rest;
    } */
};

int main()
{

    linked_list a;
    a.add_node(1);
    a.add_node(2);
    linked_list b;
    b.add_node(3);
    b.add_node(4);
    linked_list::concatenate(a.gethead(),b.gethead());
    linked_list::display(a.gethead());
   cout<<endl; 
    //linked_list::reverse(a.gethead(),a.gethead());
   a.reverse(a.gethead());
    linked_list::display(a.gethead());
    return 0;
}
