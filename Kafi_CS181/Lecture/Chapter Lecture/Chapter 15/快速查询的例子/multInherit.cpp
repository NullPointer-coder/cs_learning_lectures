#include <iostream>
using namespace std;

// override a function
class Box // base class A
{
protected:
    string box_name;

public:
    Box(string name)
    {
        box_name = name;
    }
    string get_name() const { return box_name; }

    void set_name(string name)
    {
        box_name = name;
    }
    void display() const
    {
        cout << "Box: " << box_name << endl;
    }
};

class ColoredBox // Base class B
{
protected:
    string box_name;
    string color;

public:
    ColoredBox(string name, string c)
    {
        box_name = name;
        color = c;
    }
    string get_name() const { return box_name; }

    void setName(string name)
    {
        box_name = name;
    }

    string get_color() const { return color; }

    void set_color(string c)
    {
        color = c;
    }

    void display() const
    {
        cout << "Colored box: " << color << " " << box_name << endl;
    }
};

// an example of multiple inheritance
class StyledBox : public Box, public ColoredBox // derived class C
{
protected:
    string style;

public:
    StyledBox(string name, string color, string s) : Box(name),
                                                     ColoredBox(name, color)
    {
        style = s;
    } 
    void set_style(string s)
    {
        style = s;
    }
    string get_style() const { return style; }
 
     void display() const // redefine the function
     {
         cout << "Styled box: " << style << " " << color << " " << Box::box_name << endl;
     }  
}; 

// driver function
int main()
{
    StyledBox style_box("Amazon Box", "Green", "Border");  

    // box.display(); will be an error, unless redefined
    // either it has be redefined in the derived class, or
    // we can use the scope resolution operator to call
    // the specific display function
    
    style_box.display(); // which one? 

    style_box.Box::display();
    style_box.ColoredBox::display(); 

    // what happens if we try to use the
    // getName or setName functions?
}