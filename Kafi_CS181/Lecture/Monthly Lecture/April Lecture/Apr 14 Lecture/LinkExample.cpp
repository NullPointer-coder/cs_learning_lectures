// Demonstrating the creation of LinkedList
// @author: Kafi Rahman

#include <iostream>

using namespace std;

template <class T>
class LinkedList
{

private:
    // private structure declaration
    struct Node
    {
        T data;
        Node *next;
    };
    // the main pointer of the list
    Node *headPtr;

public:
    // constructor, make the list empty
    LinkedList()
    {
        headPtr = nullptr;
    }

    // add one element to the end of the list
    void append(T data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        // is the list empty, then headPtr should point to the newNode
        if (headPtr == nullptr)
            headPtr = newNode;
        else // otherwise, navigate to the last node of the list
        {
            Node *currentPtr = headPtr;
            while (currentPtr->next != nullptr)
                currentPtr = currentPtr->next;

            // make the last node link to the newNode
            currentPtr->next = newNode;
        }
    }

    // locates the item and removes it from the list
    void deleteNode(T deleteItem)
    {
        Node *current = headPtr; // current points to the headPtr

        if (headPtr == nullptr) // there is nothing to delete
            return;             // do nothing
        else if (headPtr->data == deleteItem)
        {
            headPtr = headPtr->next; // headPtr will now point to the next element
            delete current;          // delete the original head
        }
        else
        {
            Node *previous = current; // previous points to the headPtr
            current = current->next;

            // move to the next element if the current element is not deleteItem
            while (current != nullptr && current->data != deleteItem)
            {
                previous = current;
                current = current->next;
            }

            if (current != nullptr) // have we found the value to be deleted
            {
                // the previous node should point to the node
                // pointed at by current->next, so that the
                // deleteItem node can be removed from the link chain
                previous->next = current->next;
                delete current;
            }
        }
    }

    // displaying all the elements of the list
    void displayNode()
    {
        cout << "\nDisplaying the node elements\n";
        Node *currentPtr = headPtr;
        // as long as currentPtr is pointing to some valid node
        while (currentPtr != nullptr)
        {
            // display the node value
            cout << currentPtr->data << " ";
            // move to the next node
            currentPtr = currentPtr->next;
        }
    }

    // destructor to release allocated memory
    ~LinkedList()
    {
        Node *currentPtr = headPtr;

        // continue as long as there are elements in the list
        while (currentPtr != nullptr)
        {
            // store the next element
            Node *tempNext = currentPtr->next;

            // delete the current element
            delete currentPtr;

            // move to the next element
            currentPtr = tempNext;
        }
    }
};

// driver program
int main()
{
    LinkedList<int> myList;
    myList.append(100);
    myList.append(10);
    myList.append(50);
    myList.append(7);
    myList.append(27);
    myList.append(17);
    myList.append(77);

    // displaying all the values
    myList.displayNode();

    cout << "\ndeleting the value, 27";
    myList.deleteNode(27); // deleting 27
    myList.displayNode();

    cout << "\ndeleting the value, 50";
    myList.deleteNode(50); // deleting 50
    myList.displayNode();

    return 0;
}
