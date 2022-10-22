#ifndef STRING_STACK_H
#define STRING_STACK_H
#include<string>

//Template Declaration
template<class myData >

class StringStack
{
    public:
        StringStack();
        StringStack(const StringStack& stack);
        ~StringStack();

        //Methods
        bool isFull();
        bool isEmpty();
        void Push(myData s);
        void Pop(myData& s);
        void Top(myData& s);
        void Print();
        
        // Getter
        int GetLength();
    
    private:
        struct node
        {
            myData input;
            node* Next;
        };
        typedef node SNode;
        SNode* Head;
        int length;
};
#endif // !STRING_STACK_H
