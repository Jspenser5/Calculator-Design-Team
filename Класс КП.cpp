//[a,b]+[c,d]*2*[x,y]
#include<iostream>
using namespace std;

class complex {
public:
	double Re;
	double Im;
	void set(double R, double I) {
		Re = R;
		Im = I;
	}
	void print() {
		cout << Re << " + " << Im << "i\n";
	}
	complex operator +(complex c2) {
		complex tmp;
		tmp.set(this->Re + c2.Re, this->Im + c2.Im);
		return tmp;
	}
	complex operator -(complex c2) {
		complex tmp;
		tmp.set(this->Re - c2.Re, this->Im - c2.Im);
		return tmp;
	}
	complex operator *(complex c2) {
		complex tmp;
		tmp.set((this->Re)*(c2.Re)- (this->Im) * (c2.Im), (this->Re)*(c2.Im)+ (this->Im) * (c2.Re));
		return tmp;
	}
	complex operator /(complex c2) {
		complex tmp;
		tmp.set(((this->Re) * (c2.Re) + (this->Im) * (c2.Im))/(c2.Re*c2.Re+ c2.Im*c2.Im), ((this->Im) * (c2.Re)-(this->Re) * (c2.Im))/ (c2.Re * c2.Re + c2.Im * c2.Im));
		return tmp;
	}
	complex operator =(complex cm)
	{
		Re = cm.Re;
		Im = cm.Im;
		return *this;
	}
};

int main() {
	complex a,b,c;
	a.set(1, 2);
	b.set(5, -2);
	c = a / b;
	c.print();
	return 0;
}