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

    private:
      T* data_;
      size_t size_, cap_;
  };
}

template< class T >
petrovVadim::Vector< T >::~Vector()
{

}

template< class T >
petrovVadim::Vector< T >::Vector():
  data_(),
  size_(),
  cap_()
{

}

#endif