#include <iostream>
using namespace std;
class CircularLinkList
{
    struct node
    {
        int data;
        node *next;
        node(int val)
        {
            data = val;
            next = NULL;
        }
    };
    node *head;

public:
    CircularLinkList()
    {
        head = NULL;
    }
    void deleteAtHead()
    {
        if (head == NULL)
        {
            cout << "Circular LinkList is already empty" << endl;
            return;
        }
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        node *todelete = head;
        temp->next = head->next;
        head = head->next;
        cout << endl
             << todelete->data << " is deleted" << endl;
        delete todelete;
        // if (head->next = head)
        // {
        //     node *todelete = head;
        //     cout << todelete->data << " is deleted" << endl;
        //     delete todelete;
        //     return;
        // }
    }
    void deleteatEnd()
    {
        if (head == NULL)
        {
            cout << "Circular LinkList is already empty" << endl;
            return;
        }
        if (head->next == head)
        {
            node *todelete = head;
            cout << endl
                 << todelete->data << " is deleted" << endl;
            delete todelete;
            return;
        }
        node *temp = head;

        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        node *todelete = temp->next;
        temp->next = todelete->next;
        cout << endl
             << todelete->data << " is deleted" << endl;
        delete todelete;
    }
    void deleteAt(int pos)
    {
        if (pos == 1)
        {
            deleteAtHead();
            return;
        }
        node *temp = head;
        int count = 1;

        do
        {

            temp = temp->next;
            count++;
            if (temp == head)
            {
                cout << "\nInvalid Location" << endl;
                return;
            }
        } while (count != pos);
        if (temp->next = head)
        {
            deleteatEnd();
            return;
        }
        node *todelete = temp->next;
        temp->next = temp->next->next;
        cout << endl
             << todelete->data << " is deleted" << endl;
        delete todelete;
    }
    void addatHead(int val)
    {
        node *newnode = new node(val);
        if (head == NULL)
        {
            head = newnode;
            newnode->next = head;
            return;
        }
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }
    void addatEnd(int val)
    {
        node *newnode = new node(val);
        if (head == NULL)
        {
            addatHead(val);
            return;
        }
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
    void display()
    {
        node *temp = head;
        if (head == NULL)
        {
            cout << "NULL";
            return;
        }
        do
        {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << head->data;
    }
};
int main()
{
    CircularLinkList *cll = new CircularLinkList();
    cll->addatEnd(1);
    cll->addatEnd(2);
    cll->addatEnd(3);
    cll->addatEnd(4);
    cll->addatEnd(5);
    cll->addatEnd(6);
    cll->addatHead(0);
    cll->display();
    cll->deleteAt(7);
    // cll->deleteAtHead();
    cll->display();

    return 0;
}