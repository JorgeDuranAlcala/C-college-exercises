#include <iostream>
#include "myqueue.cpp"
using namespace std;
#define REP(i, a, b) for (int i = a; i <= b; i++)

typedef long long ll;
typedef double db;

int main()
{
    ll a = 12345465665566565;
    ll b = 23323233233444444;
    ll c = a * b;
    db x = 24.555;
    Queue<int> *q = new Queue<int>();

    REP(i, 0, 4)
    {
        cout << i << "\n";
    }

    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(34);
    q->enqueue(8);

    q->print();

    int pop = q->dequeue();
    q->dequeue();
    q->dequeue();
    q->dequeue();
    cout << "popped: " << pop << "\n";
    //cout << "front: " << q->peek() << "\n";
    cout << "size: " << q->size() << "\n";

    if (q->isEmpty())
    {
        cout << "the queue is empty";
    }
}