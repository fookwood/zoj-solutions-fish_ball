// 1666272 2008-10-14 22:44:47 Accepted  1981 C++ 0 184 呆滞的慢板 

// 简单的分段函数，先把所有冰和水都化成 -30 度的冰，得到一定的能量在分段讨论。 

#include <iostream>
using namespace std;

double mw, mi, tw, ti, energy, mass;

int main() {
    while(cin >> mw >> mi >> tw >> ti &&
        (mw || mi || tw || ti)) {
        energy = (ti+30.0) * 2.09 * mi +
            mw * (335.0 + 30.0 * 2.09 + tw * 4.19);
        mass = mi + mw;
        if(energy < mass * 30.0 * 2.09) {
            printf("%.1lf g of ice and "
                "%.1lf g of water at %.1lf C\n",
                mass, 0.0, -30.0 + energy / mass / 2.09);
        }
        else if(energy < mass * (30.0 * 2.09 + 335.0)) {
            mw = (energy - mass * 30.0 * 2.09) / 335.0;
            mi = mass - mw;
            printf("%.1lf g of ice and "
                "%.1lf g of water at %.1lf C\n",
                mi, mw, 0.0);
        }
        else {
            printf("%.1lf g of ice and "
                "%.1lf g of water at %.1lf C\n",
                0.0, mass, (energy - mass * (30.0*2.09+335.0))/4.19/mass);
        }
    }
}
