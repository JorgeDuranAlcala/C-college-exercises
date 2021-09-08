#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX_SIZE 50

string queuevar = "Im from the outside";

template <typename T>
class Queue
{
private:
    T *arr;
    int rear;
    int front;
    int capacity;
    int count;

public:
    Queue();
    ~Queue();
    T peek();
    void enqueue(T item);
    T dequeue();
    bool isEmpty();
    bool isFull();
    void print();
    int size();
};

template <typename T>
int Queue<T>::size()
{
    return count;
}

template <typename T>
void Queue<T>::print()
{
    cout << "[";
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "]\n";
}

template <typename T>
Queue<T>::Queue()
{
    capacity = MAX_SIZE;
    front = 0;
    rear = -1;
    arr = new T[capacity];
    count = 0;
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] arr;
}

template <typename T>
bool Queue<T>::isEmpty()
{
    return (size() == 0);
}

template <typename T>
bool Queue<T>::isFull()
{
    return (size() == capacity);
}

template <typename T>
T Queue<T>::peek()
{
    if (isEmpty())
    {
        cout << "underflow-program-failure"
             << "\n";
        exit(EXIT_FAILURE);
    }

    return arr[front];
}

template <typename T>
void Queue<T>::enqueue(T item)
{
    if (isFull())
    {
        cout << "overflow-program-failure"
             << "\n";
        exit(EXIT_FAILURE);
    }

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    //cout << "item added to queue: " << arr[rear] << "\n";
    count++;
}
template <typename T>
T Queue<T>::dequeue()
{
    if (isEmpty())
    {
        cout << "underflow-program-failure"
             << "\n";
        exit(EXIT_FAILURE);
    }

    T item = arr[front];
    //cout << "removing: " << arr[front] << "\n";
    front = (front + 1) % capacity;
    count--;
    return item;
}
