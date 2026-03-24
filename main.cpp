#include <iostream>
#include "top-it-vector.hpp"

bool testEmptyVector()
{
  topit::Vector< int > v;
  bool res = v.isEmpty();
  return res == 0;
}

bool testElementInBoundAcces()
{
  topit::Vector< int > v;
  v.pushBack(1);
  try
  {
    int& val = v.at(0);
    return (val == 1);
  }
  catch (...)
  {
    return false;
  }
}

bool testCopyConstructorForEmpty()
{
  topit::Vector< int > v;
  topit::Vector< int > v1(v);
  return v1 == v;
}

bool testCopyConstructorForNonEmpty()
{
  topit::Vector< int > v;
  v.pushBack(1);
  topit::Vector< int > v1(v);
  return v1 == v;
}

bool testElementOutOfBoundAcces()
{
  topit::Vector< int > v;
  v.pushBack(1);
  try
  {
    return v.at(0);
    return false;
  }
  catch (std::out_of_range& e)
  {
    return true;
  }
  catch(...)
  {
    return false;
  }
}

bool testElementInBoundConstAccess()
{
  topit::Vector< int > v;
  v.pushBack(1);
  const topit::Vector< int > vc = v;
  try
  {
    const int& val = vc.at(0);
    return val == 1;
  }
  catch (...)
  {
    return false;
  }
}

bool testElementOutOfBoundConstAccess() {
  topit::Vector< int > v;
  const topit::Vector< int > vc = v;
  try {
    v.at(0);
    return false;
  }
  catch (std::out_of_range& e)
  {
    return true;
  }
  catch(...)
  {
    return false;
  }
}

bool testGetSize()
{
  topit::Vector< int > v;
  v.pushBack(1);
  size_t res = v.getSize();
  return res == 1;
}

bool testGetCapacity()
{
  topit::Vector< int > v;
  v.pushBack(1);
  size_t res = v.getCapacity();
  return res == 2;
}

bool testPushBack()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  int res = v[v.getSize() - 1];
  return res == 2;
}

bool testPopBack()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.popBack();
  int res = v[v.getSize() - 1];
  return res == 1;
}

int main()
{
  using test_t = std::pair< const char*, bool(*)() >;
  test_t tests[] = {{"Empty vector", testEmptyVector}, {"Size vector", testGetSize}, {"Capacity vector", testGetCapacity},
    {"PushBack vector", testPushBack}, {"PopBack vector", testPopBack}, {"Element in bound acces", testElementInBoundAcces},
    {"Element out of bound acces", testElementOutOfBoundAcces}, {"Element in bound const acces", testElementInBoundConstAccess},
    {"Element out of bound const acces", testElementOutOfBoundConstAccess}, {"Copy for empty", testCopyConstructorForEmpty},
    {"Copy for non empty", testCopyConstructorForNonEmpty}};
  const size_t count = sizeof(tests) / sizeof(test_t);
  std::cout << std::boolalpha;
  bool res = true;
  for (size_t i = 0; i < count; ++i)
  {
    res = res && tests[i].second();
    std::cout << tests[i].first << ": " << res << '\n';
  }
  std::cout << "RESULT: " << res << '\n';
}
