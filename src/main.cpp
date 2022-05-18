#include <iostream>
#include <string>
#include <Windows.h>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#define GLM_ENABLE_EXPERIMENTAL

#include "Image.h"
#include "Camera.h"
#include "Scene.h"
#include "Shape.h"
#include "Sphere.h"
#include "Plane.h"
#include "Ellipsoid.h"

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

	int sceneChoice = 1;
	if (sceneChoice == 1) {
		int widthHeight = 1024;
		auto image = make_shared<Image>(widthHeight, widthHeight);

		shared_ptr<Camera> cam = make_shared<Camera>(widthHeight, widthHeight, 45, 5, 'z', -1);
		shared_ptr<Scene> scene = make_shared<Scene>();

		Light light1(-1, 2, 1);
		light1.intensity = .5;
		Light light2(.5, -.5, 0);
		light2.intensity = .5;

		Shape* redSphere = new Sphere();
		redSphere->translate(.5, -.7, .5);
		redSphere->scale(.3);
		redSphere->diffuse(1, 0, 0);
		redSphere->ambient(.1, .1, .1);
		redSphere->specular(1, 1, .5);
		redSphere->shiny(100);

		Shape* blueSphere = new Sphere();
		blueSphere->translate(1, -.7, 0);
		blueSphere->scale(.3);
		blueSphere->diffuse(0, 0, 1);
		blueSphere->ambient(.1, .1, .1);
		blueSphere->specular(1, 1, .5);
		blueSphere->shiny(100);

		Shape* refSphere1 = new Sphere();
		refSphere1->translate(-.5, 0, -.5);
		refSphere1->scale(1);
		refSphere1->reflective();

		Shape* refSphere2 = new Sphere();
		refSphere2->translate(1.5, 0, -1.5);
		refSphere2->scale(1);
		refSphere2->reflective();

		Shape* floor = new Plane();
		floor->diffuse(1, 1, 1);
		floor->ambient(.1, .1, .1);
		floor->specular(0, 0, 0);
		floor->shiny(0);

		Shape* wall = new Plane();
		wall->translate(0, 0, -3);
		wall->normalSet(0, 0, 1);
		wall->diffuse(1, 1, 1);
		wall->ambient(.1, .1, .1);
		wall->specular(0, 0, 0);
		wall->shiny(0);

		scene->addObject(redSphere);
		scene->addObject(blueSphere);
		scene->addObject(floor);
		scene->addObject(wall);
		scene->addLight(light1);
		scene->addLight(light2);
		scene->addCamera(cam);
		scene->draw(image);

		image->writeToFile("filename.png");
	}

	ShellExecuteW(NULL, L"open", L"C:\\Users\\Frank M\\Desktop\\RayTracer\\build\\filename.png", L"", L"C:\\Users\\Frank M\\Desktop\\RayTracer\\build\\", SW_SHOW);

	return 0;
}
