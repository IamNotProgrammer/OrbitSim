#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <iostream>

#define TMAX 1e8
#define DT 1 
const double G = 6.67408e-11;


using namespace std;



class vector {
public:

	double x{};
	double y{};

	vector() = default;



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
		//f = ((-G * (m * M)) / (pow(abs(r), 3))) * r - rPlanetTwo; //todo fix
		v = v + f/m * DT;
	}
};

class planetsystem {
public:
	planet planet1, planet2;

	void move(){
		vector f;
		f = ((-G * (planet1.m * planet2.m)) / (pow(abs(planet1.r - planet2.r), 3))) * (planet1.r - planet2.r);
		planet1.f = -f;
		planet1.move();
		planet2.f = f;
		planet2.move();
	}

};

int main() {

	planetsystem system;

	/*FILE* Subject = fopen("Subject.txt", "r");
	fscanf(Subject, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
		&system.planet1.r.x, &system.planet1.r.y, &system.planet1.v.x, &system.planet1.v.y, &system.planet1.m,
		&system.planet2.r.x, &system.planet2.r.y, &system.planet2.v.x, &system.planet2.v.y, &system.planet2.m);
	fclose(Subject);*/



	system.planet2.r.x = 149e9;
	system.planet2.r.y = 0;
	system.planet2.v.x = 0;
	system.planet2.v.y = 29783.;
	system.planet2.m = 5.9726e24;

	system.planet1.r.x = 0.;
	system.planet1.r.y = 0.;
	system.planet1.v.x = 0.;
	system.planet1.m = 1.989e30;
	system.planet1.v.y = -(system.planet2.m*system.planet2.v.y) / system.planet1.m;

	//printf("%lf %lf %lf %lf\n\n", system.planet1.r.x, system.planet1.r.y, system.planet2.r.x, system.planet2.r.y);

	//cout « system.planet1.r.x « "\t" « system.planet1.r.y « "\n";

	FILE* F = fopen("data.txt", "w");

	for (int i = 1; i <= TMAX; i++) {

		system.move();

		//if (i < 5)
			//printf("%i %lf %lf %lf %lf\n", i, system.planet1.r.x, system.planet1.r.y, system.planet2.r.x, system.planet2.r.y);

		if (i % 10000 == 0)
		fprintf(F, "%i %lf %lf %lf %lf\n", i, system.planet1.r.x, system.planet1.r.y, system.planet2.r.x, system.planet2.r.y);
	}
	fclose(F);
	//scanf("%*c");
}

/* scanf("%*c %*c %*c");
*/