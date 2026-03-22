#ifndef TOP_IT_VECTOR_HPP
#define TOP_IT_VECTOR_HPP

#include <cstddef>

namespace petrovVadim
{
  template< class T >
  struct Vector
  {
    Vector();
    ~Vector();
    Vector(const Vector&);
    Vector(Vector&&);
    Vector& operator=(const Vector&);
    Vector& operator=(Vector&&);

    bool isEmpty() const noexcept;
    size_t getSize() const noexcept;
    size_t getCapacity() const noexcept;

    void popBack();
    void pushBack(const T& v);
    void insert(size_t i, const T& v);
    void erase(size_t i);

    private:
      T* data_;
      size_t size_, cap_;
  };
}

template< class T >
bool petrovVadim::Vector< T >::isEmpty() const noexcept
{
  return !size_;
}

template< class T >
petrovVadim::Vector< T >::~Vector()
{
  delete data_;
}

template< class T >
petrovVadim::Vector< T >::Vector():
  data_(),
  size_(),
  cap_()
{}

template< class T >
size_t petrovVadim::Vector< T >::getSize() const noexcept
{
  return size_;
}

template< class T >
size_t petrovVadim::Vector< T >::getCapacity() const noexcept
{
  return cap_;
}

template< class T >
void petrovVadim::Vector< T >::pushBack(const T& v)
{
  T* newData = nullptr;
  try
  {
    newData = new T[cap_ + 1];
    for (size_t i = 0; i < size_; ++i)
    {
      newData[i] = data_[i];
    }
    newData[size_] = v;
    delete[] data_;
    data_ = newData;
    ++cap_;
    ++size_;
  }
  catch(...)
  {
    delete[] newData;
    throw;
  }
}

template< class T >
void petrovVadim::Vector< T >::popBack()
{
    if (!size_)
  {
    return;
  }

  T* newData = nullptr;
  try
  {
    newData = new T[cap_ - 1];
    for (size_t i = 0; i < size_ - 1; ++i)
    {
      newData[i] = data_[i];
    }
    delete[] data_;
    data_ = newData;
    --cap_;
    --size_;
  }
  catch(...)
  {
    delete[] newData;
    throw;
  }
}

#endif