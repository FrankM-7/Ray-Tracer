#pragma once
#ifndef _LIGHT_H
#define _LIGHT_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Light {
private:
public:
	glm::vec3 position;
	Light();
};

#endif
