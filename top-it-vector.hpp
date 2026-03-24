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
    Vector(size_t size);
  public:
    Vector();
    ~Vector();
    Vector(const Vector< T >&);
    Vector(Vector< T >&&) noexcept;
    Vector< T >& operator=(const Vector< T >&);
    Vector< T >& operator=(Vector< T >&&);
    Vector(size_t size, const T& init);

    T& operator[](size_t i) noexcept;
    const T& operator[](size_t i) const noexcept;
    T& at(size_t i);
    const T& at(size_t i) const;

    void swap(Vector< T >&) noexcept;

    bool isEmpty() const noexcept;
    size_t getSize() const noexcept;
    size_t getCapacity() const noexcept;

    void extend(size_t new_size);
    void pushBack(const T& v);
    void popBack();
    void insert(size_t i, const T& v);
    void erase(size_t i);
  };

  template< class T >
  bool operator==(const Vector< T >& rhs, const Vector< T >& lhs);
  template< class T >
  bool operator!=(const Vector< T >& rhs, const Vector< T >& lhs);
}

namespace topit
{
  template< class T >
  bool operator==(const Vector< T >& rhs, const Vector< T >& lhs)
  {
    bool isEqual = lhs.getSize() == rhs.getSize();
    for (size_t i = 0; (i < lhs.getSize()) && (isEqual = isEqual && lhs[i] == rhs[i]); ++i);
    return isEqual;
  }

  template< class T >
  bool operator!=(const Vector< T >& rhs, const Vector< T >& lhs)
  {
    return !(rhs == lhs);
  }

  template< class T >
  Vector< T >::Vector():
    data_(nullptr),
    size_(0),
    capacity_(0)
  {}

  template< class T >
  Vector< T >::~Vector()
  {
    delete[] data_;
  }

  template< class T >
  Vector< T >::Vector(const Vector< T >& other):
    data_(other.size_ ? new T[other.size_ * 2] : nullptr),
    size_(other.size_),
    capacity_(size_ * 2)
  {
    for (size_t i = 0; i < size_; ++i)
    {
      try
      {
        data_[i] = other.data_[i];
      }
      catch (...)
      {
        delete[] data_;
        throw;
      }
    }
  }

  template< class T >
  Vector< T >::Vector(Vector< T >&& other) noexcept:
    data_(other.data_),
    size_(std::move(other.size_)),
    capacity_(std::move(other.capacity_))
  {
    other.data_ = nullptr;
  }

  template< class T >
  void swap(Vector< T >& other) noexcept
  {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
  }

  template< class T >
  Vector< T >& Vector< T >::operator=(const Vector< T >& other)
  {
    Vector< T > cop(other);
    swap(cop);
    return * this;
  }

  template< class T >
  Vector< T >& Vector< T >::operator=(Vector< T >&& other)
  {
    Vector< T > cop(std::move(rhs));
    swap(cop);
    return * this;
  }

  template< class T >
  Vector< T >::Vector(size_t size):
    data_(size ? new T[size] : nullptr),
    size_(size),
    capacity_(size)
  {}

  template< class T >
  Vector< T >::Vector(size_t size, const T& init):
    Vector(size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      data_[i] = init;
    }
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
  T& Vector< T >::operator[](size_t i) noexcept
  {
    return data_[i];
  }

  template< class T >
  const T& Vector< T >::operator[](size_t i) const noexcept
  {
    return data_[i];
  }

  template< class T >
  T& Vector< T >::at(size_t i)
  {
    if (i < getSize())
    {
      return data_[i];
    }
    else
    {
      throw std::out_of_range("Bad i");
    }
  }

  template< class T >
  const T& Vector< T >::at(size_t i) const
  {
    if (i < getSize())
    {
      return data_[i];
    }
    else
    {
      throw std::out_of_range("Bad i");
    }
  }

  template< class T >
  void Vector< T >::extend(size_t new_capacity)
  {
    T* new_data = new T[new_capacity];
    for (size_t i = 0; i < size_; ++i)
    {
      new_data[i] = data_[i];
    }
    capacity_ = new_capacity;
    delete[] data_;
    data_ = new_data;
  }

  template< class T >
  void Vector< T >::pushBack(const T& v)
  {
    if (size_ == 0)
    {
      extend(2);
    }
    else if (size_ == capacity_)
    {
      extend(capacity_ * 2);
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
