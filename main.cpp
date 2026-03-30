#include <iostream>
#include "top-it-vector.hpp"

bool testInitializerList()
{
  petrovVadim::Vector< int > v{1, 2};
  return v.getSize() == 2 && (v[0] == 1) && (v[1] == 2);
}

bool testEraseOperation()
{
  petrovVadim::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.pushBack(3);
  v.erase(1);
  return (v.getSize() == 2) && (v[0] == 1) && (v[1] == 3);
}

bool testEraseRangeOperation()
{
  petrovVadim::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.pushBack(3);
  v.pushBack(4);
  v.erase(1, 3);
  return (v.getSize() == 2) && (v[0] == 1) && (v[1] == 4);
}

bool testInsertOperation()
{
  petrovVadim::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.pushBack(3);
  v.insert(1, 999);
  return (v.getSize() == 4) && (v[1] == 999);
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
  v.popBack();
  return (v.getSize() == 2) && (v[0] == 1) && (v[1] == 3);
}

int main()
{
  using test_t = std::pair< const char*, bool(*)() >;
  test_t tests[] =
  {
    { "Test initilizer", testInitializerList },
    { "Test erase element", testEraseOperation },
    { "Test erase range", testEraseRangeOperation },
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

  size_t success = 0;
  size_t fail = 0;

  for (size_t i = 0; i < count; ++i)
  {
    bool res = tests[i].second();
    if (res)
    {
      ++success;
    }
    else
    {
      ++fail;
      std::cout << "FAILED: " << tests[i].first << "\n";
    }
  }

  std::cout << "SUCCESS: " << success << "\nFAILED: " << fail << "\n";
  // Плодсчёт пройденных и не пройденных
  // Выоыодить непршедшие тесты
}
