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

    T& operator[](size_t id) noexcept;
    const T& operator[](size_t id) const noexcept;
    T& at(size_t id);
    const T& at(size_t id) const;

    void popBack();
    void pushBack(const T& v);
    void insert(size_t i, const T& v);
    void erase(size_t i);

    private:
      T* data_;
      size_t size_, cap_;
  };
  
  
  template< class T >
  bool Vector< T >::isEmpty() const noexcept
  {
    return !size_;
  }
  
  template< class T >
  Vector< T >::~Vector()
  {
    delete data_;
  }
  
  template< class T >
  Vector< T >::Vector():
    data_(),
    size_(),
    cap_()
  {}
  
  template< class T >
  size_t Vector< T >::getSize() const noexcept
  {
    return size_;
  }
  
  template< class T >
  size_t Vector< T >::getCapacity() const noexcept
  {
    return cap_;
  }
  
  template< class T >
  void Vector< T >::pushBack(const T& v)
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
  void Vector< T >::popBack()
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

  template< class T >
  T & Vector< T >::at(size_t id)
  {
    const Vector< T > * cthis = this;
    return const_cast< T & >(cthis->at(id));
  }

  template< class T >
  const T & Vector< T >::at(size_t id) const
  {
    if (id < getSize())
    {
      return (*this)[id];
    }
    throw std::out_of_range("bad id");
  }

  template< class T >
  T & Vector< T >::operator[](size_t id) noexcept
  {
    const Vector< T > * cthis = this;
    return const_cast< T & >((*cthis)[id]);
  }

  template< class T >
  const T & Vector< T >::operator[](size_t id) const noexcept
  {
    return data_[id];
  }

  template< class T >
  bool operator==(const Vector< T >& lhs, const Vector< T >& rhs) noexcept
  {
    bool isEqual = lhs.getSize() == rhs.getSize();
    for (size_t i = 0; (i < lhs.getSize()) && (isEqual = isEqual && lhs[i] == rhs[i]); ++i);
    return isEqual;
  }

  template< class T >
  Vector< T >::Vector(const Vector< T >& rhs):
    data_(rhs.getSize() ? new T[rhs.getSize()] : nullptr),
    size_(rhs.getSize()),
    cap_(rhs.getSize())
  {
    for (size_t i = 0; i < rhs.getSize(); ++i)
    {
      try
      {
        data_[i] = rhs[i];
      }
      catch(...)
      {
        delete[] data_;
        throw;
      }
    }
  }
}

#endif