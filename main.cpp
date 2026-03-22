#include <iostream>
#include "top-it-vector.hpp"

bool testEmptyVector()
{
  topit::Vector< int > v;
  bool res = v.isEmpty();
  return res == 0;
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
                    {"PushBack vector", testPushBack}, {"PopBack vector", testPopBack}};
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
