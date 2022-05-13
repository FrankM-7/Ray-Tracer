#pragma once
#ifndef _CAMERA_H
#define _CAMERA_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <vector>

using namespace std;

class Camera
{ 
private:
	vector<glm::vec3> rays;
public:
	Camera();
	
	// width and height of the image; float fov (angle between axis and top of rayplane) distance on the axis; axis options: x, y, z; direction camera is looking (-1 or 1)
	Camera(int width, int height, float fov, float distance, char axis, int direction);

};

#endif
