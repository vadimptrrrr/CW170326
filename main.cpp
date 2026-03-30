#include <iostream>
#include "top-it-vector.hpp"

bool testInitializerList()
{
  petrovVadim::Vector< int > v{1, 2};
  return v.getSize() == 2 && (v[0] == 1) && (v[1] == 2);
}

bool testInsertOperation()
{
  petrovVadim::Vector< int > v;
  insert(v, 0, 1);
  insert(v, 0, 2);
  insert(v, 1, 3);
  return v[0] == 2 && v[1] == 3 && v[2] == 1;
}

bool testCopyConstructorForEmpty()
{
  petrovVadim::Vector< int > v;
  petrovVadim::Vector< int > vv = v;
  return v == vv;
}

bool testCopyConstructorForNonEmpty()
{
  petrovVadim::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.pushBack(3);
  petrovVadim::Vector< int > vv = v;
  return v == vv;
}

bool testElementAccess()
{
  petrovVadim::Vector< int > v;
  v.pushBack(1);
  try
  {
    int& val = v.at(0);
    return val == 1;
  }
  catch(...)
  {
    return false;
  }
}

bool testElementOutOfBoundAccess()
{
  petrovVadim::Vector< int > v;
  try
  {
    v.at(0);
    return false;
  }
  catch(const std::out_of_range &)
  {
    return true;
  }
  catch(...)
  {
    return false;
  }
  
}

bool testEmptyVector()
{
  // std::cout << __func__ << "\n";
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
    { "Test initilizer", testInitializerList },
    { "Test insert element", testInsertOperation },
    { "Test copy empty vector", testCopyConstructorForEmpty },
    { "Test copy non empty vector", testCopyConstructorForNonEmpty },
    { "Test elment access", testElementAccess },
    { "Inbound access", testElementOutOfBoundAccess },
    { "Test Empty", testEmptyVector },
    { "Test add element", testPushBack },
    { "Test delete last element", testPopBack }
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
  // Плодсчёт пройденных и не пройденных
  // Выоыодить непршедшие тесты
}
