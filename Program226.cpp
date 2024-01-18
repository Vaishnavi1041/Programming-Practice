// Singly Circular
#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE;

class SinglyCL
{
    private:
        PNODE first;
        PNODE last;
        int Count;

    public:
        SinglyCL();
        void InsertFirst(int no);
        void InsertLast(int no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(int no,int ipos);
        void DeleteAtPos(int ipos);
};

SinglyCL::SinglyCL()
{
    first = NULL;
    last = NULL;
    Count = 0;
}

void SinglyCL::InsertFirst(int no)
{
    PNODE newn = new NODE;
    newn->data = no;
    newn->next = NULL;
     if ((first==NULL) && (last == NULL)) //LL is empty
    {
        first= newn;
        last = newn;
    }
    else //LC contains Atleast 1 node
    {
        newn->next =first;
       last = newn; //#
    }   
    (last)->next =first;
    Count++;
}
void SinglyCL::InsertLast(int no)
{
    PNODE newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    
    if((first == NULL) && (last == NULL))  // LL is empty
    {
        first = newn;
        last = newn;
        (last)->next = first;
     }
    else    // LL contains atleast 1 node
    {
        (last)->next = newn;
         last = newn;
        (last)->next = first;
    }
    Count++;
}
void SinglyCL::Display()
{
    PNODE temp = first;
    cout<<"Elements of the linked list are : \n";
    
    if((first != NULL) && (last != NULL)) // Type 1
    {
        do
        {
            cout<<"|"<<temp->data<<"|->";
            temp = temp -> next;
        }while(temp != last->next);

        printf("Address of Fisrt node\n");
    }
}
int SinglyCL::CountNode()
{
    return Count;
}
void SinglyCL::DeleteFirst()
{
     if(first == NULL &&  last == NULL)  // Case 1
    {
        return;
    }
    else if(first ==  last) // Case 2
    {
        free(first);
        first = NULL;
         last = NULL;
    }
    else    // Case 3
    {
        (first) = first->next;
        free(( last)->next);
        ( last)->next = first;
    }
    Count--;
}
void SinglyCL::DeleteLast()
{
     PNODE temp = first;

    if(first== NULL && last == NULL)  
    {
        return;
    }
    else if(first == last) 
    {
       free(first);
       first= NULL;
       last = NULL;
    }
    else    
    {
        while(temp->next != last)
        {
	        temp = temp->next;
        }
        free(last);
        last = temp;
        (last)->next = first;
    }    
    Count--;
}
void SinglyCL::InsertAtPos(int no,int ipos)
{
    PNODE newn = NULL;

    PNODE temp = first;

    if((ipos < 1) || (ipos > Count+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
       InsertFirst(no); 
    }
    else if(ipos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new NODE;
        newn->data = no;
        newn->next = NULL;

        for(int i =1; i< ipos-1; i++)
        {
            temp = temp ->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
    Count++;
}
void SinglyCL::DeleteAtPos(int ipos)
{
    PNODE temp = first;
    PNODE targatednode = NULL;

    if((ipos < 1) || (ipos > Count))
    {
        printf("Invalid position\n");
        return;
    }

    if(ipos == 1)
    {
       DeleteFirst(); 
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {
        for(int i =1; i< ipos-1; i++)
        {
            temp = temp ->next;
        }

        targatednode = temp->next;
        temp->next = temp->next->next;
        free(targatednode);
    }
    Count--;
}

int main()
{
    SinglyCL obj;
    int iRet = 0;

    obj.InsertFirst(111);
    obj.InsertFirst(101);
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    
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