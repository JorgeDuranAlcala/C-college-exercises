#include <iostream>
using namespace std;
#define MAX_ARR_SIZE 100

template <typename T>
class Array
{
private:
    T *arr;
    int count;
    int capacity;

public:
    Array(int size = MAX_ARR_SIZE)
    {
        capacity = size;
        arr = new T{capacity};
        count = 0;
    }
    ~Array()
    {
        delete[] arr;
    }
    void push(T item)
    {
        if (isFull())
        {
            cout << "overflow/program/crashed"
                 << "\n";
            exit(EXIT_FAILURE);
        }

        arr[count] = item;
        count++;
    }
    int size()
    {
        return count;
    }
    bool isFull()
    {
        return (size() == capacity);
    }
    void print()
    {
        cout << "[";
        for (int i = 0; i < size(); i++)
        {
            cout << arr[i] << ", ";
        }
        cout << "]\n";
    }

    Array<T> *slice(int start, int end)
    {
        Array<T> *slicedArr = new Array<T>();
        for (int i = start; i < end; i++)
        {
            slicedArr->push(arr[i]);
        }
        return slicedArr;
    }

    bool includesHelper(int left, int right, T target)
    {
        while (left <= right)
        {
            int middleIndex = (left + right) / 2;
            int middleElement = arr[middleIndex];
            if (middleElement == target)
                return true;
            else if (target > middleElement)
            {
                left++;
            }
            else if (target < middleElement)
            {
                right--;
            }
        }
        return false;
    }

    bool includes(T target)
    {
        return includesHelper(0, size(), target);
    }
};
