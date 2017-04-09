#include <fstream>
using namespace std;
int sliyanie () {
	int p=1;
	int x,y;
	ifstream f_1=("./f_1.txt"), f_2=("./f_2.txt");
	ofstream f_3 ("./f_3.txt"), f_4 ("./f_4.txt");
	if (f_2) {
		f_1 >> x;
		f_2 >> y;
		while (f_1 && f_2) {
			int a=1, b=1;
			while ( a < p && b < p ) {
				if ( x < y ) {
					f_3 << x;
					a++;
					f_1 >> x;
				}
				else {
					f_3 << y;
					b++;
					f_2 >> y;
				}
			}
			while ( a < p ) {
				f_3 << x;
				a++;
				f_1 >> x;
			}
			while ( b < p ) {
				f_4 << y;
				b++;
				f_2 >> y;
			}
		}
	}
}