#ifndef VEC_ITER_HPP
#define VEC_ITER_HPP

namespace petrovVadim
{
  template< class T >
  struct VecIter
  {
    VecIter(T* ptr);
    VecIter(const VecIter& other);
    VecIter(VecIter&& other) noexcept;
    VecIter& operator=(const VecIter& other);
    VecIter& operator=(VecIter&& other) noexcept;

    T& operator*() const;
    T* operator->() const;

    VecIter& operator++();
    VecIter operator++(int);
    VecIter& operator--();
    VecIter operator--(int);

    bool operator==(const VecIter& other) const;
    bool operator!=(const VecIter& other) const;

    private:
      T* ptr_;
  };
  
}

#endif
