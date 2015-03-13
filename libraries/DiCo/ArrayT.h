#ifndef ArrayT_h
#define ArrayT_h

template <class T> class ArrayT
{
private:
  int size;
  int count;
  T* items;
public:
  ArrayT();
  ArrayT(int);
  ArrayT(const ArrayT&);
  ~ArrayT();
  int add(const T&);
  T& item(int);
  T& operator[] (int);
  int sizeGet(){return size;};
};

template <class T> ArrayT<T>::ArrayT(int _size): count(0), size(_size)
{
  if (size > 0) items = new T[size];
}

template <class T> ArrayT<T>::ArrayT()
{
  ArrayT(5);
}

template <class T> ArrayT<T>::ArrayT(const ArrayT<T> &src)
{
  ArrayT<T>(src.size);
  for(int i=0; i < src.size; i++) add(src[i]);
}

template <class T> ArrayT<T>::~ArrayT()
{
  if (size > 0) delete[] items;
}

template <class T> int ArrayT<T>::add(const T& item)
{
  int i = count;
  if (count < size) items[count] = item;
  count++;
  return i < size ? i : -1;
}

template <class T> T& ArrayT<T>::item(int i)
{
  return items[i];
}

template <class T> T& ArrayT<T>::operator[](int i)
{
  item(i);
}

#endif