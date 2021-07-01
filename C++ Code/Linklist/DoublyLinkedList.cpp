#include <iostream>
#include <conio.h>
using namespace std;
class DoublyLinkList
{
private:
    class node
    {
    public:
        int data;
        node *prev;
        node *next;
        node(int val)
        {
            data = val;
            prev = NULL;
            next = NULL;
        }
    };

    node *head;

public:
    void deleteHead()
    {
        if (head == NULL)
        {
            cout << "Doubly Linked List is already empty" << endl;
            return;
        }
        node *todelete = head;

        if (head->next != NULL)
        {
            head->next->prev = NULL;
            head = head->next;
        }
        else
        {
            todelete = head;
            head = NULL;
        }
        cout << todelete->data << " is deleted" << endl;
        delete todelete;
    }
    void deleteEnd()
    {
        if (head == NULL)
        {
            cout << "Doubly Linked List is already empty" << endl;
            return;
        }
        node *temp = head;
        node *todelete;
        if (temp->next == NULL)
        {
            todelete = head;
            head = NULL;
            //return;
        }
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        todelete = temp;
        if (temp->prev != NULL)
            temp->prev->next = NULL;

        cout << todelete->data << " is deleted" << endl;
        delete todelete;
    }
    void deleteat(int loc)
    {
        int count = 1;

        if (loc == 1)
        {
            deleteHead();
            return;
        }
        node *temp = head;
        node *todelete;

        do
        {

            temp = temp->next;
            if (temp == NULL)
            {
                cout << "\nInvalid location" << endl;
                return;
            }
            count++;
        } while (count != loc);
        todelete = temp;
        if (temp->next != NULL && temp->prev != NULL)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        else if (temp->next == NULL)
        {
            deleteEnd();
            return;
        }

        cout << todelete->data << " is deleted" << endl;

        delete todelete;
    }
    void addatLoc(int val, int loc)
    {
        node *temp = head;
        node *newnode = new node(val);
        int count = 1;
        if (loc == 1)
        {
            addatHead(val);
            return;
        }

        while (count != loc - 1 && temp->next != NULL)
        {
            temp = temp->next;
            count++;
        }

        if (count < loc - 1)
        {
            cout << "\nInvalid Location" << endl;
        }
        else if (temp->next == NULL)
        {
            addatEnd(val);
        }

        else
        {
            temp->next->prev = newnode;
            newnode->next = temp->next;

            temp->next = newnode;
            newnode->prev = temp;
        }
    }
    void addatEnd(int val)
    {
        node *temp = head;
        node *newnode = new node(val);
        if (head == NULL)
        {
            addatHead(val);
            return;
        }
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    void addatHead(int val)
    {
        node *newnode = new node(val);
        if (head == NULL)
        {
            head = newnode;
            return;
        }

        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "NULL" << endl;
            return;
        }
        node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main()
{
    DoublyLinkList *dll = new DoublyLinkList();
    dll->addatEnd(1);
    dll->addatEnd(2);
    dll->addatEnd(3);
    dll->addatEnd(5);

    dll->display();
    //  dll->addatLoc(10, 1);
    //dll->display();

    cout << endl;
    dll->deleteat(1);
    dll->display();
    dll->deleteat(1);
    dll->display();
    dll->deleteat(1);
    dll->display();
    dll->deleteat(1);
    dll->display();
    dll->deleteat(1);
    //  dll->deleteEnd();
    //  dll->display();
    //  dll->deleteEnd();
    //  dll->display();
    //  dll->deleteEnd();
    //dll->display();

    // dll->deleteHead();
    // dll->display();

    // dll->deleteHead();

    // //dll->addatLoc(10, 5);
    // cout << endl;

    // dll->display();
    // dll->deleteHead();

    // dll->display();

    return 0;
}