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

            delete current; // delete the original head
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
    // this is the driver function
    void displayNode()
    {
        cout <<"\nThe elements are the following: " << endl;
        Node *currentPtr = headPtr;
        displayNodePrivate(currentPtr);
    }
    
    // recursive method to display the content of the node
    void displayNodePrivate(Node * current)
    {
        if(current == nullptr)
            return; // we are done
        else
        {   
            displayNodePrivate(current ->next);
            // display the current data, and go to the next node
            cout << current->data << endl;
        };       
    }
    
    
    // driver function
    int sizeList()
    {
        Node *currentPtr = headPtr;
        int size = sizeListPrivate(currentPtr);
        return size;
    }
    
    // recursive method to count the number of nodes
    int sizeListPrivate(Node * current)
    {
        if(current == nullptr)
            return 0; // we are done
        else
        {   
            return 1 + sizeListPrivate(current ->next);
        };       
    }
    
};


// driver program
int main()
{
    LinkedList<int> myList;
    myList.append(5);
    myList.append(100);
    myList.append(50);
    myList.append(505);
    myList.append(25);
    myList.append(10);
    myList.append(90000);

    // displaying all the values
    myList.displayNode();
    cout << "The size of the list is: " << myList.sizeList() << endl;
 
    return 0;
}