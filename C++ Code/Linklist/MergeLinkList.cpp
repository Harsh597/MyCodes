#include <iostream>
using namespace std;
class LinkList
{
public:
    class node
    {
    public:
        int data;
        node *next;
        node()
        {
            next = NULL;
        }
        node(int val)
        {
            data = val;
            next = NULL;
        }
    };

private:
    node *head;

public:
    LinkList()
    {
        head = NULL;
    }
    void add(int val)
    {
        node *n = new node(val);
        node *temp = head;
        if (head == NULL)
        {
            head = n;
            return;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = (n);
        }
    }
    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void merge(LinkList *ll2)
    {
        node *temp=new node(-1);
        node* todelete=temp;
        LinkList *ll1 = this;
        node *ptr1 = ll1->head;
        node *ptr2 = ll2->head;

        while (ptr1 != NULL && ptr2 != NULL)
        {
            if (ptr1->data < ptr2->data)
            {
                temp->next = ptr1;
                ptr1 = ptr1->next;
            }
            else
            {
                temp->next = ptr2;
                ptr2= ptr2->next;
            }
            temp=temp->next;
        }
        // ll1->head=todelete;
        // ll1->display();
        // exit(1);
        while(ptr1!=NULL)
        {
            temp->next=ptr1;
            temp=temp->next;
            ptr1=ptr1->next;
        }
        while(ptr2!=NULL)
        {
            temp->next=ptr2;
            temp=temp->next;
            ptr2=ptr2->next;
        }
       ll2->head=ll1->head=todelete->next;
       

       delete todelete;
        // exit(1);
    }
};
int main()
{
    LinkList *ll1 = new LinkList();
    LinkList *ll2 = new LinkList();
    ll2->add(1);
    ll2->add(4);
    ll2->add(5);
    ll2->add(7);
    ll1->add(2);
    ll1->add(3);
    ll1->add(6);
    ll2->add(9);

    ll1->display();
    ll2->display();

    ll2->merge(ll1);
    ll1->display();
    ll2->display();


    return 0;
}