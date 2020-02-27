#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <iostream>

#define TMAX 1e6
#define DT 1 
const double G = 6.67408e-11;


using namespace std;



class vector {
public:

	double x{};
	double y{};

	vector() = default;

	vector(const double & a, const double & b){
		vector res;
		res.x = a;
		res.y = b;
	}



	vector operator +(const vector& b)const {
		vector res;
		res.x = b.x + x;
		res.y = b.y + y;
		return res;
	}
	vector operator -(const vector& b)const {
		vector res;
		res.x = b.x - x;
		res.y = b.y - y;
		return res;
	}

	vector operator +(const double& i)const {
		vector res;
		res.x = x + i;
		res.y = y + i;
		return res;
	}
	vector operator -(const double& i)const {
		vector res;
		res.x = x - i;
		res.y = y - i;
		return res;
	}
	vector operator *(const double& i)const {
		vector res;
		res.x = x * i;
		res.y = y * i;
		return res;
	}
	vector operator /(const double& i)const {
		vector res;
		res.x = x / i;
		res.y = y / i;
		return res;
	}
	double operator *(const vector& b) {
		double res;
		res = x * b.x + y * b.y;
		return res;
	}
	double operator /(const vector& b) {
		double res;
		res = x * b.x - y * b.y;
		return res;
	}
	bool operator == (const vector& b)const {
		return(x == b.x) && (y == b.y);
	}
	bool operator !=(const vector& b)const {
		return !(*this == b);
	}
	vector& operator=(const vector& b) {
		x = b.x;
		y = b.y;
		return *this;
	}
	vector operator +=(const vector& b) {
		x=b.x + x;
		y=b.y + y;
		return *this;
	}

	vector operator -=(const vector& b) {
		x = x - b.x;
		y = y - b.y;
		return *this;
	}

	vector operator-()const {
		vector res;
		res.x = -x;
		res.y = -y;
		return res;
	}
};

double abs(const vector &vi){
	return sqrt(vi.x*vi.x + vi.y*vi.y);
}

vector operator +(double x, const vector& y) {
	return y + x;
}
vector operator -(double x, const vector& y) {
	return y - x;
}
vector operator *(double x, const vector& y) {
	return y * x;
}
vector operator /(double x, const vector& y) {
	return y / x;
}

class planet {
public:
	double m{};
	vector r, v, f;

	planet() = default;

	void move() {
		r = r + v * DT;
		v = v + f/m * DT;
	}
};

class planetsystem {
public:
	planet *planets;
	unsigned N;

	explicit planetsystem(unsigned n){
		planets = new planet[n];
		N = n;
	}

	~planetsystem(){
		delete[]planets;
	}

	planetsystem(const planetsystem &A){
		planets = new planet[A.N];
		for (int i = 0; i < A.N; i++)
			planets[i] = A.planets[i];
		N = A.N;
	}

	void move(){
		vector f;
		for (int i = 0; i < N; i++)
			planets[i].f = vector(0., 0.);
		for (int i = 0; i < N; i++){
			for (int x = i + 1; x < N; x++){
				f = ((-G * (planets[i].m * planets[x].m)) / (pow(abs(planets[i].r - planets[x].r), 3))) * (planets[i].r - planets[x].r);
				planets[i].f += -f;
				planets[x].f += f;
			}
			planets[i].move();
		}

	}

};

int main() {

	planetsystem system(8);

	double alpha,beta, rocketvabs,rocketh;

	alpha = 90;
	beta = 0;
	rocketvabs = 15000;
	rocketh = 6550000. ;


	system.planets[0].r.x = 0.; //sun
	system.planets[0].r.y = 0.;
	system.planets[0].v.x = 0.;
	system.planets[0].v.y = 0.;
	system.planets[0].m = 1.989e30;

	system.planets[1].r.x = 57909227.e3; //mercury
	system.planets[1].r.y = 0.;
	system.planets[1].v.x = 0.;
	system.planets[1].v.y = 47360.;
	system.planets[1].m = 3.33022e23;

	system.planets[2].r.x = 108208930.e3; //venus
	system.planets[2].r.y = 0.;
	system.planets[2].v.x = 0.;
	system.planets[2].v.y = 35020.;
	system.planets[2].m = 4.8675e24;

	system.planets[3].r.x = 149e9; //earth
	system.planets[3].r.y = 0.;
	system.planets[3].v.x = 0.;
	system.planets[3].v.y = 29783.;
	system.planets[3].m = 5.9726e24;

	system.planets[4].r.x = 2.2794382e11; //mars
	system.planets[4].r.y = 0.;
	system.planets[4].v.x = 0.;
	system.planets[4].v.y = 24077.;
	system.planets[4].m = 6.4171e23;

	system.planets[5].r.x = 7.405736e11; //jupiter
	system.planets[5].r.y = 0.;
	system.planets[5].v.x = 0.;
	system.planets[5].v.y = 13070.;
	system.planets[5].m = 1.8986e27;

	system.planets[6].r.x = system.planets[3].r.x + 384399000.; //moon
	system.planets[6].r.y = 0.;
	system.planets[6].v.x = 0.;
	system.planets[6].v.y = system.planets[3].v.y + 1023.;
	system.planets[6].m = 7.3477e22;

	system.planets[7].r.x = system.planets[3].r.x + cos(beta / 180 * 3.1415)*rocketh; //rocket
	system.planets[7].r.y = system.planets[3].r.y + sin(beta / 180 * 3.1415)*rocketh;
	system.planets[7].v.x = system.planets[3].v.x + cos(alpha / 180 * 3.1415)*rocketvabs;
	system.planets[7].v.y = system.planets[3].v.y + sin(alpha / 180 * 3.1415)*rocketvabs;
	system.planets[7].m = 100.;

	/*
	system.planets[1].r.x = 149e9; //saturn
	system.planets[1].r.y = 0;
	system.planets[1].v.x = 0;
	system.planets[1].v.y = 29783.;
	system.planets[1].m = 5.9726e24;

	system.planets[1].r.x = 149e9; //uranus
	system.planets[1].r.y = 0;
	system.planets[1].v.x = 0;
	system.planets[1].v.y = 29783.;
	system.planets[1].m = 5.9726e24;

	system.planets[1].r.x = 149e9; //neptune
	system.planets[1].r.y = 0;
	system.planets[1].v.x = 0;
	system.planets[1].v.y = 29783.;
	system.planets[1].m = 5.9726e24;
*/






	FILE* F = fopen("data.txt", "w");
	FILE* F1 = fopen("data1.txt", "w");
	FILE* F2 = fopen("data2.txt", "w");

	for (int i = 1; i <= TMAX; i++) {

		system.move();

		if (i % 10000 == 0){
			for (int j = 0; j < system.N; j++)
				fprintf(F, "%lf %lf ", system.planets[j].r.x, system.planets[j].r.y);
			fprintf(F, "\n");
		}
		if (i % 100 == 0){
			vector nxnastran = system.planets[3].r - system.planets[6].r;
			vector solidworks = system.planets[3].r - system.planets[7].r;
			fprintf(F1, "%lf %lf %lf %lf", nxnastran.x, nxnastran.y, solidworks.x, solidworks.y);
			fprintf(F1, "\n");
		}
		if (i % 100 == 0){
			vector catia = system.planets[7].r - system.planets[6].r;
			fprintf(F2, "%lf %lf ", catia.x, catia.y);
			fprintf(F2, "\n");
		}
	}
	fclose(F);
}
