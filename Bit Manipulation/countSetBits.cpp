#include <iostream>
using namespace std;

int main()
{
    // Brian Kernighan's Algorithm
      unsigned int count = 0;
      while (N) {
          N = N & (N - 1);
          count++;
      }
        
      cout<<count<<endl;

    return 0;
}
