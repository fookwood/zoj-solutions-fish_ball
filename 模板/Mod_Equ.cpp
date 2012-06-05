/////////////////////////////////////////////////////////
//                                                     //  
//          ax ≡b(mod n) 线性模方程求解               //
//                                                     //
//                                                     //
//     solve(a, b, n)： 返回一个vector，为方程的解，   //
//	 					若为空则方程无解               //
//                                                     //
//     如果GCD(a, n) | b, 则有GCD(a, n)个解,否则无解   // 
//                                                     //
//                                                     //
//           2008 CopyRight(c) by Jacmy                //
//                                                     //
/////////////////////////////////////////////////////////

#include <vector>
#include <cmath>
#include <set>

using namespace std;

class Mod_Equ
{
	private:
			vector<int> Extended_Euclid(int a, int b, int d)
			{
				vector <int> E, E1;	
				if (!b)
				{
					E.clear();
					E.push_back(d);
					E.push_back(1);
					E.push_back(0);										
					return E;
				}
				
				E = Extended_Euclid(b, a % b, d);
				
				E1.clear();
				E1.push_back(E[0]);
				E1.push_back(E[2]);
				E1.push_back(E[1] - int(a / b) * E[2]);
			
				return E1;
			}
			
			int GCD(int a, int b)
			{
				if (!b) return a;
				   else return GCD(b, a % b);
			}
		
	public:
		set <int> solve(int a, int b, int n)
		{
			vector <int> V;
			set <int> ans;
			int d;
			
			V.clear(); ans.clear();
			
			d = GCD(a, n);
			V = Extended_Euclid(a, n, d);
			
			if (!(b % d))
			{
				int x0 = (V[1] * b / d) % n;
				
				for (int i = 0; i < d; ++i)
				{
					int x1 = (x0 + i * n / d + n) % n;
					
					while (x1 < 0) x1 += n;
					
					ans.insert(x1);
				}
			}
			else return ans;
		}
};
