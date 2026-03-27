#include <iostream>
#include "top-it-vector.hpp"

bool testEmptyVector()
{
  topit::Vector< int > v;
  bool res = v.isEmpty();
  return res;
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

bool testInsertOne()
{
  topit::Vector< int > v;
  v.insert(0, 1);
  v.insert(0, 3);
  v.insert(1, 2);
  return (v[0] == 3 && v[1] == 2 && v[2] == 1 && v.getSize() == 3);
}

bool testInsertVector()
{
  topit::Vector< int > v;
  v.insert(0, 1);
  v.insert(0, 2);
  v.insert(0, 3);
  topit::Vector< int > v1;
  v1.insert(0, 0);
  v1.insert(0, 0);
  v1.insert(1, v);
  return (v1[1] == 3 && v1[2] == 2 && v1[3] == 1 && v1.getSize() == 5);
}

bool testEraseOne()
{
  topit::Vector< int > v;
  v.insert(0, 1);
  v.insert(0, 3);
  v.insert(1, 2);
  v.erase(1);
  return (v[0] == 3 && v[1] == 1 && v.getSize() == 2);
}

bool testEraseSeveral()
{
  topit::Vector< int > v;
  v.insert(0, 1);
  v.insert(0, 2);
  v.insert(0, 3);
  v.insert(0, 4);
  v.erase(1, 2);
  return (v[0] == 4 && v[1] == 1 && v.getSize() == 2);
}

bool testInsertOneIterator()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.insert(v.begin(), 2);
  return (v[0] == 2 && v[1] == 1 && v.getSize() == 2);
}

bool testInsertFromToIterator()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(5);
  topit::Vector< int > v1;
  v1.pushBack(2);
  v1.pushBack(3);
  v1.pushBack(4);
  v.insert(v.begin() + 1, v1.begin(), v1.begin() + 3);
  return (v[0] == 1 && v[1] == 2 && v[2] == 3 && v[3] == 4 && v[4] == 5 && v.getSize() == 5);
}

bool testInsertFromNIterator()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(5);
  topit::Vector< int > v1;
  v1.pushBack(2);
  v1.pushBack(3);
  v1.pushBack(4);
  v.insert(v.begin() + 1, v1.begin(), 3);
  return (v[0] == 1 && v[1] == 2 && v[2] == 3 && v[3] == 4 && v[4] == 5 && v.getSize() == 5);
}

bool testEraceOneIterator()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(5);
  topit::Vector< int > v1;
  v1.pushBack(2);
  v1.pushBack(3);
  v1.pushBack(4);
  v.insert(v.begin() + 1, v1.begin(), 3);
  v.erase(v.begin() + 1);
  return (v[0] == 1 && v[1] == 3 && v[2] == 4 && v[3] == 5 && v.getSize() == 4);
}

bool testEraceFromToIterator()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(5);
  topit::Vector< int > v1;
  v1.pushBack(2);
  v1.pushBack(3);
  v1.pushBack(4);
  v.insert(v.begin() + 1, v1.begin(), 3);
  v.erase(v.begin() + 1, v.begin() + 4);
  return (v[0] == 1 && v[1] == 5 && v.getSize() == 2);
}

bool testEraceFromNIterator()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(5);
  topit::Vector< int > v1;
  v1.pushBack(2);
  v1.pushBack(3);
  v1.pushBack(4);
  v.insert(v.begin() + 1, v1.begin(), 3);
  v.erase(v.begin() + 1, 3);
  return (v[0] == 1 && v[1] == 5 && v.getSize() == 2);
}

int main()
{
  using test_t = std::pair< const char*, bool(*)() >;
  test_t tests[] = {{"Empty vector", testEmptyVector}, {"Size vector", testGetSize}, {"Capacity vector", testGetCapacity},
    {"PushBack vector", testPushBack}, {"PopBack vector", testPopBack}, {"Element in bound acces", testElementInBoundAcces},
    {"Element out of bound acces", testElementOutOfBoundAcces}, {"Element in bound const acces", testElementInBoundConstAccess},
    {"Element out of bound const acces", testElementOutOfBoundConstAccess}, {"Copy for empty", testCopyConstructorForEmpty},
    {"Copy for non empty", testCopyConstructorForNonEmpty}, {"Insert one", testInsertOne}, {"Insert vector", testInsertVector},
    {"Erace one", testEraseOne}, {"Erace several", testEraseSeveral}, {"Insert one by iterator", testInsertOneIterator},
    {"Insert from to by iterator", testInsertFromToIterator}, {"Insert from n by iterator", testInsertFromNIterator},
    {"Erace one by iterator", testEraceOneIterator}, {"Erace from to by iterator", testEraceFromToIterator},
    {"Erace from n by iterator", testEraceFromNIterator}};
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
