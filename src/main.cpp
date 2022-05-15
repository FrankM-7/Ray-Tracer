#include <iostream>
#include <string>
#include <Windows.h>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Image.h"
#include "Camera.h"
#include "Scene.h"
#include "Shape.h"
#include "Sphere.h"

using namespace std;

string RESOURCE_DIR = "../resources/"; // Where the resources are loaded from

int main(int argc, char **argv)
{
	//int sceneChoice = atoi(argv[1]);
	//int widthHeight = atoi(argv[2]);
	//string filename = argv[3];

	//auto image = make_shared<Image>(widthHeight, widthHeight);
	
	//for (int i = 0; i < widthHeight; i++) {
	//	image->setPixel(10, i, 255, 0, 0);
	//}
	// calculate ray directions for every pixel
	int widthHeight = 1024;
	shared_ptr<Camera> cam = make_shared<Camera>(widthHeight, widthHeight, 45, 5, 'z', -1);
	shared_ptr<Scene> scene = make_shared<Scene>();
	shared_ptr<Shape> sphere = make_shared<Sphere>();
	Light light;
	light.position = glm::vec3(0, 3, 2);
	scene->addObject(sphere);
	scene->addCamera(cam);
	scene->addLight(light);

	auto image = make_shared<Image>(widthHeight, widthHeight);

	scene->draw(image);

	image->writeToFile("filename.png");
	return 0;
}
