#ifndef AssocArray_h
#define AssocArray_h

#include <ArrayT.h>
#include <Arduino.h>

template <class T> class AssocArrayT
{
private:
  ArrayT<String>* keys;
  ArrayT<T>* items;
public:
  AssocArrayT();
  AssocArrayT(int);
  ~AssocArrayT();
  int add(const char*, const T);
  int add(const String, const T);
  T* find(const char*);
  T* find(String);
  T* operator[](const char*);
  int sizeGet(){return keys->sizeGet();};
};

template <class T> AssocArrayT<T>::AssocArrayT(int _size)
{
  keys = new ArrayT<String>(_size);
  items = new ArrayT<T>(_size);
}

template <class T> AssocArrayT<T>::AssocArrayT()
{
  AssocArrayT(5);
}

template <class T> AssocArrayT<T>::~AssocArrayT()
{
  delete keys;
  delete items;
}

template <class T> int AssocArrayT<T>::add(const String key, const T item)
{
  int i = keys->add(key);
  if (i >= 0) items->add(item);
  return i;
}

template <class T> int AssocArrayT<T>::add(const char* key, const T item)
{
  AssocArrayT<T>::add(String(key), item);
}

template <class T> T* AssocArrayT<T>::find(String key)
{
  T* item = NULL;
  int size = sizeGet();

  if (size)
  {
    for (int i=0; i < size; i++)
    {
      if (key == keys->item(i))
      {
        item = &(items->item(i));
        break;
      }
    }
  }
  return item; 
}

template <class T> T* AssocArrayT<T>::find(const char* key)
{
  return find(String(key));
}

template <class T> T* AssocArrayT<T>::operator[](const char* key)
{
  return find(key);
}

#endif