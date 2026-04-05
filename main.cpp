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

bool testInsertByIterator()
{
  topit::Vector< int > v;
  v.insert(0, 1);
  v.insert(0, 2);
  v.insert(0, 3);
  topit::Vector< int > v1;
  v1.insert(0, 0);
  v1.insert(0, 0);
  v1.insert(1, v.begin(), v.getSize());
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

bool testInitializerList()
{
  topit::Vector< int > v = {1, 2, 3};
  return v.getSize() == 3 && (v[0] == 1) && (v[1] == 2);
}

bool testDefaultConstructor()
{
  topit::Vector< int > v;
  return v.isEmpty() && v.getSize() == 0 && v.getCapacity() == 0;
}

bool testConstructorWithSize()
{
  topit::Vector< int > v(5);
  bool sizeOk = (v.getSize() == 5);
  bool capacityOk = (v.getCapacity() >= 5);
  bool allDefault = true;
  for (size_t i = 0; i < v.getSize(); ++i)
  {
    if (v[i] != int())
    {
      allDefault = false;
      break;
    }
  }
  return sizeOk && capacityOk && allDefault;
}

bool testConstructorWithSizeAndInit()
{
  topit::Vector< int > v(5, 42);
  bool sizeOk = (v.getSize() == 5);
  bool capacityOk = (v.getCapacity() >= 5);
  bool allInit = true;
  for (size_t i = 0; i < v.getSize(); ++i)
  {
    if (v[i] != 42)
    {
      allInit = false;
      break;
    }
  }
  return sizeOk && capacityOk && allInit;
}

bool testMoveConstructor()
{
  topit::Vector< int > v1;
  v1.pushBack(1);
  v1.pushBack(2);
  v1.pushBack(3);
  size_t oldSize = v1.getSize();
  
  topit::Vector< int > v2(std::move(v1));
  
  bool newSizeOk = (v2.getSize() == oldSize);
  bool newDataOk = (v2[0] == 1 && v2[1] == 2 && v2[2] == 3);
  return newSizeOk && newDataOk;
}

bool testCopyAssignment()
{
  topit::Vector< int > v1;
  v1.pushBack(1);
  v1.pushBack(2);
  v1.pushBack(3);
  
  topit::Vector< int > v2;
  v2 = v1;
  
  return (v2.getSize() == v1.getSize()) && (v2[0] == 1) && (v2[1] == 2) && (v2[2] == 3);
}

bool testMoveAssignment()
{
  topit::Vector< int > v1;
  v1.pushBack(1);
  v1.pushBack(2);
  v1.pushBack(3);
  size_t oldSize = v1.getSize();
  
  topit::Vector< int > v2;
  v2 = std::move(v1);
  
  bool newSizeOk = (v2.getSize() == oldSize);
  bool newDataOk = (v2[0] == 1 && v2[1] == 2 && v2[2] == 3);
  return newSizeOk && newDataOk;
}

bool testOperatorBracket()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.pushBack(3);
  
  v[0] = 10;
  v[1] = 20;
  v[2] = 30;
  
  return (v[0] == 10) && (v[1] == 20) && (v[2] == 30);
}

bool testConstOperatorBracket()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.pushBack(3);
  const topit::Vector< int >& cv = v;
  
  return (cv[0] == 1) && (cv[1] == 2) && (cv[2] == 3);
}

bool testAtMethod()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.pushBack(3);
  
  bool normalAccess = (v.at(0) == 1) && (v.at(1) == 2) && (v.at(2) == 3);
  v.at(0) = 10;
  bool modification = (v.at(0) == 10);
  
  return normalAccess && modification;
}

bool testConstAtMethod()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.pushBack(3);
  const topit::Vector< int >& cv = v;
  
  return (cv.at(0) == 1) && (cv.at(1) == 2) && (cv.at(2) == 3);
}

bool testReserve()
{
  topit::Vector< int > v;
  size_t oldCapacity = v.getCapacity();
  v.reserve(100);
  
  bool capacityIncreased = (v.getCapacity() >= 100);
  bool sizeUnchanged = (v.getSize() == 0);
  
  v.pushBack(1);
  v.pushBack(2);
  v.reserve(50);
  bool noShrink = (v.getCapacity() >= 100);
  
  return capacityIncreased && sizeUnchanged && noShrink;
}

bool testShrinkToFit()
{
  topit::Vector< int > v;
  for (int i = 0; i < 10; ++i)
  {
    v.pushBack(i);
  }
  size_t capacityBefore = v.getCapacity();
  for (int i = 0; i < 5; ++i)
  {
    v.popBack();
  }
  v.shrinkToFit();
  
  return (v.getSize() == 5) && (v.getCapacity() == 5);
}

bool testNormalize()
{
  topit::Vector< int > v;
  for (int i = 0; i < 10; ++i)
  {
    v.pushBack(i);
  }
  for (int i = 0; i < 8; ++i)
  {
    v.popBack();
  }
  v.normalize();
  
  return (v.getSize() == 2) && (v.getCapacity() == 4);
}

bool testSwap()
{
  topit::Vector< int > v1;
  v1.pushBack(1);
  v1.pushBack(2);
  
  topit::Vector< int > v2;
  v2.pushBack(3);
  v2.pushBack(4);
  v2.pushBack(5);
  
  size_t size1 = v1.getSize();
  size_t size2 = v2.getSize();
  
  v1.swap(v2);
  
  return (v1.getSize() == size2) && (v2.getSize() == size1) &&
         (v1[0] == 3) && (v2[0] == 1);
}

bool testPushBackCount()
{
  topit::Vector< int > v;
  v.pushBackCount(42, 5);
  
  bool sizeOk = (v.getSize() == 5);
  bool allCorrect = true;
  for (size_t i = 0; i < v.getSize(); ++i)
  {
    if (v[i] != 42)
    {
      allCorrect = false;
      break;
    }
  }
  return sizeOk && allCorrect;
}

bool testPushBackRange()
{
  int arr[] = {1, 2, 3, 4, 5};
  topit::Vector< int > v;
  v.pushBackRange(arr, 5);
  
  bool sizeOk = (v.getSize() == 5);
  bool allCorrect = true;
  for (size_t i = 0; i < v.getSize(); ++i)
  {
    if (v[i] != static_cast< int >(i + 1))
    {
      allCorrect = false;
      break;
    }
  }
  return sizeOk && allCorrect;
}

bool testInsertAtBeginning()
{
  topit::Vector< int > v;
  v.pushBack(2);
  v.pushBack(3);
  v.insert(0, 1);
  
  return (v[0] == 1) && (v[1] == 2) && (v[2] == 3) && (v.getSize() == 3);
}

bool testInsertAtEnd()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.insert(2, 3);
  
  return (v[0] == 1) && (v[1] == 2) && (v[2] == 3) && (v.getSize() == 3);
}

bool testInsertRangeAtBeginning()
{
  int arr[] = {1, 2, 3};
  topit::Vector< int > v;
  v.pushBack(4);
  v.pushBack(5);
  v.insert(0, arr, 3);
  
  return (v[0] == 1) && (v[1] == 2) && (v[2] == 3) && 
         (v[3] == 4) && (v[4] == 5) && (v.getSize() == 5);
}

bool testInsertRangeAtEnd()
{
  int arr[] = {3, 4, 5};
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.insert(2, arr, 3);
  
  return (v[0] == 1) && (v[1] == 2) && (v[2] == 3) && 
         (v[3] == 4) && (v[4] == 5) && (v.getSize() == 5);
}

bool testEraseAtBeginning()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.pushBack(3);
  v.erase(0);
  
  return (v[0] == 2) && (v[1] == 3) && (v.getSize() == 2);
}

bool testEraseAtEnd()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.pushBack(3);
  v.erase(2);
  
  return (v[0] == 1) && (v[1] == 2) && (v.getSize() == 2);
}

bool testEraseRangeAtBeginning()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.pushBack(3);
  v.pushBack(4);
  v.erase(0, 2);
  
  return (v[0] == 3) && (v[1] == 4) && (v.getSize() == 2);
}

bool testEraseRangeAtEnd()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.pushBack(3);
  v.pushBack(4);
  v.erase(2, 2);
  
  return (v[0] == 1) && (v[1] == 2) && (v.getSize() == 2);
}

bool testEqualityOperator()
{
  topit::Vector< int > v1;
  v1.pushBack(1);
  v1.pushBack(2);
  v1.pushBack(3);
  
  topit::Vector< int > v2;
  v2.pushBack(1);
  v2.pushBack(2);
  v2.pushBack(3);
  
  topit::Vector< int > v3;
  v3.pushBack(1);
  v3.pushBack(2);
  
  return (v1 == v2) && !(v1 == v3);
}

bool testInequalityOperator()
{
  topit::Vector< int > v1;
  v1.pushBack(1);
  v1.pushBack(2);
  v1.pushBack(3);
  
  topit::Vector< int > v2;
  v2.pushBack(1);
  v2.pushBack(2);
  v2.pushBack(4);
  
  topit::Vector< int > v3;
  v3.pushBack(1);
  v3.pushBack(2);
  v3.pushBack(3);
  
  return (v1 != v2) && !(v1 != v3);
}

bool testIteratorBeginEnd()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.pushBack(3);
  
  auto it = v.begin();
  return (*it == 1) && (*(++it) == 2) && (*(++it) == 3) && (++it == v.end());
}

bool testConstIteratorBeginEnd()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.pushBack(3);
  const topit::Vector< int >& cv = v;
  
  auto it = cv.begin();
  return (*it == 1) && (*(++it) == 2) && (*(++it) == 3) && (++it == cv.end());
}

bool testIteratorOperators()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.pushBack(3);
  v.pushBack(4);
  v.pushBack(5);
  
  auto it = v.begin();
  it += 2;
  bool plusEqual = (* it == 3);
  
  auto it2 = it + 2;
  bool plus = (* it2 == 5);
  
  it2 -= 2;
  bool minusEqual = (* it2 == 3);
  
  auto it3 = it2 - 2;
  bool minus = (* it3 == 1);

  ++it3;
  bool increment = (* it3 == 2);

  --it3;
  bool decrement = (*it3 == 1);
  
  return plusEqual && plus && minusEqual && minus && increment && decrement;
}

bool testLargeData()
{
  topit::Vector< int > v;
  const size_t N = 10000;
  
  for (size_t i = 0; i < N; ++i)
  {
    v.pushBack(static_cast< int >(i));
  }
  
  bool sizeOk = (v.getSize() == N);
  bool dataOk = true;
  for (size_t i = 0; i < N; ++i)
  {
    if (v[i] != static_cast< int >(i))
    {
      dataOk = false;
      break;
    }
  }
  
  return sizeOk && dataOk;
}

int main()
{
  using test_t = std::pair< const char*, bool(*)() >;
  test_t tests[] = {
    {"Empty vector", testEmptyVector},
    {"Size vector", testGetSize},
    {"Capacity vector", testGetCapacity},
    {"PushBack vector", testPushBack},
    {"PopBack vector", testPopBack},
    {"Element in bound acces", testElementInBoundAcces},
    {"Element out of bound acces", testElementOutOfBoundAcces},
    {"Element in bound const acces", testElementInBoundConstAccess},
    {"Element out of bound const acces", testElementOutOfBoundConstAccess},
    {"Copy for empty", testCopyConstructorForEmpty},
    {"Copy for non empty", testCopyConstructorForNonEmpty},
    {"Insert one", testInsertOne},
    {"Insert vector", testInsertByIterator},
    {"Erace one", testEraseOne},
    {"Erace several", testEraseSeveral},
    {"Insert one by iterator", testInsertOneIterator},
    {"Insert from to by iterator", testInsertFromToIterator},
    {"Insert from n by iterator", testInsertFromNIterator},
    {"Erace one by iterator", testEraceOneIterator},
    {"Erace from to by iterator", testEraceFromToIterator},
    {"Erace from n by iterator", testEraceFromNIterator},
    {"Non-empty vector for non-empty initializer list", testInitializerList},
    {"Default constructor", testDefaultConstructor},
    {"Constructor with size", testConstructorWithSize},
    {"Constructor with size and init", testConstructorWithSizeAndInit},
    {"Move constructor", testMoveConstructor},
    {"Copy assignment", testCopyAssignment},
    {"Move assignment", testMoveAssignment},
    {"Operator[]", testOperatorBracket},
    {"Const operator[]", testConstOperatorBracket},
    {"at() method", testAtMethod},
    {"const at() method", testConstAtMethod},
    {"reserve()", testReserve},
    {"shrinkToFit()", testShrinkToFit},
    {"normalize()", testNormalize},
    {"swap()", testSwap},
    {"pushBackCount()", testPushBackCount},
    {"pushBackRange()", testPushBackRange},
    {"insert at beginning", testInsertAtBeginning},
    {"insert at end", testInsertAtEnd},
    {"insert range at beginning", testInsertRangeAtBeginning},
    {"insert range at end", testInsertRangeAtEnd},
    {"erase at beginning", testEraseAtBeginning},
    {"erase at end", testEraseAtEnd},
    {"erase range at beginning", testEraseRangeAtBeginning},
    {"erase range at end", testEraseRangeAtEnd},
    {"operator==", testEqualityOperator},
    {"operator!=", testInequalityOperator},
    {"iterator begin/end", testIteratorBeginEnd},
    {"const iterator begin/end", testConstIteratorBeginEnd},
    {"iterator operators", testIteratorOperators},
    {"large data test", testLargeData}
  };
  
  const size_t count = sizeof(tests) / sizeof(test_t);
  std::cout << std::boolalpha;
  bool allPassed = true;
  
  for (size_t i = 0; i < count; ++i)
  {
    bool testResult = tests[i].second();
    allPassed = allPassed && testResult;
    std::cout << tests[i].first << ": " << testResult << '\n';
  }
  
  std::cout << "\n========================================\n";
  std::cout << "FINAL RESULT: " << allPassed << '\n';
  
  size_t passedCount = 0;
  for (size_t i = 0; i < count; ++i)
  {
    if (tests[i].second())
    {
      ++passedCount;
    }
  }
  std::cout << "Passed: " << passedCount << "/" << count << '\n';
  
  return 0;
}
