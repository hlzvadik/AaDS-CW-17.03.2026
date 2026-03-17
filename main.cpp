#include <iostream>
#include "top-it-vector.hpp"

bool testEmptyVector()
{
  topit::Vector< int > v;
  bool res = v.is_empty();
  return res;
}

int main()
{
  using test_t = std::pair< const char*, bool(*)() >;
  test_t tests[] = {{"Empty vector", testEmptyVector}};
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
