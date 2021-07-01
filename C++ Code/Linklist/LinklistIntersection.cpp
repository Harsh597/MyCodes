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
    void intersect(LinkList *&ll2, int pos)
    {
        LinkList *ll1 = new LinkList();
        ll1 = this;

        node *temp1 = ll1->head;
        while (--pos)
        {
            temp1 = temp1->next;
            if(temp1==NULL)
            {
                cout<<"Intersection not possible"<<endl;
                return;
            }
        }
        node *temp2 = ll2->head;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp1;
    }
    int length(LinkList *&ll)
    {
        int len = 0;
        node *temp = ll->head;
        while (temp != NULL)
        {
            temp = temp->next;
            len++;
        }
        return len;
    }
    int Isintersection(LinkList *&ll2)
    {
        LinkList *ll1 = this;
        int len1 = length(ll1);
        int len2 = length(ll2);
        int pos;
        node *head1;
        node *head2;

        if (len1 > len2)
        {
            pos = len1 - len2;
            head1 = ll1->head;
            head2 = ll2->head;
        }
        else
        {
            pos = len2 - len1;
            head1 = ll2->head;
            head2 = ll1->head;
        }
        int cur = 0;
        while (pos)
        {
            
            head1 = head1->next;
            if(head1==NULL)
            return -1;
            pos--;
            
        }
        while (head1 != NULL && head2 != NULL)
        {
            if (head1 == head2)
            {
                return head->data;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return -1;
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
   
    void createcycle(int pos)
    {
        node *temp = head;
        node *startnode = new node();
        int count = 1;
        while (temp->next != NULL)
        {
            if (count == pos)
            {
                startnode = temp;
            }
            temp = temp->next;
            count++;
        }
        temp->next = startnode;
    }
    bool detectcycle()
    {
        node *slow = head;
        node *fast = head;

        while (fast != NULL && fast->next != NULL)
        {

            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
    void removecycle()
    {
        node *slow = head;
        node *fast = head;
        do
        {

            slow = slow->next;
            fast = fast->next->next;

        } while (slow != fast);
        slow = head;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
};
int main()
{
    LinkList *ll1 = new LinkList();
    LinkList *ll2 = new LinkList();
    ll1->add(1);
    ll1->add(2);
    ll1->add(3);
    ll1->add(4);
    ll1->add(5);
    ll1->add(6);
    ll2->add(9);
    ll2->add(10);
    cout << "Intersection: " << ll1->Isintersection(ll2) << endl;

    ll1->display();
    ll2->display();
   ll1->intersect(ll2, 5);
    ll1->display();
    ll2->display();

    cout << "Intersection: " << ll1->Isintersection(ll2) << endl;
}