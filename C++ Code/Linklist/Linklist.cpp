#include <iostream>
#include <conio.h>
using namespace std;
class LinkList
{
    class node
    {
    public:
        int data;
        node *next;
        node()
        {
            next = NULL;
        }
    };

public:
    void Display_list(node *head)
    {
        if (head == NULL)
        {
            cout << "\nEmpty Linked List" << endl;
        }
        node *temp = head;
        cout << endl;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
        cout << endl;
    }
    void AddtoHead_list(node *&head)
    {
        node *temp = head;
        int val;

        node *n = new node();
        cout << "\nEnter the element to be added" << endl;
        cin >> n->data;

        if (head == NULL)
        {
            head = n;
        }
        else
        {
            n->next = head;
            head = n;
        }
    }
    void AddtoLast_list(node *&head)
    {
        node *temp = head;
        int val;

        node *n = new node();
        cout << "\nEnter the element to be added" << endl;
        cin >> n->data;

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
            temp->next = n;
        }
    }
    void AddatLoc_list(node *&head)
    {

        node *temp = head;
        int val;
        int loc;
        int size = 0;
        int i = 1;

        node *n = new node();

        cout << "\nEnter the location" << endl;
        cin >> loc;

        while (temp != NULL)
        {
            temp = temp->next;
            size++;
        }
        cout << "size " << size << endl;
        temp = head;
        if (loc == 1)
        {
            AddtoHead_list(head);
            return;
        }
        else if (loc > size + 1)
        {
            cout << "\nInvalid location" << endl;
        }
        else if (loc == size + 1)
        {
            AddtoLast_list(head);
        }
        else
        {
            while (temp != NULL)
            {
                if (i == loc - 1)
                {
                    break;
                }
                temp = temp->next;
                i++;
            }

            cout << "\nEnter the element to be added" << endl;
            cin >> n->data;
            n->next = temp->next;
            temp->next = n;
        }
    }
    void DeletefromHead_list(node *&head)
    {
        int val;
        node *temp = head;
        if (head == NULL)
        {
            cout << "\nLinked List is already empty" << endl;
            return;
        }
        else if (temp->next == NULL)
        {
            val = head->data;
            delete head;
            head = NULL;
        }
        else
        {
            node *todelete = head;
            val = head->data;
            head = head->next;
            delete todelete;
        }
        cout << "\n " << val << " is deleted" << endl;
    }
    void DeletefromEnd_list(node *&head)
    {
        int val;
        node *temp = head;
        if (head == NULL)
        {
            cout << "\nLinked List is already empty" << endl;
            return;
        }
        else if (temp->next == NULL)
        {
            val = head->data;
            delete head;
            head = NULL;
        }
        else
        {
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            node *todelete = temp->next;
            val = todelete->data;
            temp->next = NULL;
            delete todelete;
        }
        cout << "\n " << val << " is deleted" << endl;
    }
    void DeleteatLoc_list(node *&head)
    {
        node *temp = head;
        int val;
        int loc;
        int size = 0;
        int i = 1;

        cout << "\nEnter the location" << endl;
        cin >> loc;

        while (temp != NULL)
        {

            temp = temp->next;
            size++;
        }
        temp = head;
        if (loc == 1)
        {
            DeletefromHead_list(head);
            return;
        }
        else if (loc > size)
        {
            cout << "\nInvalid location" << endl;
        }
        else if (loc == size)
        {
            DeletefromEnd_list(head);
        }
        else
        {
            while (temp != NULL)
            {
                if (i == loc - 1)
                {
                    break;
                }

                temp = temp->next;
                i++;
            }
            node *todeleted = temp->next;
            cout << todeleted->data << " is deleted" << endl;
            temp->next = temp->next->next;
            delete todeleted;
        }
    }
    void Search_list(node *&head)
    {
        int ele;
        cout << "\nEnter the element to be searched" << endl;
        cin >> ele;
        int loc = 1;
        while (head != NULL)
        {
            if (head->data == ele)
            {
                cout << ele << " is present at  location no : " << loc << endl;
                return;
            }
            head = head->next;
            loc++;
        }
        cout << ele << " is not present in the linklist" << endl;
    }
    void ReverseIteratively_list(node *&head)
    {
        node *prev = NULL;
        node *curr = head;
        node *next;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        head = prev;
        // cout << "LinkList is reversed" << endl;
        Display_list(head);
    }
    node *ReverseRecursively_list(node *&head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        node *newhead = ReverseRecursively_list(head->next);
        head->next->next = head;
        head->next = NULL;

        return newhead;
    }
    int length(node *&head)
    {
        int len = 0;
        node *temp = head;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
    node *AppendLastK_Nodes_list(node *&head, int k)
    {
        node *newhead;
        node *newtail;
        node *tail = head;

        int len = length(head);

        int count = 1;

        while (tail->next != NULL)
        {
            if (count == len - k)
            {
                newtail = tail;
                newhead = newtail->next;
            }

            count++;
            tail = tail->next;
        }
        newtail->next = NULL;
        tail->next = head;
        return newhead;
    }

    node *ReverseK_Nodes_list(node *&head, int k)
    {
        node *prev = NULL;
        node *curr = head;
        node *next;
        int count = 0;
        while (curr != NULL && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (next != NULL)
            head->next = ReverseK_Nodes_list(next, k);
        return prev;
    }
    void EvenAfterOdd(node *&head)
    {
        node *odd = head;
        node *even = head->next;
        node *evenstart = even;
        while (odd->next != NULL && even->next != NULL)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
     
        odd->next = evenstart;

        Display_list(head);
    }
    void LinkList_Menu()
    {
        node *head = NULL;
        int choice = 1;
        do
        {

            cout << "\n1) Display Linked List" << endl;
            cout << "2) Add Element To End" << endl;
            cout << "3) Add Element to Head" << endl;
            cout << "4) Add At Location" << endl;
            cout << "5) Delete Element From End" << endl;
            cout << "6) Delete Element From Head" << endl;
            cout << "7) Delete At Location" << endl;
            cout << "8) Search in Linklist" << endl;
            cout << "9) Reverse Linklist Iteratively" << endl;
            cout << "10) Reverse Linklist Recursively" << endl;
            cout << "11) Reverse K Nodes" << endl;
            cout << "12) Append Last K Nodes to start of linked list" << endl;
            cout << "13) Put Even Position Nodes after Odd Position" << endl;

            cout << "14) Exit" << endl;

            fflush(stdin);
            cin >> choice;
            fflush(stdin);
            switch (choice)
            {
            case 1:
                Display_list(head);
                break;
            case 2:
                AddtoLast_list(head);
                break;
            case 3:
                AddtoHead_list(head);
                break;
            case 4:
                AddatLoc_list(head);
                break;
            case 5:
                DeletefromEnd_list(head);
                break;
            case 6:
                DeletefromHead_list(head);
                break;
            case 7:
                DeleteatLoc_list(head);
                break;
            case 8:
                Search_list(head);
                break;
            case 9:
                ReverseIteratively_list(head);
                break;
            case 10:
            {
                node *newhead = ReverseRecursively_list(head);
                head = newhead;
                Display_list(newhead);
            }
            break;
            case 11:
            {
                int k;
                cout << "Enter the value of K" << endl;
                cin >> k;
                node *newhead = ReverseK_Nodes_list(head, k);
                head = newhead;
                Display_list(newhead);
            }
            break;
            case 12:
            {
                int k;
                cout << "Enter the value of K" << endl;
                cin >> k;
                node *newhead = AppendLastK_Nodes_list(head, k);
                head = newhead;
                Display_list(newhead);
            }
            break;
            case 13:
            {
                EvenAfterOdd(head);
                // Display_list(head);
                break;
            }

            case 14:
                exit(1);
                break;

            default:
                break;
            }

        } while (choice != 14);
    }
};

int main()
{
    LinkList *ll = new LinkList();
    ll->LinkList_Menu();
    return 0;
}