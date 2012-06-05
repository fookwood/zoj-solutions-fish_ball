// PERFORMER: ELF
// DATE: Dec. 17th, 2007
// TITLE: Humble Numbers
#include<fstream>
using namespace std;


bool ishumble(long num)
{ while(!(num%2)) num/=2;
  while(!(num%3)) num/=3;
  while(!(num%5)) num/=5;
  while(!(num%7)) num/=7;
  return num==1;
}

int main()
{ long humble[5842];
  int k = 0; 
  ofstream out("out.txt"); 
  for(long i = 1l; i < 2000000000l; i++) {
    if(ishumble(i)) {
      out << (humble[k++] = i) << "l, "; 
    if(k % 10 == 0) out << endl;     } 
  }
  out << 2000000000l << "l\n"; 
  out.close();  
}
