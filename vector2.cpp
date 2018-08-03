// vector::back
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector;

  myvector.push_back(10);
   std::cout << ' ' << myvector.back() <<'\n' <<'\n';

  while (myvector.back() != 0)
  {
    myvector.push_back ( myvector.back() -1 );
     std::cout << ' ' << myvector.back()<<'\n';
  }
 std::cout << ' ' << myvector.size() <<'\n' <<'\n';
  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size() ; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  return 0;
}
