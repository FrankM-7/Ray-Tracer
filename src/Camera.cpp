#include "Camera.h"
#include <iostream>

using namespace std;

Camera::Camera() {
	cout << "ERROR: Need to Specify Camera Width/Height" << endl;
}

Camera::Camera(int width, int height, float fov, float distance, char axis, int direction) {
	// float aspectRatio = (float) width / (float) height;
	glm::vec3 cam = glm::vec3(0, 0, distance);

	float heightOneSquare = 2 * glm::tan(glm::radians(fov / 2)) / height;
	float heightHalfSquare = heightOneSquare / 2;

	// used to translate the plane to make the middle (0,0)
	float fullPlaneMiddle = heightOneSquare * height / 2;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			glm::vec3 p = glm::vec3((j * heightOneSquare + heightHalfSquare) - fullPlaneMiddle, (i * heightOneSquare + heightHalfSquare) - fullPlaneMiddle, distance + direction);
			glm::vec3 dir = glm::normalize(p - cam);
			rays.push_back(dir);
		}
	}
	cout << rays.size() << endl;
	testing.push_back(1);
}

vector<glm::vec3> Camera::getRays() {
	return this->rays;
}

vector<glm::vec3> Camera::getVector() {
	vector<glm::vec3> ret;
	cout << "rays size: " << this->testing.size() << endl;
	for (int i = 0; i < 5; i++) {
		ret.push_back(glm::vec3(i,i,i));
	}
	return ret;
}