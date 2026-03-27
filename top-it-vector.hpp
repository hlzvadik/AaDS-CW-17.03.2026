#ifndef TOP_IT_VECTOR_HPP
#define TOP_IT_VECTOR_HPP
#include <cstddef>

namespace topit
{
  template< class T >
  class VIter
  {
    T* value_;
  public:
    bool operator==(VIter< T > other);
    bool operator!=(VIter< T > other);
    T& operator*();
    T& operator->();
    VIter< T > operator++();
    void operator+=(size_t n);
    VIter< T > operator+(size_t n);
    void operator--();
    void operator-=(size_t n);
    VIter< T > operator-(size_t n);
  };

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
    void normalize();

    void pushBack(const T& v);
    void popBack();
    void insert(size_t i, const T& v);
    void insert(size_t i, Vector< T >& v);
    void erase(size_t i);
    void erase(size_t i, size_t n);

    VIter< T > begin();
    VIter< T > end();
    void insert(VIter< T > i, const T& val);
    void insert(VIter< T > i, VIter< T > from, VIter< T > to);
    void insert(VIter< T > i, VIter< T > from, size_t n);
    void erase(VIter< T > i);
    void erase(VIter< T > i, VIter< T > to);
    void erase(VIter< T > i, size_t n);
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
  void Vector< T >::swap(Vector< T >& other) noexcept
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
    Vector< T > cop(std::move(other));
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
  void Vector< T >::normalize()
  {
    if (size_ == 0 && capacity_ > 2)
    {
      T* new_data_ = new T[2];
      delete[] data_;
      data_ = new_data_;
    }
    else if (size_ * 2 < capacity_)
    {
      T* new_data_ = new T[size_ * 2];
      for (size_t i = 0; i < size_; ++i)
      {
        try
        {
          new_data_[i] = data_[i];
        }
        catch(const std::exception& e)
        {
          delete[] new_data_;
        }
      }
      delete[] data_;
      data_ = new_data_;
      capacity_ = size_ * 2;
    }
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
    normalize();
  }

  template< class T >
  void Vector< T >::insert(size_t i, const T& v)
  {
    if (i != 0 && i >= size_)
    {
      throw std::out_of_range("Index out of range");
    }
    T* new_data_ = new T[size_ + 1];
    try
    {
      for (size_t j = 0; j < i; ++j)
      {
        new_data_[j] = data_[j];
      }
      new_data_[i] = v;
      for (size_t j = i; j < size_; ++j)
      {
        new_data_[j + 1] = data_[j];
      }
    }
    catch (...)
    {
      delete[] new_data_;
      throw;
    }
    ++size_;
    capacity_ = size_;
    delete[] data_;
    data_ = new_data_;
  }

  template< class T >
  void Vector< T >::insert(size_t i, Vector< T >& v)
  {
    if (i != 0 && i >= size_)
    {
      throw std::out_of_range("Index out of range");
    }
    T* new_data_ = new T[size_ + v.getSize()];
    try
    {
      for (size_t j = 0; j < i; ++j)
      {
        new_data_[j] = data_[j];
      }
      for (size_t j = 0; j < v.getSize(); ++j)
      {
        new_data_[i + j] = v[j];
      }
      for (size_t j = i; j < size_; ++j)
      {
        new_data_[v.getSize() + j] = data_[j];
      }
    }
    catch(...)
    {
      delete[] new_data_;
      throw;
    }
    size_ += v.getSize();
    capacity_ = size_;
    delete[] data_;
    data_ = new_data_;
  }

  template< class T >
  void Vector< T >::erase(size_t i)
  {
    if (i != 0 && i >= size_)
    {
      throw std::out_of_range("Index out of range");
    }
    T* new_data_ = new T[size_ - 1];
    try
    {
      for (size_t j = 0; j < i; ++j)
      {
        new_data_[j] = data_[j];
      }
      for (size_t j = i + 1; j < size_; ++j)
      {
        new_data_[j - 1] = data_[j];
      }
    }
    catch (...)
    {
      delete[] new_data_;
      throw;
    }
    --size_;
    capacity_ = size_;
    delete[] data_;
    data_ = new_data_;
    normalize();
  }

  template< class T >
  void Vector< T >::erase(size_t i, size_t n)
  {
    if (i != 0 && i + n >= size_)
    {
      throw std::out_of_range("Index out of range");
    }
    T* new_data_ = new T[size_ - n];
    try
    {
      for (size_t j = 0; j < i; ++j)
      {
        new_data_[j] = data_[j];
      }
      for (size_t j = i + n; j < size_; ++j)
      {
        new_data_[j - n] = data_[j];
      }
    }
    catch (...)
    {
      delete[] new_data_;
      throw;
    }
    size_ -= n;
    capacity_ = size_;
    delete[] data_;
    data_ = new_data_;
    normalize();
  }

  template< class T >
  bool VIter< T >::operator==(VIter< T > other)
  {
    return other.value_ == value_;
  }

  template< class T >
  bool VIter< T >::operator!=(VIter< T > other)
  {
    return !(other == (* this));
  }

  template< class T >
  T& VIter< T >::operator*()
  {
    return * value_;
  }
  template< class T >
  T& VIter< T >::operator->()
  {
    return * value_;
  }
  template< class T >
  VIter< T > VIter< T >::operator++()
  {
    return value_++;
  }
  template< class T >
  void VIter< T >::operator+=(size_t n)
  {
    value_ += n;
  }
  template< class T >
  VIter< T > VIter< T >::operator+(size_t n)
  {
    return (value_ + n);
  }
  template< class T >
  void VIter< T >::operator--()
  {
    return value_--;
  }
  template< class T >
  void VIter< T >::operator-=(size_t n)
  {
    value_ -= n;
  }
  template< class T >
  VIter< T > VIter< T >::operator-(size_t n)
  {
    return (value_ - n);
  }

  template< class T >
  VIter< T > Vector< T >::begin()
  {
    return {data_[0]};
  }
  template< class T >
  VIter< T > Vector< T >::end()
  {
    return {data_[size_ - 1]};
  }
  template< class T >
  void Vector< T >::insert(VIter< T > i, const T& val)
  {
    T* new_data_ = new T[size_ + 1];
    size_t id = 0;
    VIter< T > now = begin();
    try
    {
      while (now != i)
      {
        new_data_[id] = (* now);
        ++id;
        ++now;
      }
      new_data_[id] = val;
      ++id;
      while (now != end())
      {
        new_data_[id] = (* now);
        ++id;
        ++now;
      }
    }
    catch (...)
    {
      delete[] new_data_;
      throw;
    }
    size_++;
    capacity_ = size_;
    delete[] data_;
    data_ = new_data_;
  }
  template< class T >
  void Vector< T >::insert(VIter< T > i, VIter< T > from, VIter< T > to)
  {
    size_t n = 1;
    VIter< T > temp = from;
    while (temp != to)
    {
      ++n;
      ++temp;
    }
    insert(i, from, n);
  }
  template< class T >
  void Vector< T >::insert(VIter< T > i, VIter< T > from, size_t n)
  {
    T* new_data_ = new T[size_ + n];
    VIter< T > now = begin();
    size_t id = 0;
    try
    {
      while (now != i)
      {
        new_data_[id] = (* now);
        ++id;
        ++now;
      }
      VIter< T > now_temp = from;
      for (size_t j = 0; j < n; ++j)
      {
        new_data_[id] = (* now_temp);
        ++now_temp;
        ++id;
      }
      while (now != end())
      {
        new_data_[i] = (* now);
        ++now;
        ++id;
      }
    }
    catch (...)
    {
      delete[] new_data_;
      throw;
    }
    size_ += n;
    capacity_ = size_;
    delete[] data_;
    data_ = new_data_;
  }
  template< class T >
  void Vector< T >::erase(VIter< T > i)
  {
    T* new_data_ = new T[size_ - 1];
    size_t id = 0;
    VIter< T > now = begin();
    try
    {
      while (now != i)
      {
        new_data_[id] = (* now);
        ++id;
        ++now;
      }
      ++now;
      while (now != end())
      {
        new_data_[id] = (* now);
        ++id;
        ++now;
      }
    }
    catch (...)
    {
      delete[] new_data_;
      throw;
    }
    size_--;
    capacity_ = size_;
    delete[] data_;
    data_ = new_data_;
  }
  template< class T >
  void Vector< T >::erase(VIter< T > i, VIter< T > to)
  {
    size_t n = 0;
    VIter< T > now_temp = i;
    while(now_temp != to)
    {
      ++n;
    }
    erase(i, n);
  }
  template< class T >
  void Vector< T >::erase(VIter< T > i, size_t n)
  {
    T* new_data_ = new T[size_ - n];
    VIter< T > now = begin();
    size_t id = 0;
    try
    {
      while (now != i)
      {
        new_data_[id] = (* now);
        ++now;
        ++id;
      }
      for (size_t i = 0; i < n; ++i)
      {
        ++now;
      }
      while (now != end())
      {
        new_data_[id] = (* now);
        ++now;
        ++id;
      }
    }
    catch(...)
    {
      delete[] new_data_;
      throw;
    }
    size_ -= n;
    capacity_ = size_;
    delete[] data_;
    new_data_ = data_;
  }
}

#endif
