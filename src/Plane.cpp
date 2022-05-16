#include "Plane.h"
#include <iostream>

using namespace std;

Plane::Plane() {
	this->position = glm::vec3(0, -1, 0);
	this->normal = glm::vec3(0, 1, 0);
}

void Plane::translate(float x, float y, float z) {
	this->position = glm::vec3(x, y, z);
}

void Plane::normalSet(float x, float y, float z) {
	glm::vec3 nor = glm::normalize(glm::vec3(x, y, z));
	this->normal = nor;
}

void Plane::hit(glm::vec3 ray, glm::vec3 origin, vector<Hit>& hits, int objIndex) {
	float t = glm::dot(this->normal, (this->position - origin)) / (glm::dot(this->normal, ray));
	if (t > 0) {
		glm::vec3 x = origin + t * ray;
		Hit hit(x, this->normal, t, objIndex);
		hits.push_back(hit);
	}
}

bool Plane::intersects(glm::vec3 ray, glm::vec3 originRay, float distance) {
	float t = glm::dot(this->normal, (this->position - originRay)) / (glm::dot(this->normal, ray));
		
	if (t > 0.0001 && t < distance) {
		return true;
	}
	return false;
}
