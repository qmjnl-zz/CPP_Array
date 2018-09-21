#include "CArray.h"
#include <iostream>
#include <random>

// Get random string with length of _length
std::string get_string(
    unsigned int _length
  )
{
  static const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";
  std::string str;
  for (unsigned int i = 0; i < _length; ++i)
  {
    str.push_back(alphanum[rand() % (sizeof(alphanum) - 1)]);
  }
  return str;
}

// Print _array data
template <typename TData>
void print_array(
    const CArray<TData> & _array
  )
{
  std::cout << "Array contains " << _array.size() << " elements:" << std::endl;
  for (unsigned int i = 0; i < _array.size(); i++)
  {
    std::cout << _array[i] << " ";
  }
  std::cout << std::endl << std::endl;
}

int main()
{
  //
  // Numbers test
  //

  std::cout << "*** NUMBERS TEST ***" << std::endl << std::endl;

  std::random_device device;
  std::mt19937 engine(device());
  std::uniform_int_distribution<unsigned int> distValue(0, 100);
  CArray<int> dataN;

  // New array
  std::cout << "*** Just created array:" << std::endl;
  print_array(dataN);

  // Adding elements
  std::cout << "*** Adding elements:" << std::endl;
  for (int i = 0; i < 20; i++)
  {
    dataN.push_back(distValue(engine));
  }
  print_array(dataN);

  // Sorting array
  std::cout << "*** Sorting:" << std::endl;
  dataN.sort();
  print_array(dataN);

  // Erasing each 2-nd element
  std::cout << "*** Erasing each 2-nd element:" << std::endl;
  unsigned int size = dataN.size();
  for (int i = size - 1; i > 0; i = i - 2)
  {
    dataN.erase(i);
  }
  print_array(dataN);

  // Adding random elements to random positions
  std::cout << "*** Adding random element to random position:" << std::endl;
  for (int i = 0; i < 10; i++)
  {
    std::uniform_int_distribution<unsigned int> distIndex(0, dataN.size() - 1);
    unsigned int index = distIndex(engine);
    int value = distValue(engine);
    dataN.insert(index, value);
    std::cout << "Index: " << index << ", value: " << value << std::endl;
    print_array(dataN);
  }
  print_array(dataN);

  // Clearing array
  std::cout << "*** Clearing array:" << std::endl;
  dataN.clear();
  print_array(dataN);

  //
  // Strings test
  //

  std::cout << std::endl
            << std::endl
            << "*** STRINGS TEST ***" << std::endl
            << std::endl;

  std::uniform_int_distribution<unsigned int> distString(1, 10);
  CArray<std::string> dataS;

  // New array
  std::cout << "*** Just created array:" << std::endl;
  print_array(dataS);

  // Adding elements
  std::cout << "*** Adding elements:" << std::endl;
  for (int i = 0; i < 15; i++)
  {
    dataS.push_back(get_string(distString(engine)));
  }
  print_array(dataS);

  // Sorting array
  std::cout << "*** Sorting:" << std::endl;
  dataS.sort();
  print_array(dataS);

  // Removing if
  std::cout << "*** Removing words containing any of 'abcde':" << std::endl;
  size = dataS.size();
  for (int i = size - 1; i >= 0; i--)
  {
    if (dataS[i].find_first_of("abcde") != std::string::npos)
    {
      dataS.erase(i);
    }
  }
  print_array(dataS);

  // Adding random elements to random positions
  std::cout << "*** Adding random element to random position:" << std::endl;
  for (int i = 0; i < 3; i++)
  {
    std::uniform_int_distribution<unsigned int> distIndex(0, dataS.size() - 1);
    unsigned int index = distIndex(engine);
    std::string value = get_string(distString(engine));
    dataS.insert(index, value);
    std::cout << "Index: " << index << ", value: " << value << std::endl;
    print_array(dataS);
  }
  print_array(dataS);
}
