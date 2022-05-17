#include "Ellipsoid.h"
#include <iostream>

using namespace std;

Ellipsoid::Ellipsoid() {
	this->radius = 1;
	this->center = glm::vec3(0, 0, 0);
}

void Ellipsoid::hit(glm::vec3 ray, glm::vec3 origin, vector<Hit>& hits, int objIndex) {
	glm::vec3 pPrime = glm::vec3(glm::inverse(E) * glm::vec4(origin, 1.0f));
	glm::vec3 vHatPrime = glm::vec3(glm::normalize(glm::inverse(E) * glm::vec4(ray, 0.0f)));

	float a5 = glm::dot(vHatPrime, vHatPrime);
	float b5 = 2.0f * (glm::dot(vHatPrime, pPrime));
	float c5 = glm::dot(pPrime, pPrime) - 1.0f;
	float d5 = glm::pow(b5, 2) - (4.0f * a5 * c5);

	glm::vec3 x5, regX, regN, nHat;
	float t5, regT;
	if (d5 > 0) {
		// 2 intercections
		t5 = (-b5 + glm::sqrt(d5)) / (2 * a5);
		x5 = pPrime + t5 * vHatPrime;
		regX = E * glm::vec4(x5, 1.0f);
		regN = glm::inverse(glm::transpose(E)) * glm::vec4(x5, 0.0f);
		nHat = glm::normalize(regN);
		regT = glm::length(regX - origin);

		if (glm::dot(glm::normalize(ray), (regX - origin)) < 0) {
			regT = -regT;
		}
		Hit hit1;
		hit1.t = regT;
		hit1.x = regX;
		hit1.n = nHat;
		hit1.objIndex = objIndex;
		hits.push_back(hit1);

		// 2 intercections
		t5 = (-b5 - glm::sqrt(d5)) / (2 * a5);
		x5 = pPrime + t5 * vHatPrime;
		regX = E * glm::vec4(x5, 1.0f);
		regN = glm::inverse(glm::transpose(E)) * glm::vec4(x5, 0.0f);
		nHat = glm::normalize(regN);
		regT = glm::length(regX - origin);

		if (glm::dot(glm::normalize(ray), (regX - origin)) < 0) {
			regT = -regT;
		}

		hit1.t = regT;
		hit1.x = regX;
		hit1.n = nHat;
		hit1.objIndex = objIndex;
		hits.push_back(hit1);
	}


}

bool Ellipsoid::intersects(glm::vec3 ray, glm::vec3 originRay, float distance) {
	glm::vec3 pPrime = glm::vec3(glm::inverse(E) * glm::vec4(originRay, 1.0f));
	glm::vec3 vHatPrime = glm::vec3(glm::normalize(glm::inverse(E) * glm::vec4(ray, 0.0f)));

	float a5 = glm::dot(vHatPrime, vHatPrime);
	float b5 = 2.0f * (glm::dot(vHatPrime, pPrime));
	float c5 = glm::dot(pPrime, pPrime) - 1.0f;
	float d5 = glm::pow(b5, 2) - (4.0f * a5 * c5);

	glm::vec3 x5, regX, regN, nHat;
	float t5, regT;
	if (d5 > 0) {
		// 2 intercections
		t5 = (-b5 + glm::sqrt(d5)) / (2 * a5);
		x5 = pPrime + t5 * vHatPrime;
		regX = E * glm::vec4(x5, 1.0f);
		regN = glm::inverse(glm::transpose(E)) * glm::vec4(x5, 0.0f);
		nHat = glm::normalize(regN);
		regT = glm::length(regX - originRay);

		if (glm::dot(glm::normalize(ray), (regX - originRay)) < 0) {
			regT = -regT;
		}
		
		if (regT > 0.001 && regT < distance) {
			return true;
		}

		// 2 intercections
		t5 = (-b5 - glm::sqrt(d5)) / (2 * a5);
		x5 = pPrime + t5 * vHatPrime;
		regX = E * glm::vec4(x5, 1.0f);
		regN = glm::inverse(glm::transpose(E)) * glm::vec4(x5, 0.0f);
		nHat = glm::normalize(regN);
		regT = glm::length(regX - originRay);

		if (glm::dot(glm::normalize(ray), (regX - originRay)) < 0) {
			regT = -regT;
		}

		if (regT > 0.001 && regT < distance) {
			return true;
		}
	}
	return false;
}
