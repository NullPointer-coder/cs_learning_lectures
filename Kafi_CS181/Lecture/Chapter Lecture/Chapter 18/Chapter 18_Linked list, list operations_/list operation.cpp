// Demonstrating various functions of the list doubly linked list class
// @author: Kafi Rahman
#include <iostream>
#include <list>

using namespace std;

// display all the contents from the list
void showTheContent(std::list<int> listVar)
{
    list<int>::iterator it; // using iterator to display values
    for (it = listVar.begin(); it != listVar.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
}

// the driver program
int main()
{

    list<int> listElem = {3, 4, 3, 7, 70, 6};
    // inserting at the back
    listElem.push_back(1);
    listElem.push_back(2);
    listElem.push_back(1);

    listElem.push_front(10);
    listElem.push_front(5);

    cout << "\nContent of List after adding values: ";
    showTheContent(listElem);

    // size() to know the number of elements
    cout << "\nNo. of elements in list: ";
    cout << listElem.size() << "\n";

    //Inserting elements in list at the beginning
    listElem.insert(listElem.begin(), 60);
    cout << "\nAfter Insertion 60 at the beginning: ";
    showTheContent(listElem);

    //Removing first element from the front in listElem.
    cout << "\nFirst element of the list: " << listElem.front();
    cout << "\nLast element of the list: " << listElem.back();

    // after removal, the updated list
    cout << "\n\nAfter removal of first and last boundary elements: ";
    listElem.pop_front(); // removing first element
    listElem.pop_back();  // removing last element
    showTheContent(listElem);

    // sorting the list
    listElem.sort();
    cout << "\nSorted List: ";
    showTheContent(listElem);

    // unique function
    // unique function can only work when the lements are sorted
    listElem.unique();
    cout << "\nAfter using the unique operation of the list: ";
    showTheContent(listElem);

    //Reversing the content of list
    listElem.reverse();
    cout << "\nReversed list: ";
    showTheContent(listElem);

    //remove() to remove all the elements with value 7.
    listElem.push_front(7); // adding 7 twice
    listElem.push_back(7);
    listElem.remove(7);
    cout << "\nAfter Removal of 7 from the list: ";
    showTheContent(listElem);

    //erasing first element of list
    listElem.erase(listElem.begin());
    //listElem.erase(listElem.begin(), listElem.end());
    cout << "\nAfter erasing the first element of the list: ";
    showTheContent(listElem);

    //Removing all elements from list.
    listElem.clear();
    cout << "\nAfter erasing all the elements of the list: ";

    // Use of empty() function
    if (listElem.empty() == true)
        cout << "\nList is now empty\n";
    else
        cout << "\nNot Empty\n";

    return 0;
} 
