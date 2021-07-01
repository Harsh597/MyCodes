#include <iostream>
using namespace std;
//Floyd's Algorithm or Hair & Tortoise Algorithm
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
        cout << "NULL";
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
    ll1->add(7);
    ll1->add(8);
    ll1->add(9);

    ll1->display();
    cout << endl;

    cout << ll1->detectcycle();

    cout << endl;
    ll1->createcycle(4);

    cout << (ll1->detectcycle());

    ll1->removecycle();
    cout << endl;

    ll1->display();

    // ll2->add(11);
    // ll2->add(21);
    // ll2->add(31);
    // ll2->add(41);
    // ll2->add(51);
    // ll2->display();

    return 0;
}