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
void petrovVadim::Vector< T >::pushBack(const T& v)
{}

#endif