#include <iostream>
#include "top-it-vector.hpp"

bool testEmptyVector()
{
  petrovVadim::Vector< int > v;
  return v.isEmpty();
}

int main()
{
  using test_t = std::pair< const char*, bool(*)() >;
  test_t tests[] =
  {
    { "Test Empty", testEmptyVector }
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
