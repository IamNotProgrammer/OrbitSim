#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <iostream>

#define TMAX 1e9
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

	planetsystem system(2);

	/*FILE* Subject = fopen("Subject.txt", "r");
	fscanf(Subject, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
		&system.planet1.r.x, &system.planet1.r.y, &system.planet1.v.x, &system.planet1.v.y, &system.planet1.m,
		&system.planet2.r.x, &system.planet2.r.y, &system.planet2.v.x, &system.planet2.v.y, &system.planet2.m);
	fclose(Subject);*/



	system.planets[1].r.x = 149e9;
	system.planets[1].r.y = 0;
	system.planets[1].v.x = 0;
	system.planets[1].v.y = 29783.;
	system.planets[1].m = 5.9726e24;

	system.planets[0].r.x = 0.;
	system.planets[0].r.y = 0.;
	system.planets[0].v.x = 0.;
	system.planets[0].m = 1.989e30;
	system.planets[0].v.y = -(system.planets[1].m*system.planets[1].v.y) / system.planets[0].m;

	//printf("%lf %lf %lf %lf\n\n", system.planet1.r.x, system.planet1.r.y, system.planet2.r.x, system.planet2.r.y);

	//cout « system.planet1.r.x « "\t" « system.planet1.r.y « "\n";

	FILE* F = fopen("data.txt", "w");

	for (int i = 1; i <= TMAX; i++) {

		system.move();

		//if (i < 5)
			//printf("%i %lf %lf %lf %lf\n", i, system.planet1.r.x, system.planet1.r.y, system.planet2.r.x, system.planet2.r.y);

		if (i % 10000 == 0)
			fprintf(F, "%i %lf %lf %lf %lf\n", i, system.planets[0].r.x, system.planets[0].r.y, system.planets[1].r.x, system.planets[1].r.y);
	}
	fclose(F);
	//scanf("%*c");
}

/* scanf("%*c %*c %*c");
*/