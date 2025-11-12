 #include<iostream>
 using namespace std;

 class Array
 {
    private:
    int *array;
    int capacity;
    int lastIndex;

    public:
    Array(int size);
    void addToArray(int value);
    void printArray();
    ~Array()
    {
    delete[] array;
    }  

 };


 Array::Array(int size)
 {
    capacity=size;
    array= new int[size];
    lastIndex=0;
 }

 void Array::addToArray(int value)
 {

    if(lastIndex==capacity) //last index should be equal to capacity because on line 47 you increment the index value, so 
    {                       // when you are on index full-capacity-th index, it adds element, than index becomes capacity
        cout<<"Can't add another element, array full."<<endl;
        return;
    } else{
        array[lastIndex]=value;
        lastIndex++;
    } 
 }

 void Array::printArray()
 {
    for(int i=0;i<capacity;i++)
    {
        cout<<i+1<<". element: "<<array[i]<<endl;
    }
 }

 int main()
 {
    Array arr1(5);
    for(int i=0;i<5;i++)
    {
        arr1.addToArray(i+1);
    }

    arr1.addToArray(200);
    arr1.addToArray(300);

    arr1.printArray();
 }

