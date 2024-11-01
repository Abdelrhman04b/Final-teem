#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

template <class T>
class DArray
{
private:
    T *data;
    int size;
    int capacity;

    void resize()
    {
        capacity *= 2;
        T *newData = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    DArray() : size(0), capacity(10)
    {
        data = new T[capacity];
    }

    ~DArray()
    {
        delete[] data;
    }

    void append(T item)
    {
        if (size >= capacity)
        {
            resize();
        }
        data[size++] = item;
    }

    void Delete(int index)
    {
        if (index >= 0 && index < size)
        {
            for (int i = index; i < size - 1; i++)
            {
                data[i] = data[i + 1];
            }
            size--;
        }
    }

    void insert(T item, int index)
    {
        if (index >= 0 && index < size)
        {
            data[index] = item;
        }
    }

    void reverse()
    {
        for (int i = 0; i < size / 2; i++)
        {
            T temp = data[i];
            data[i] = data[size - i - 1];
            data[size - i - 1] = temp;
        }
    }

    T &operator[](int index)
    {
        return data[index];
    }

    int getSize() const
    {
        return size;
    }
};