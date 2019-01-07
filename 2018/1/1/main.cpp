#include <fstream>
#include <iostream>

int main()
{
  int frequ = 0;
  int input;

  std::ifstream fin("input.txt");
  if (!fin)
  {
    std::cout << "bad file" << std::endl;
    exit(EXIT_FAILURE);
  }

  while (fin >> input)
  {
    frequ += input;
  }

  std::cout << frequ << std::endl;
}
