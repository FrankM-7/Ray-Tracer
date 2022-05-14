#include "Sphere.h"
#include <iostream>

using namespace std;

Sphere::Sphere() {
	cout << "is a sphere" << endl;
}

bool Sphere::hit(glm::vec3 ray) {
	cout << "yea" << endl;
	return false;
}
