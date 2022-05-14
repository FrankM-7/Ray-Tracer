#include "Sphere.h"
#include <iostream>

using namespace std;

Sphere::Sphere() {
	cout << "is a sphere" << endl;
	this->radius = 1;
	this->center = glm::vec3(0, 0, 0);
}

void Sphere::hit(glm::vec3 ray, glm::vec3 origin, vector<Hit>& hits, int objIndex) {
	glm::vec3 pc = origin - this->center;
	float a = glm::dot(ray, ray);
	float b = 2 * (glm::dot(ray, pc));
	float c = glm::dot(pc, pc) - glm::pow(this->radius, 2);
	float d = glm::pow(b, 2) - 4 * a * c;

	if (d > 0) {
		float t = (-b + glm::sqrt(d)) / (2 * a);
		glm::vec3 x = origin + t * ray;
		glm::vec3 n = (x - this->center) / this->radius;
		Hit hit(x, n, t, objIndex);
		hits.push_back(hit);

		t = (-b - glm::sqrt(d)) / (2 * a);
		x = origin + t * ray;
		n = (x - this->center) / this->radius;
		hit.x = x;
		hit.n = n;
		hit.t = t;
		hits.push_back(hit);
	}
}

void Sphere::scale(float radius) {
	this->radius = radius;
}