#include<iostream>

const int num = 5;
int vec[num] = {10, 30, 50, 70, 90};

struct nodeType
{
    int info;
    nodeType *link;
};

nodeType* insertNodeOnLinkedList(int vec[])
{
    nodeType *first, *last, *newNode;
    first = NULL;
    last = NULL;

    for (int i = 0; i<num; i++)
    {
        // std::cout << vec[i] << "\n";
        newNode = new nodeType;
        newNode-> info = vec[i];
        newNode->link = NULL;
        if (first == NULL)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->link = newNode;
            last = newNode;
        }
    }

    return first;
}

void printLinkedList(nodeType *first)
{
    int num, counter;
    nodeType *current;
    current = first;
    counter = 0;

    while (current != NULL)
    {
        std::cout << "Element #" << counter << ": " << current->info <<"\n";
        current = current->link;
        counter++;
    }
}

int main()
{
    int num = 2;
    nodeType *first;
    first = insertNodeOnLinkedList(vec);
    printLinkedList(first);
}