#pragma once

#include <cassert>
#include <type_traits>
#include <utility>
#include <vector>

class CoordinateIterator
{
  using size_type = std::size_t;
  using value_type = unsigned long long;
  using pointer = value_type*;
  using reference = value_type&;

private:
  value_type m_Counter = 0;

public:
  CoordinateIterator() = default;
  CoordinateIterator(const CoordinateIterator& rhs)
    : m_Counter(rhs())
  {}
  CoordinateIterator(value_type value)
    : m_Counter(value)
  {}
  CoordinateIterator& operator++()
  {
    ++m_Counter;
    return (*this);
  }
  CoordinateIterator& operator--()
  {
    --m_Counter;
    return (*this);
  }
  CoordinateIterator& operator++(int val)
  {
    assert(val >= 0 && "value shall be unsigned");
    m_Counter += val;
    return (*this);
  }
  CoordinateIterator& operator--(int val)
  {
    assert(val >= 0 && "value shall be unsigned");
    assert(static_cast<value_type>(val) <= m_Counter && "value shall be smaller than current counting");
    m_Counter -= val;
    return (*this);
  }
  value_type operator()() const { return m_Counter; }
  pointer operator->() { return &m_Counter; };
  reference operator*() { return m_Counter; };

  CoordinateIterator& operator=(const CoordinateIterator& rhs)
  {
    m_Counter = rhs();
    return (*this);
  }
  bool operator==(const CoordinateIterator& rhs) const { return m_Counter == rhs(); }
  bool operator!=(const CoordinateIterator& rhs) const { return m_Counter != rhs(); }
};

