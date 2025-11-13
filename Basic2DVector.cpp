#include<iostream>
using namespace std;
/*
with side effects -> modify variable, no return type
without side effect -> const, can't modify, has a return type
*/
class Vector2D
{
    private:
    int x;
    int y;

    public:
    Vector2D(int x = 0, int y = 0);
    bool equals(Vector2D& other);
    
    //side effect addition and substraction:
    void addVectors(Vector2D& other);
    void substractVectors(Vector2D& other);

    //no side effect addition and substraction:
    Vector2D _addVectors(const Vector2D& other) const;
    Vector2D _substractVectors(const Vector2D& other) const;

    void printVector();

};

Vector2D::Vector2D(int x, int y) : x(x), y(y) {}

bool Vector2D::equals(Vector2D& other)
{
    return this->x == other.x && this->y == other.y;
}

void Vector2D::addVectors(Vector2D& other)
{
    //side effects are modifying *this, not the argument
    this->x += other.x;
    this->y += other.y;
}

void Vector2D::substractVectors(Vector2D& other)
{
    //side effects are modifying *this, not the argument
    this->x -= other.x;
    this->y -= other.y;
}

Vector2D Vector2D::_addVectors(const Vector2D& other) const
{
    return Vector2D(this->x + other.x, this->y+other.y);
}

Vector2D Vector2D::_substractVectors(const Vector2D& other) const
{
    return Vector2D(this->x - other.x, this->y - other.y);
}

void Vector2D::printVector()
{
    cout<<"Vector: "<<"("<<this->x<<","<<this->y<<")"<<endl;
}

int main()
{
    Vector2D v1(1,1), v2(2,3) ,v3(4,0), v4(5,2);

    cout<<"Side effects: "<<endl;
    cout<<"Vectors before side effects: "<<endl<<"1.";
    v1.printVector();
    cout<<"2. ";
    v2.printVector();

    cout<<"After addition with side effects: "<<endl;
    v1.addVectors(v2);
    cout<<"1.";
    v1.printVector();
    cout<<"2. ";
    v2.printVector();

    cout<<"After substraction with side effects: "<<endl;
    v1.substractVectors(v2);
    cout<<"1.";
    v1.printVector();
    cout<<"2. ";
    v2.printVector();

    cout<<endl;

    cout<<"No side effects: "<<endl;
    cout<<"Vectors before side effects: "<<endl<<"1.";
    v3.printVector();
    cout<<"2. ";
    v4.printVector();

    Vector2D v5(0,0);
    cout<<"Vector for storing results: ";
    v5.printVector();

    cout<<endl;

    v5= v3._addVectors(v4);
    cout<<"Vector for storing results after adding two vectors: ";
    v5.printVector();

    cout<<endl;

    v5= v3._substractVectors(v4);
    cout<<"Vector for storing results after substracting two vectors: ";
    v5.printVector();

    cout<<endl;

    cout<<"Equality check 1: "<<endl;
    cout<<"1.";
    v1.printVector();
    cout<<"2. ";
    v2.printVector();
    cout<<"Result: "<<v1.equals(v2);

    cout<<endl;

    Vector2D v6(1,1), v7(1,1);
    cout<<endl<<"Equality check 2: "<<endl;
    cout<<"1.";
    v6.printVector();
    cout<<"2. ";
    v7.printVector();
    cout<<"Result: "<<v6.equals(v7);
    
}