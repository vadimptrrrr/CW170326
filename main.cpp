#include <iostream>
#include "top-it-vector.hpp"

bool testEmptyVector()
{
  petrovVadim::Vector< int > v;
  return v.isEmpty();
}

bool testPushBack()
{
  petrovVadim::Vector< int > v;
  v.pushBack(1);
  v.pushBack(3);
  v.pushBack(2);
  return !v.isEmpty();
}

bool testPopBack()
{
  petrovVadim::Vector< int > v;
  v.pushBack(1);
  v.pushBack(3);
  v.pushBack(2);
  bool tmp = !v.isEmpty() && v.getCapacity() == 3;
  v.popBack();
  return tmp && v.getSize() == 2 && v.getCapacity() == 2;
}

int main()
{
  using test_t = std::pair< const char*, bool(*)() >;
  test_t tests[] =
  {
    { "Test Empty", testEmptyVector },
    { "Test add element", testPushBack },
    { "Test delete last element", testPopBack}
  };
  const size_t count = sizeof(tests) / sizeof(test_t);
  std::cout << std::boolalpha;
  bool pass = true;

  for (size_t i = 0; i < count; ++i)
  {
    bool res = tests[i].second;
    std::cout << tests[i].first << ": " << res << "\n";
    pass = pass && res;
  }

  std::cout << "REESULT: " << pass << "\n";
}
