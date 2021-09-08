#include <iostream>
using namespace std;

typedef struct Node
{
    int val;
    struct Node *next;
} ND;

void printNodes(ND *head);
void printNodesRecursively(ND *head);
int sumList(ND *head);
int sumListHelper(ND *head, int result);
int getNodeValue(ND *head, int index);
ND *reverseLinkedList(ND *head);
ND *reverseLinkedListRec(ND *head, ND *prev);
ND *zipperList(ND *l1, ND *l2);
ND *searchNode(ND *list, int key);

int main()
{
    ND a;
    ND b;
    ND c;
    ND d;
    a.val = 1;
    b.val = 2;
    c.val = 3;
    d.val = 4;
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = nullptr;

    ND x;
    ND y;
    ND z;
    x.val = 30;
    y.val = 31;
    z.val = 32;
    x.next = &y;
    y.next = &z;
    z.next = nullptr;

    ND *zp = zipperList(&a, &x);

    printNodesRecursively(zp);
    ND *found = searchNode(&a, 3);
    cout << "node found ";
    printNodesRecursively(found);

    /*cout << getNodeValue(&a, 4) << "\n";
    cout << "linked before reversion"
         << "\n";
    printNodesRecursively(&a);
    cout << "\n"
         << "reversed linkedList using a recursivity approach"
         << "\n";
    ND *rr = reverseLinkedListRec(&a, nullptr);
    printNodesRecursively(rr); */

    return 0;
}

void printNodes(ND *head)
{
    if (head == nullptr)
        return;
    ND *current = head;

    while (current != nullptr)
    {
        cout << current->val;
        current = current->next;
    }
    cout << "\n";
}

void printNodesRecursively(ND *head)
{
    if (head != nullptr)
    {
        cout << head->val << ", ";
        printNodesRecursively(head->next);
    }
    else
    {
        cout << "\n";
    }
}

int sumList(ND *head)
{
    return sumListHelper(head, 0);
}

int sumListHelper(ND *head, int result)
{
    if (head == nullptr)
    {
        return result;
    }

    return sumListHelper(head->next, head->val + result);
}

int getNodeHelper(ND *head, int index, int steps)
{
    if (head == nullptr)
        return -1;
    if (steps == index)
    {
        return head->val;
    }

    return getNodeHelper(head->next, index, steps + 1);
}

int getNodeValue(ND *head, int index)
{
    return getNodeHelper(head, index, 0);
}

ND *reverseLinkedList(ND *head)
{
    /*
        null 1->2->3->null
        null<-1 2->3->null
        null<-1<-2 3-> null
    */
    ND *currentNode = head;
    ND *prev = nullptr;
    while (currentNode != nullptr)
    {
        ND *nextNode = currentNode->next;
        currentNode->next = prev;
        prev = currentNode;
        currentNode = nextNode;
    }

    return prev;
}

ND *reverseLLRecHelper(ND *head, ND *prev = nullptr)
{
    if (head == nullptr)
    {
        return prev;
    }
    ND *next = head->next;
    head->next = prev;
    prev = head;
    return reverseLLRecHelper(next, prev);
}

ND *reverseLinkedListRec(ND *head, ND *prev)
{
    if (head == nullptr)
    {
        return prev;
    }
    ND *next = head->next;
    head->next = prev;
    prev = head;
    return reverseLLRecHelper(next, prev);
}

ND *zipperList(ND *l1, ND *l2)
{
    ND *c1 = l1->next;
    ND *c2 = l2;
    // a->b->c->d
    // x->y->z
    // a->x->b->y->c->z->d
    ND *tail = l1;
    int count = 0;
    while (c2 != nullptr && c1 != nullptr)
    {

        if ((count % 2) == 0)
        {
            tail->next = c2;
            c2 = c2->next;
        }
        else
        {
            tail->next = c1;
            c1 = c1->next;
        }

        /* cout << "(" << c1->val << "," << c2->val << ") "
             << "count: " << count % 2 << " "; */

        /*  c1 = c1->next;
        c2 = c2->next; */
        tail = tail->next;

        count++;
    }
    if (c1 != nullptr)
        tail->next = c1;
    if (c2 != nullptr)
        tail->next = c2;

    return l1;
}

ND *searchNode(ND *list, int key)
{
    ND *head = list;
    while (head != nullptr && head->val != key)
    {
        head = head->next;
    }
    return head;
}
