#include"string_stack.h"
#include<iostream>
#include<iomanip>

template<class myData>
StringStack<myData>::StringStack()
{
    Head = NULL;
    length = 0;
}

template<class myData>
StringStack<myData>::StringStack(const StringStack& stack)
{
    // Create first node
    SNode* copy = new node;
    Head = copy;

    // Walk list to copy nodes
    SNode* ptr = stack.Head;
    while (ptr != NULL)
    {
        copy->Next = new node;
        copy = copy->Next;
        copy->input= ptr->input;
        copy->Next = NULL;
        ptr = ptr->Next;
    }
    // Tidy first node
    copy = Head;
    Head = copy->Next;
    delete copy;
}

template<class myData>
StringStack<myData>::~StringStack()
{
    SNode* Temp;
    // Walk stack deleting data
    while (Head != NULL)
    {
        Temp = Head;
        Head = Head->Next;
        delete Temp;
    }
    // Reset head
    Head = NULL;
    length = 0;
}


template<class myData>
bool StringStack<myData>::isFull()
{
    return false;
}


template<class myData>
bool  StringStack<myData>::isEmpty()
{
    return !(length > 0) ? true : false;

}

template<class myData>
void StringStack<myData>::Push(myData s)
{
    if (isFull())
    {
        return;
    }
    //Allocate space
    SNode* temp = new node;
    if (temp == NULL)
    {
        return;
    }
    //Add Data
    temp->input = s;
    temp->Next = Head;
    Head = temp;
    length++;
}

template<class myData>
void StringStack<myData>::Pop(myData& s)
{
    if (isEmpty())
    {
        return;
    }
    s = Head->input;
    SNode* temp = Head;
    Head = Head->Next;
    delete temp;
    length--;
}

template<class myData>
void StringStack<myData>::Top(myData& s)
{
    if (isFull())
    {
        return;
    }
    //Read from node
    s = Head->input;
}

template<class myData>
int StringStack<myData>::GetLength()
{
    return length;
}

template<class myData>
void StringStack<myData>::Print()
{
    // Walk the stack printing data
    std::cout << "stack:\n";
    SNode* Temp = Head;
    while (Temp != NULL)
    {
        std::cout << Temp->input << " \n";
        Temp = Temp->Next;
    }
    std::cout << std::endl;
}