#include <iostream>
#include <vector>
#include <string>
#include <math.h>

struct vec {
	std::vector<int>a;
	std::vector<int>b;
	std::vector<int>res;
	int scaler;
	double size;
};
void adding(std::vector<int>& temp, char a) {
	std::cout << "Input coordinate "<<a<<": ";
	char dob = '0';
	do {
		int t = 0;
		std::cin >> t;
		temp.push_back(t);
		std::cout << "Do you want add coordinate? (+/-) ";
		std::cin >> dob;
	} while (dob == '+');
}

void add(vec& temp) {
	for (int i = 0; i < temp.a.size(); i++) {
		temp.res.push_back(temp.a[i] + temp.b[i]);
	}
	std::cout << "Summ of two vectors is: ";
	for (int i = 0; i < temp.res.size(); i++) {
		std::cout << temp.res[i];
		if (temp.res.size()-1>i)
			std::cout << ", ";
		else
			std::cout << ".";
	}
	std::cout << "\n";
}
void subtract(vec& temp) {
	for (int i = 0; i < temp.a.size(); i++) {
		temp.res.push_back(temp.b[i] - temp.a[i]);
	}
	std::cout << "Sutrakt of two vectors is: ";
	for (int i = 0; i < temp.res.size(); i++) {
		std::cout << temp.res[i];
		if (temp.res.size() - 1 > i)
			std::cout << ", ";
		else
			std::cout << ".";
	}
	std::cout << "\n";
}
void scale(vec& temp) {
	for (int i = 0; i < temp.a.size(); i++) {
		temp.res.push_back(temp.a[i]*temp.scaler);
	}
	std::cout << "result of multiplication of a vestor by a scalar: ";
	for (int i = 0; i < temp.res.size(); i++) {
		std::cout << temp.res[i];
		if (temp.res.size() - 1 > i)
			std::cout << ", ";
		else
			std::cout << ".";
	}
	std::cout << "\n";
}
void length(vec& temp, std::vector<int> a) {
	int sum = 0;
	for (int i = 0; i < a.size(); i++) {
		a[i] = pow(a[i],2);
		sum += a[i];
	}
	temp.size = sqrt(sum);
	std::cout << "The length of vector is: " << temp.size << "\n";
}
void normalize(vec& temp) {
	std::vector<double> norm;
	for (int i = 0; i < temp.a.size(); i++) {
		norm.push_back(temp.a[i] / temp.size);
	}
	std::cout << "Normalize vector is: ";
	for (int i = 0; i < norm.size(); i++) {
		std::cout << norm[i];
		if (norm.size() - 1 > i)
			std::cout << ", ";
		else
			std::cout << ".";
	}
	std::cout << "\n";
}
int main() {
	vec vect;
	std::string action;
	std::cout << "Choose action: ";
	std::cin >> action;
	if (action == "add") {
		adding(vect.a, 'a');
		adding(vect.b, 'b');
		add(vect); 
	}
	else
	if (action == "subtract") {
		adding(vect.a, 'a');
		adding(vect.b, 'b');
		subtract(vect);
	}
	else 
		if (action == "scale") {
			adding(vect.a, 'a');
			std::cout << "Input scalar: ";
			std::cin >> vect.scaler;
			scale(vect);
		}
		else if (action == "length") {
			adding(vect.a, 'a');
			length(vect,vect.a);
		}
		else if (action == "normalize") {
			adding(vect.a, 'a');
			length(vect,vect.a);
		}
}