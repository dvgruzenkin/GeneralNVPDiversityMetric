/*
One of 3 N-versions created for science experiment.

This experiment describes in article "General diversity metric for N-version software".
Experiment is carried out in Denis V. Gruzenkin PhD thesis writing.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct intList
{
    int value;
    struct intList* next;
} IntList;

IntList* SwapItems(IntList* list, IntList* first, IntList* second);
IntList* SortList(IntList* list);
void PrintList(IntList* item);
void PrintItem(IntList* oneItem);
void DeleteList(IntList* list);
IntList* CreateItem(int newValue);
IntList* InsertAfter(IntList* leftItem, IntList* insertedItem);
IntList* GetTail(IntList* list);
IntList* PushBack(IntList* list, IntList* insertedItem);


int main()
{
    /*IntList* list = CreateItem(9);
    PushBack(list, CreateItem(0));
    PushBack(list, CreateItem(-6));
    PushBack(list, CreateItem(18));
    PushBack(list, CreateItem(34));
    PushBack(list, CreateItem(3));
    PushBack(list, CreateItem(24));*/

    IntList* list = CreateItem(-20);
    PushBack(list, CreateItem(10));
    PushBack(list, CreateItem(8));
    PushBack(list, CreateItem(48));
    PushBack(list, CreateItem(-5));
    PushBack(list, CreateItem(4));
    PushBack(list, CreateItem(-25));

    PrintList(list);
    list = SortList(list);
    DeleteList(list);

    return 0;
}

IntList* SwapItems(IntList* list, IntList* first, IntList* second)
{
    if (list == first)
    {
        first->next = second->next;
        second->next = first;
        return second;
    }
    IntList* p = list;
    while (p->next != NULL)
    {
        if (p->next == first)
            break;
        p = p->next;
    }
    p->next = second;
    first->next = second->next;
    second->next = first;
    return list;
}

IntList* SortList(IntList* list)
{
    int bWasModified = 0;
    IntList* head = list;
    do
    {
        bWasModified = 0;
        IntList* cur = head;
        while (cur != NULL && cur->next != NULL)
        {
            if (cur->value > cur->next->value)
            {
                head = SwapItems(head, cur, cur->next);
                bWasModified = 1;
            }
            else
                cur = cur->next;
        }
        PrintList(head);
    } while (bWasModified);
    return head;
}

void PrintList(IntList* item)
{
    printf("\n");
    while (item != NULL)
    {
        PrintItem(item);
        item = item->next;
    }
}

void PrintItem(IntList* oneItem)
{
    printf("%d\t", oneItem->value);
}

void DeleteList(IntList* list)
{
    while (list)
    {
        IntList* tmp = list;
        list = list->next;
        free (tmp);
    }
}

IntList* CreateItem(int newValue)
{
    IntList* newItem = (IntList*) malloc(sizeof(IntList));
    newItem->value = newValue;
    newItem->next = NULL;
    return newItem;
}

IntList* InsertAfter(IntList* leftItem, IntList* insertedItem)
{
    if (leftItem != NULL)
    {
        insertedItem->next = leftItem->next;
        leftItem->next = insertedItem;
    }
    return insertedItem;
}

IntList* GetTail(IntList* list)
{
    if (list == NULL)
        return NULL;
    while (list->next != NULL)
        list = list->next;
    return list;
}

IntList* PushBack(IntList* list, IntList* insertedItem)
{
    return InsertAfter(GetTail(list), insertedItem);
}


