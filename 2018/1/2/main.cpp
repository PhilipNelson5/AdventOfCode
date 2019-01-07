#include <fstream>
#include <iostream>
#include <map>

int main()
{
  int frequ = 0;
  int input;
  std::map<int, bool> recvFrequ;

  recvFrequ.emplace(frequ, true);

  bool found = false;

  while (!found)
  {
    std::ifstream fin("input.txt");
    if (!fin)
    {
      std::cout << "bad file" << std::endl;
      exit(EXIT_FAILURE);
    }

    while (fin >> input)
    {
      frequ += input;

      if (recvFrequ.find(frequ) == std::end(recvFrequ))
      {
        recvFrequ.emplace(frequ, true);
      }
      else
      {
        std::cout << "TWICE: " << frequ << std::endl;
        found = true;
        break;
      }
    }
  }
  std::cout << "\nsize: " << recvFrequ.size() << std::endl;
  std::cout << "final frequency: " << frequ << std::endl;
}
