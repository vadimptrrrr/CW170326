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
    bool isEmpty() const noexcept;

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

#endif