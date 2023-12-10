#include <iostream>

using namespace std;

struct Node
{
    //value to hold
    int data;
    //ptr to next item
    Node* next;
};

class LinkedList
{
private:
    Node* head;
    Node* tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    //push new node to head of list
    void pushNode(int value)
    {
        Node* newHead = new Node;
        newHead->data = value;
        newHead->next = head;
        head = newHead;
    }

    //insert new node to end of list
    void insertToEndNode(int value)
    {
        Node *temp = new Node;
        temp->data = value;
        temp->next = NULL;

        //empty list
        if (head == NULL)
        {
            //one item in list now
            head = temp;
            tail = temp;
        }
        //list has items
        else
        {
            //insert new item to list
            tail->next = temp;
            tail = tail->next;
        }
    }

    //insert at position in list
    void insertPositionNode(int position, int value)
    {
        Node* pre = new Node;
        Node* current = new Node;
        Node* temp = new Node;

        current = head;

        //iterate through list, will always be greater than 1 less the position but not the position itself, so will insert at position
        for (int i = 0; i < position; i++)
        {
            //set current node to be after previous node
            pre = current;
            current = current->next;
        }

        //set previous node to the temp node, then the next will be the current node
        temp->data = value;
        pre->next = temp;
        temp->next = current;
    }

    //delete node at position
    void deleteNode(int position)
    {
        Node* current = head;
        Node* pre = current;

        for (int i = 0; i < position + 1; i++)
        {
            //beginning
            if (i == position && current == head)
            {
                head = head->next;
                break;
            }
            else
            {
                //end
                if (current == tail)
                {
                    pre->next = NULL;
                    tail = pre;
                    break;
                }
                //at position
                else if (i == position)
                {
                    pre->next = current->next;
                    break;
                }
            }
            //move current node
            pre = current;
            current = current->next;
        }
    }

    //print out the list starting at the head
    void printList()
    {
        int dataCounter = 0;
        Node* current = head;

        while (current != NULL)
        {
            cout << "Data " << dataCounter  << ": " << current->data << "\n";
            current = current->next;
            dataCounter++;
        }
    }
};

int main()
{
    //setup linked list
    LinkedList list;
    list.insertToEndNode(1);
    list.insertToEndNode(5);
    list.pushNode(2);
    list.insertPositionNode(1, 7);
    list.printList();

    //test deletion
    cout << "\n";
    list.deleteNode(1);
    list.printList();
    return 0;
}