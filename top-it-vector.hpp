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
    Vector(Vector&&) noexcept;
    explicit Vector(size_t size, const T& init);
    Vector(std::initializer_list< T > il);
    Vector& operator=(const Vector&);
    Vector& operator=(Vector&&);

    bool isEmpty() const noexcept;
    size_t getSize() const noexcept;
    size_t getCapacity() const noexcept;
    void swap(Vector< T >& rhs) noexcept;
    void changeVectorInSomeWay();

    T& operator[](size_t id) noexcept;
    const T& operator[](size_t id) const noexcept;
    T& at(size_t id);
    const T& at(size_t id) const;

    void popBack();
    void pushBack(const T& v);

    void insert(size_t i, const T& v);
    // void insert(VecIter< T > pos, const T& v);
    // void insert(VecIter< T > pos, size_t count, const T& v);
    // void insert(VecIter< T > pos, VecIter< T > start, VecIter< T > end);

    void erase(size_t i);
    void erase(size_t start, size_t end);
    // void erase(VecIter< T > pos);
    // void erase(VecIter< T > pos, size_t s);
    // void erase(VecIter< T > start, VecIter< T > end);

    private:
      T* data_;
      size_t size_, cap_;
      explicit Vector(size_t size);
  };

  template< class T >
  Vector< T >::Vector(std::initializer_list< T > il):
    Vector(il.size())
  {
    size_t i = 0;
    for (auto it = il.begin(); it != il.end(); ++it)
    {
      data_[i++] = *it;
    }
  }

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
    insert(size_, v);
  }

  template< class T >
  void Vector< T >::popBack()
  {
    erase(size_ - 1);
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
    Vector(rhs.getSize())
  {
    for (size_t i = 0; i < rhs.getSize(); ++i)
    {
      data_[i] = rhs[i];
    }
  }

  template< class T >
  Vector< T >::Vector(size_t size):
    data_(size ? new T[size] : nullptr),
    size_(size),
    cap_(size)
  {}

  template< class T >
  Vector< T >::Vector(size_t size, const T& init):
    Vector(size)
  {
    for( size_t i = 0; i < size; ++i)
    {
      data_[i] = init;
    }
  }

  template< class T >
  Vector< T >& Vector< T >::operator=(const Vector< T >& rhs)
  {
    if (this == std::addressof(rhs))
    {
      return *this;
    }
    Vector< T > cpy(rhs);
    swap(cpy);
    return *this;
  }

  template< class T >
  Vector< T >& Vector< T >::operator=(Vector< T >&& rhs)
  {
    Vector< T > cpy(std::move(rhs));
    swap(cpy);
    return *this;
  }

  template< class T >
  Vector< T >::Vector(Vector< T >&& rhs) noexcept:
    data_(rhs.data_),
    size_(rhs.size_),
    cap_(rhs.cap_)
  {
    rhs.data_ = nullptr;
  }

  template< class T >
  void Vector< T >::swap(Vector< T >& rhs) noexcept
  {
    std::swap(data_, rhs.data_);
    std::swap(size_, rhs.size_);
    std::swap(cap_, rhs.cap_);
  }

  template< class T >
  void Vector< T >::changeVectorInSomeWay()
  {
    Vector< T > cpy(*this);
    cpy.pushBack(T());
    cpy.pushBack(T());
    cpy.pushBack(T());
    cpy.pushBack(T());
    cpy.pushBack(T());
    cpy.pushBack(T());
    swap(cpy);
  }

  template< class T >
  void Vector< T >::insert(size_t i, const T& val)
  {
    T* new_data = nullptr;
    if (cap_ == 0)
    {
      new_data = new T[i + 1];
      cap_ = i + 1;
    }
    else if (i >= cap_)
    {
      new_data = new T[cap_ + 10];
      cap_ += 10;
    }
    else if (size_ + 1 >= cap_)
    {
      new_data = new T[cap_ * 2];
      cap_ *= 2;
    }
    else
    {
      new_data = new T[cap_];
    }

    size_t j = 0;
    try
    {
      if (i > size_)
      {
        for (; j < size_; ++j)
        {
          new_data[j] = data_[j];
        }
        new_data[i] = val;
        size_ = i + 1;
      }
      else
      {
        for (; j < i; ++j)
        {
          new_data[j] = data_[j];
        }
        new_data[i] = val;
        for (; j < size_; ++j)
        {
          new_data[j + 1] = data_[j];
        }
        ++size_;
      }
    }
    catch(...)
    {
      delete[] new_data;
      throw;
    }

    delete[] data_;
    data_ = new_data;
  }

  // template< class T >
  // void Vector< T >::insert(VecIter< T > pos, const T& v)
  // {}

  // template< class T >
  // void Vector< T >::insert(VecIter< T > pos, size_t count, const T& v)
  // {}

  // template< class T >
  // void Vector< T >::insert(VecIter< T > pos, VecIter< T > start, VecIter< T > end)
  // {}

  template< class T >
  void Vector< T >::erase(size_t i)
  {
    erase(i, i + 1);
  }

  template< class T >
  void Vector< T >::erase(size_t start, size_t end)
  {
    if (!size_)
    {
      return;
    }

    T* new_data = new T[cap_];
    size_t j = 0;
    try
    {
      for (; j < start; ++j)
      {
        new_data[j] = data_[j];
      }
      for (size_t k = end; k < size_; ++k, ++j)
      {
        new_data[j] = data_[k];
      }
      size_ -= (end - start);
    }
    catch(...)
    {
      delete[] new_data;
      throw;
    }
    delete[] data_;
    data_ = new_data;
  }

  // template< class T >
  // void Vector< T >::erase(VecIter< T > pos)
  // {}

  // template< class T >
  // void Vector< T >::erase(VecIter< T > pos, size_t s)
  // {}

  // template< class T >
  // void Vector< T >::erase(VecIter< T > start, VecIter< T > end)
  // {}
}

#endif