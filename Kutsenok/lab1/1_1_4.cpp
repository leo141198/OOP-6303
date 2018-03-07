#include <assert.h>
#include <algorithm> // std::copy
#include <cstddef> // size_t

template<typename T>
class Array
{
public:
  // (default) constructor
  Array(const size_t size = 0)
    : m_size(size)
    , m_array(m_size ? new T[m_size] : nullptr)
  {
  }
  
  ~Array() {
      delete [] m_array;
  }

  const size_t size() const
  {
    return m_size;
  }

  T& operator[](const size_t index)
  {
    assert(index < m_size);
    return m_array[index];
  }
    
  Array& operator=(Array const& a) {
      //if(&a != this) {
          try {
             Array* temp = new Array(a);
             m_size = temp->m_size;
             m_array = temp->m_array;
          } catch(...) {
              throw;
          }
      //}
      return *this;
  }
   
  Array(Array&& a) : m_size(a.m_size), m_array(a.m_array) {
      a.m_array = nullptr;
      a.m_size = 0;
  }
    
  Array(Array const& a): m_size(a.m_size), m_array(new T[m_size]) {
      try {
          for(int i = 0; i < m_size; i++) {
              m_array[i] = a.m_array[i];
          }
      } catch(...) {
        delete [] m_array;
        throw;
      }
          
  }

private:
  size_t m_size;
  T* m_array;
};

new_temp = old;
