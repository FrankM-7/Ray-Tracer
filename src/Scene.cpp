#include "Scene.h"

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

Scene::Scene() {

}

void Scene::addCamera(shared_ptr<Camera> camera) {
	this->camera = camera;
}

void Scene::addObject(shared_ptr<Shape> object) {
	this->objects.push_back(object);
}

void Scene::draw() {
	cout << this->camera->getVector().size() << endl;
	/*for (int i = 0; i < this->camera->rays.size(); i++) {
		cout << "heello" << endl;
	}*/
}

