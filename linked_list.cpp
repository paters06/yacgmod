#include<iostream>

// The code for linked lists were obtained from
// chapter 16, p1047
// C++Programming Design including Data Structures
// from D. S. Malik

template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

template <class Type>
class LinkedListType
{
    public:
    const linkedListType<Type>& operator= (const linkedListIterator<Type>&);
    
    void initializeList();

    bool isEmptyList() const;

    void print() const;

    int length() const;

    void destroy();

    Type front() const;

    Type back() const;

    virtual bool search(const Type& searchItem) const = 0;

    virtual bool insetrFirst(const Type& newItem) const = 0;

    virtual bool insertLast(const Type& newItem) const = 0;

    virtual bool deleteNode(const Type& deleteItem) const = 0;

    linkedListIterator<Type> begin();

    linkedListIterator<Type> end();

    linkedListType();

    linkedListType(const linkedLisrType<Type>& otherList);
    
    ~linkedListType();

    protected:
        int count;
        nodeType<Type> *first;
        nodeType<Type> *last;
    
    private:
        void copyList(const linkedListType<Type>& otherList);
};

template <class Type>
class linkedListIterator
{
    public:
        linkedListIterator();

        linkedListIterator(nodeType<Type> *ptr);

        Type operator*();

        linkedListIterator<Type> operator++();

        bool operator==(const linkedListIterator<Type>& right) const;

        bool operator!=(const linkedListIterator<Type>& right) const;
    
    private:
        nodeType<Type> *current;
};

template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
    current = NULL;
}

template <class Type>
linkedListIterator<Type>:: linkedListIterator(nodeType<Type> *ptr)
{
    current = ptr;
}

template <class Type>
Type linkedListIterator<Type>::operator* ()
{
    return current->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++ ()
{
    current = current -> link;
    return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator== (const linkedListIterator<Type>& right) const
{
    return (current == right.current)
}

template <class Type>
bool linkedListIterator<Type>::operator!= (const linkedListIterator<Type>& right) const
{
    return (current != right.current)
}

int main()
{
    return 0;
}