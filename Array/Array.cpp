#include "CArray.h"
#include <iostream>
#include <random>

std::string get_string(unsigned int length)
{
  static const char alphanum[] = "0123456789"
                                 "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                 "abcdefghijklmnopqrstuvwxyz";
  std::string str;
  for (unsigned int i = 0; i < length - 1; ++i)
  {
    str.push_back(alphanum[rand() % (sizeof(alphanum) - 1)]);
  }
  return str;
}

template <typename TData>
void print_array(const CArray<TData> & _array)
{
  std::cout << std::endl
            << "Array contains " << _array.size() << " elements" << std::endl
            << std::endl;
  for (unsigned int i = 0; i < _array.size(); i++)
  {
    std::cout << _array[i] << " ";
  }
  // std::cout << std::endl << std::endl << "-----" << std::endl;
}

int main()
{
  std::random_device device;
  std::mt19937 engine(device());
  std::uniform_int_distribution<unsigned int> distribution(0, 9);

  for (int i = 1; i <= 4; i++)
  {
    CArray<int> data;
    unsigned int count = distribution(engine);
    for (unsigned int i = 0; i < count; i++)
    {
      std::cout << get_string(count) << std::endl;
      // data.push_back(distribution(engine));
    }

    // print_array(data);
    // data.sort();
    // print_array(data);
    // std::cout << "*****" << std::endl;
  }
}
