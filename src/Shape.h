#pragma once
#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <string>
#include <vector>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shape
{
private:

public:
	Shape();
	virtual bool hit(glm::vec3 ray);
};

#endif
