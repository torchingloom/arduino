#ifndef ArrayT_h
#define ArrayT_h

#include "Arduino.h"

template <class T> class ArrayT
{
private:
  int size;
  int count;
  T* items;
  int resize(int);
public:
  ArrayT();
  ArrayT(int);
  ArrayT(const ArrayT&);
  ~ArrayT();
  int add(const T&);
  T& item(int);
  T& operator[] (int);
  int sizeGet(){return size;};
  int itemCount(){return count;};
};

template <class T> ArrayT<T>::ArrayT(int _size): count(0)
{
  size = _size;
  if (size <= 1) size = 1;
  items = new T[size];
}

template <class T> ArrayT<T>::ArrayT()
{
  ArrayT(5);
}

template <class T> ArrayT<T>::ArrayT(const ArrayT<T> &src)
{
  delete[] items;
  items = new ArrayT<T>(src.size);
  for(int i=0; i <= src.count; i++) add(src[i]);
  size = src.count+1;
  count = src.count;
}

template <class T> ArrayT<T>::~ArrayT()
{
  delete[] items;
}

template <class T> int ArrayT<T>::add(const T& item)
{
  int i = count+1;
  if (i < size) items[i] = item;
  else if (resize(size+1)) items[i] = item;
  count = i;
  return i < size ? i : -1;
}

template <class T> int ArrayT<T>::resize(int new_size)
{
  T* new_items = new T[new_size];
  if (new_items)
  {
    for (int i=0; i <= count; i++) new_items[i] = items[i];
  }
  delete[] items;
  items = new_items;
  return size = new_size;
}

template <class T> T& ArrayT<T>::item(int i)
{
  return items[i];
}


template <class T> T& ArrayT<T>::operator[](int i)
{
  return item(i);
}


#endif