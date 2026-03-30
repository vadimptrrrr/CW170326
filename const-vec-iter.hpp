#ifndef CONST_VEC_ITER_HPP
#define CONST_VEC_ITER_HPP

namespace petrovVadim
{
  template< class T >
  struct CVecIter
  {
    CVecIter(const T* ptr);
    CVecIter(const CVecIter& other);
    CVecIter(CVecIter&& other) noexcept;
    CVecIter& operator=(const CVecIter& other);
    CVecIter& operator=(CVecIter&& other) noexcept;

    const T& operator*() const;
    const T* operator->() const;

    CVecIter& operator++();
    CVecIter operator++(int);
    CVecIter& operator--();
    CVecIter operator--(int);

    bool operator==(const CVecIter& other) const;
    bool operator!=(const CVecIter& other) const;

    private:
      const T* ptr_;
  };
  
}


#endif