#include "top-it-vector.hpp"

namespace topit
{
  template< class T >
  bool Vector< T >::isEmpty() const noexcept
  {
    return size_ != 0;
  }

  template< class T >
  size_t Vector< T >::getSize() const noexcept
  {
    return size_;
  }

  template< class T >
  size_t Vector< T >::getCapacity() const noexcept
  {
    return capacity_;
  }

  template< class T >
  void extend(Vector< T >& v, size_t new_capacity)
  {
    T* new_data = new T[new_capacity];
    for (size_t i = 0; i < v.size_; ++i)
    {
      new_data[i] = v.data_[i];
    }
    v.capacity_ = new_capacity;
    delete[] v.data_;
    v.data_ = new_data;
  }

  template< class T >
  void Vector< T >::pushBack(const T& v)
  {
    if (size_ == 0)
    {
      extend(* this, 1);
    }
    else if (size_ == capacity_)
    {
      extend(* this, capacity_ * 2);
    }
    data[size_] = v;
    size_++;
  }

  template< class T >
  void Vector< T >::popBack()
  {
    size_--;
  }
}
