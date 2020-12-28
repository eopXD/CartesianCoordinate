#pragma once
#include "CoordinateIterator.h"

template <typename T>
class CartesianCoordinate
{
public:
  using value_type = T;
  using offset_type = unsigned long long;
  using container_type = std::vector<value_type>;
  using iterator = CoordinateIterator;

public: // contructor
  CartesianCoordinate() = delete;
  CartesianCoordinate(std::initializer_list<T> maxAxis)
    : m_maxAxis(maxAxis)
  {
    static_assert(std::is_unsigned<T>::value && std::is_integral<T>::value, "T should be unsigned integral");
    initializeVolume(maxAxis);
  }
  template <typename ContainerT>
  CartesianCoordinate(ContainerT maxAxis)
    : m_maxAxis(maxAxis)
  {
    static_assert(std::is_unsigned<typename ContainerT::value_type>::value &&
                    std::is_integral<typename ContainerT::value_type>::value,
                  "ContainerT should be of unsigned integral");
    static_assert(std::is_same<T, typename ContainerT::value_type>::value, "ContainerT value type should match T");
    initializeVolume(maxAxis);
  }

private:
  template <typename ContainerT>
  void initializeVolume(ContainerT maxAxis)
  {
    m_maxOffset = 1;
    for (auto& axis : maxAxis) {
      m_maxOffset *= axis;
    }
    offset_type volume = m_maxOffset;
    typename container_type::size_type maxDim = m_maxAxis.size();
    typename ContainerT::const_iterator it = std::begin(maxAxis);
    for (typename container_type::size_type idx = 0; idx < maxDim; ++idx, ++it) {
      volume /= *it;
      m_volume.push_back(volume);
    }
  }

public: // iterator
  iterator begin() const { return iterator(0); }
  iterator end() const { return iterator(m_maxOffset); }
  iterator at(std::initializer_list<T> startAxis) const
  {
    assert(startAxis.size() == m_maxAxis.size() && "argument should match the dimension initialized");
    offset_type currOffset = calcOffset(m_maxAxis.size(), std::begin(startAxis));
    return iterator(currOffset);
  }
  template <typename ContainerT>
  iterator at(ContainerT startAxis) const
  {
    static_assert(std::is_same<T, typename ContainerT::value_type>::value, "ContainerT value type should match T");
    assert(startAxis.size() == m_maxAxis.size() && "argument should match the dimension initialized");
    offset_type currOffset = calcOffset(m_maxAxis.size(), std::begin(startAxis));
    return iterator(currOffset);
  }

private:
  template <typename Iterator>
  offset_type calcOffset(typename container_type::size_type maxDim, Iterator it) const
  {
    offset_type offset = 0;
    for (typename container_type::size_type idx = 0; idx < maxDim; ++idx, ++it) {
      offset += (*it) * m_volume[idx];
    }
    return offset;
  }

public: // access during iteration
  offset_type offsetOf(iterator it) const { return it(); }
  template <typename OutputIterator>
  void coordOf(iterator it, OutputIterator out) const
  {
    offset_type temp = it();
    typename container_type::size_type maxDim = m_maxAxis.size();
    for (typename container_type::size_type idx = 0; idx < maxDim; ++idx) {
      *out++ = temp / m_volume[idx];
      temp = temp % m_volume[idx];
    }
  }

private:
  container_type m_maxAxis;
  container_type m_volume;
  value_type m_maxOffset;
};
