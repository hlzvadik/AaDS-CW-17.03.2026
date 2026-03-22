#ifndef TOP_IT_VECTOR_HPP
#define TOP_IT_VECTOR_HPP
#include <cstddef>

namespace topit
{
  template< class T >
  class Vector
  {
    T* data_;
    size_t size_, capacity_;
  public:
    Vector();
    ~Vector();
    Vector(const Vector&);
    Vector(Vector&&);
    Vector& operator=(const Vector&);
    Vector& operator=(Vector&&);

    bool isEmpty() const noexcept;
    size_t getSize() const noexcept;
    size_t getCapacity() const noexcept;

    void pushBack(const T& v);
    void popBack();
    void insert(size_t i, const T& v);
    void erase(size_t i);
  };
}

namespace topit
{
  template< class T >
  topit::Vector< T >::Vector():
    data_(nullptr),
    size_(0),
    capacity_(0)
  {}

  template< class T >
  topit::Vector< T >::~Vector()
  {
    delete[] data_;
  }

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
    data_[size_] = v;
    size_++;
  }

  template< class T >
  void Vector< T >::popBack()
  {
    size_--;
  }
}

#endif
