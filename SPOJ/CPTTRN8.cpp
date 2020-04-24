#include <iostream>
using namespace std;

int main()
{
	int tc, rows, cols, sz;
	
	cin >> tc;
	while (tc--)
	{
		cin >> rows >> cols >> sz;
		rows *= 2*sz;
		cols *= 2*sz;
		
		int l, r, ct_l, ct_r;
		for (int i=0; i<rows; i++) {
			ct_l = ct_r = 0;
			
			if (i%(2*sz) < sz) {
				l = (sz-1-(i%(2*sz)));
				r = sz+(i%(2*sz));
				
				for (int j=0; j<cols; j++) {
					if (j==l) {
						cout << "/";
						l += 2*sz;
						ct_l++;
					}
					else if (j==r) {
						cout << "\\";
						r += 2*sz;
						ct_r++;
					}
					else if (ct_l != ct_r) cout << "*";
					else cout << ".";
				}
			}
			else {
				l = i%sz;
				r = (2*sz-1)-(i%sz);
				
				for (int j=0; j<cols; j++) {
					if (j==l) {
						cout << "\\";
						l += 2*sz;
						ct_l++;
					}
					else if (j==r) {
						cout << "/";
						r += 2*sz;
						ct_r++;
					}
					else if (ct_l != ct_r) cout << "*";
					else cout << ".";
				}
			}
			cout << endl;
		}
		if(tc) cout << endl;
	}
	
	return 0;
}
