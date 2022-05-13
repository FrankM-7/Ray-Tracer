#include "Camera.h"
#include <iostream>

using namespace std;

Camera::Camera() {
	cout << "ERROR: Need to Specify Camera Width/Height" << endl;
}

Camera::Camera(int width, int height, float fov, float distance, char axis, int direction) {
	// float aspectRatio = (float) width / (float) height;
	float heightHalfSquare = (2 * glm::tan(glm::radians(fov/2)) / height)/2;
	
	float y = heightHalfSquare * (height - 1);
	for (int i = 0; i < height; i++) {
		float x = heightHalfSquare * (width - 1) * (-1);
		for (int j = 0; j < width; j++) {
			glm::vec3 square = glm::vec3(x, y, distance);
			glm::vec3 direction = square - glm::vec3(0, 0, distance);
			float magnitude = glm::sqrt(glm::pow(direction.x, 2) + glm::pow(direction.y, 2) + glm::pow(direction.z, 2));
			direction = glm::vec3(direction.x / magnitude, direction.y / magnitude, direction.z / magnitude);
			rays.push_back(glm::vec3(direction.x, direction.y, direction.z));

			x += heightHalfSquare * 2;
		}
		y -= heightHalfSquare * 2;
	}
	for (auto i : rays) cout << i.x << " " << i.y << " " << i.z << endl;
}