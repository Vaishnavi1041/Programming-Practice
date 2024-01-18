// Doubly Circular
#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE, *PNODE;

class DoublyCL
{
    private:
        PNODE first;
        PNODE last;
        int Count;

    public:
        DoublyCL();
        void InsertFirst(int no);
        void InsertLast(int no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(int no,int ipos);
        void DeleteAtPos(int ipos);
};

DoublyCL::DoublyCL()
{
    first = NULL;
    last = NULL;
    Count = 0;
}

void DoublyCL::InsertFirst(int no)
{
    PNODE newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))  // LL is empty
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    last->next= first;
    first->prev = last;
    Count++;
}
void DoublyCL::InsertLast(int no)
{
    PNODE newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))  // LL is empty
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->prev = last;
        last->next= newn;
        last= newn;
    }
    last->next= first;
    first->prev = last;
    Count++;
}
void DoublyCL::Display()
{ 
    PNODE temp = first;

    cout<<"Elements of the linked list are : \n";
    
    while(temp != NULL) 
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp ->next;
    }
    cout<<"NULL \n";
}
int DoublyCL::CountNode()
{
    return Count;
}
void DoublyCL::DeleteFirst()
{
    if((first == NULL) && (last == NULL))    // LL is empty
    {
        return;
    }
    else if(first == last)   // LL contains single node
    {
        free(first);
        first = NULL;
        last = NULL;
    }
    else    // LL contains more than one node
    {
        first = (first)->next;
        free((last)->next);    // free((*Head)->prev);
        (first)->prev = last;
        (last)->next = first;
    }
    Count--;
}
void DoublyCL::DeleteLast()
{
    if((first == NULL) && (last == NULL))    // LL is empty
    {
        return;
    }
    else if(first == last)   // LL contains single node
    {
        free(first);
        first = NULL;
        last = NULL;
    }
    else    // LL contains more than one node
    {
        last = ( last)->next;
        free((last)->next);   
        ( last)->prev = first;
        (first)->next =  last;
    }
    Count--;
}
void DoublyCL::InsertAtPos(int no,int ipos)
{
    PNODE newn = new NODE;
    PNODE temp = first;

    if((ipos < 1) || (ipos >Count+1))
    {
        cout<<"Invalid position\n";
        return;
    }  

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == Count + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int i = 1; i< ipos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
    Count++;
}
void DoublyCL::DeleteAtPos(int ipos)
{
     PNODE temp = first;

    if((ipos < 1) || (ipos >Count+1))
    {
        cout<<"Invalid position\n";
        return;
    }  

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Count + 1)
    {
        DeleteLast();
    }
    else
    {
        for(int i = 1; i< ipos-1; i++)
        {
            temp = temp -> next;
        }

        temp->next=  temp->next->next;
        free(temp->next->next);
        temp->next->prev = temp;
    }
    Count--;
}

int main()
{
    DoublyCL obj;
    int iRet = 0;

    obj.InsertFirst(111);
    obj.InsertFirst(101);
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();

     
    obj.InsertLast(121);
    obj.InsertLast(151);
    obj.InsertLast(201);
    
    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";


    obj.InsertAtPos(105, 5);

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteAtPos(5);

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    return 0;
}