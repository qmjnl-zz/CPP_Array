#pragma once

#include <string>

template <typename TData>
class CArray
{
public:
  CArray()
    : capacity_(0)
    , size_(0)
    , data_(nullptr)
  {
  };

  CArray(
      const CArray & _array
    )
  {
    capacity_(_array.capacity_);
    size_(_array.size_);

    data_ = new TData[capacity_];
    for (unsigned int i = 0; i < size_; i++)
    {
      data_[i] = _array.data_[i];
    }
  };

  ~CArray()
  {
    if (data_ != nullptr)
    {
      delete[] data_;
      data_ = nullptr;
    }
  };

  // Add element to the end
  void push_back(
      const TData & _value
    )
  {
    if (size_ == capacity_)
    {
      unsigned int capacity = capacity_ == 0 ? default_capacity_ : capacity_ * 2;
      TData * new_data = new TData[capacity];
      for (unsigned int i = 0; i < size_; i++)
      {
        new_data[i] = data_[i];
      }
      delete[] data_;

      data_ = new_data;
      capacity_ = capacity;
    }

    data_[size_] = _value;
    size_++;
  };

  // Add element at _index position
  void insert(
      unsigned int _index,
      const TData & _value
    )
  {
    if (size_ > 0 && _index >= size_)
    {
      std::string message = "Index " + std::to_string(_index) + " is out of range " + std::to_string(size_);
      throw std::out_of_range(message);
    }

    if (size_ == capacity_)
    {
      unsigned int capacity = capacity_ == 0 ? default_capacity_ : capacity_ * 2;
      TData * new_data = new TData[capacity];

      for (unsigned int i = 0; i < _index; i++)
      {
        new_data[i] = data_[i];
      }
      for (unsigned int i = _index; i < size_; i++)
      {
        new_data[i + 1] = data_[i];
      }

      delete[] data_;
      data_ = new_data;
      capacity_ = capacity;
    }
    else
    {
      for (int i = static_cast<int>(size_) - 1; i >= static_cast<int>(_index); i--)
      {
        data_[i + 1] = data_[i];
      }
    }

    data_[_index] = _value;
    size_++;
  };

  // Delete element at _index
  void erase(
      unsigned int _index
    )
  {
    if (_index >= size_)
    {
      return;
    }

    for (unsigned int i = _index + 1; i < size_; i++)
    {
      data_[i - 1] = data_[i];
    }
    size_--;
    data_[size_] = TData();
  };

  // Clear container
  void clear()
  {
    capacity_ = 0;
    size_ = 0;
    if (data_ != nullptr)
    {
      delete[] data_;
      data_ = nullptr;
    }
  };

  // Get number of elements
  unsigned int size() const
  {
    return size_;
  };

  // Get element at _index
  TData & operator[](
      unsigned int _index
    )
  {
    return data_[_index];
  };

  // Get element at _index (const version)
  const TData & operator[](
      unsigned int _index
    ) const
  {
    return data_[_index];
  };

  // Sort container
  void sort()
  {
    sort(0, size_ - 1);
  };

protected:
  // Sort container
  void sort(
      const int _first,
      const int _last
    )
  {
    if (size_ < 2 || _first >= _last)
    {
      return;
    }

    TData & pivot = data_[_last];
    int i = _first - 1;

    for (int j = _first; j <= _last - 1; j++)
    {
      if (data_[j] <= pivot)
      {
        i++;
        std::swap(data_[i], data_[j]);
      }
    }

    int pi = i + 1;
    std::swap(data_[pi], data_[_last]);

    sort(_first, pi - 1);
    sort(pi + 1, _last);
  };

protected:
  const unsigned int default_capacity_ = 1; // Default capacity for container
  unsigned int capacity_;                   // Possible count of elements
  unsigned int size_;                       // Count of elements
  TData * data_;                            // Container
};
