#ifndef TOP_IT_VECTOR_HPP
#define TOP_IT_VECTOR_HPP

template< class T >
struct vector
{
  T* data;
  size_t size, cap;
};

#endif