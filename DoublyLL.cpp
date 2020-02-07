#include <iostream>
#include <typeinfo>

using namespace std;

template <class t>

class abc
{
    struct node
    {
        t data;
        node* prev;
        node* next;
    };
    node* head=nullptr;
    node* ptr;
    node* temp;
    node* temp1;
    node* temp2;
public:
    inline void newNode();
    void insNode(t value);
    void trav(t b);
    void insNewNode(t value,t pos);
    void delNode(t value);
    void insNodeAtBeg(t value);
    void insNodeAtLast(t vlaue);
};

template<class t>
void abc<t>::insNodeAtLast(t value)
{
    newNode();
    ptr->data=value;
    ptr->next=nullptr;
    ptr->prev=temp;
    temp->next=ptr;
    temp=ptr;
    cout<<"\nInsertion of data "<<ptr->data<<" at end is successfully done!!!"<<endl;
}

template<class t>
void abc<t>::insNodeAtBeg(t value)
{
    newNode();
    temp1=head;
    ptr->data=value;
    ptr->prev=nullptr;
    ptr->next=head;
    head=ptr;
    temp1->prev=ptr;
    cout<<"\nInsertion of data "<<ptr->data<<" at beginning is successfully done!!!"<<endl;
}

template<class t>
void abc<t>::delNode(t value)
{
    ptr=temp1=temp2=head;
    int c=0;
    while(ptr->data not_eq value)
    {
        ptr=ptr->next;
        c++;
    }
    for(int i=1;i<c;++i)
        temp1=temp1->next;
    for(int i=1;i<=c+1;++i)
        temp2=temp2->next;

    //cout<<temp1->data<<"   "<<ptr->data<<"   "<<temp2->data<<endl;
    temp1->next=ptr->next;
    temp2->prev=ptr->prev;
    cout<<"\nDeletion of data "<<ptr->data<<" is successfully done!!!"<<endl;
    delete ptr;
}

template<class t>
void abc<t>::insNewNode(t value,t pos)
{
    newNode();
    ptr->data=value;
    temp1=temp2=head;
    for(int i=1;i<pos-1;++i)
        temp1=temp1->next;
    for(int i=1;i<pos;++i)
        temp2=temp2->next;
    ptr->prev=temp2->prev;
    ptr->next=temp1->next;
    temp1->next=ptr;
    temp2->prev=ptr;
    cout<<"\nInsertion of data "<<ptr->data<<" at position "<<pos<<" is successfully done!!!"<<endl;
}

template<class t>
inline void abc<t>::newNode()
{
    ptr=new node;
}

template<class t>
void abc<t>::insNode(t value)
{
    newNode();
    ptr->data=value;
    ptr->next=ptr->prev=nullptr;
    if(head==nullptr)
        head=ptr;
    else
    {
        temp->next=ptr;
        ptr->prev=temp;
    }
    temp=ptr;
}

template<class t>
void abc<t>::trav(t b)
{
    ptr=head;
    if(b==1)
    {
        while(ptr not_eq nullptr)
        {
            cout<<ptr->data<<"-->";
            ptr=ptr->next;
        }
    }
    else if(b==0)
    {
        while(ptr not_eq temp)
            ptr=ptr->next;
        while(ptr not_eq nullptr)
        {
            cout<<ptr->data<<"-->";
            ptr=ptr->prev;
        }
    }
    else
    {
        cout<<"Invalid choice!!!"<<endl;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    int n;
    abc<int> b;
    b.insNode(1);
    b.insNode(2);
    b.insNode(3);
    b.insNode(4);
    b.insNode(5);
    b.insNode(6);
    cout<<"travel from front press 1 else travel from back press 0 : ";
    cin>>n;
    b.trav(n);
    b.insNewNode(89,4);
    cout<<"travel from front press 1 else travel from back press 0 : ";
    cin>>n;
    b.trav(n);
    b.delNode(3);
    cout<<"travel from front press 1 else travel from back press 0 : ";
    cin>>n;
    b.trav(n);
    b.insNodeAtBeg(0);
    cout<<"travel from front press 1 else travel from back press 0 : ";
    cin>>n;
    b.trav(n);
    b.insNodeAtLast(9);
    cout<<"travel from front press 1 else travel from back press 0 : ";
    cin>>n;
    b.trav(n);

    cout<<"\n\n"<<typeid(b).name()<<endl;
    return 0;
}
