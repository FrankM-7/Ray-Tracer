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
	


	


	int sceneChoice = 1;
	if (sceneChoice == 1) {
		int widthHeight = 1024;
		auto image = make_shared<Image>(widthHeight, widthHeight);

		shared_ptr<Camera> cam = make_shared<Camera>(widthHeight, widthHeight, 45, 5, 'z', -1);
		shared_ptr<Scene> scene = make_shared<Scene>();

		Shape* redSphere = new Sphere();
		redSphere->translate(-.5, -1, 1);
		redSphere->diffuse(1, 0, 0);
		redSphere->specular(1, 1, .5);
		redSphere->ambient(.1, .1, .1);
		redSphere->shiny(100);

		
		Shape* greenSphere = new Sphere();
		greenSphere->translate(.5, -1, -1);
		greenSphere->diffuse(0, 1, 0);
		greenSphere->specular(1, 1, .5);
		greenSphere->ambient(.1, .1, .1);
		greenSphere->shiny(100);

		Shape* blueSphere = new Sphere();
		blueSphere->translate(0, 1, 0);
		blueSphere->diffuse(0, 0, 1);
		blueSphere->specular(1, 1, .5);
		blueSphere->ambient(.1, .1, .1);
		blueSphere->shiny(100);

		Light light(-2, 1, 1);

		scene->addObject(redSphere);
		scene->addObject(blueSphere);
		scene->addObject(greenSphere);

		scene->addCamera(cam);
		scene->addLight(light);

		scene->draw(image);

		image->writeToFile("filename.png");
	}

	ShellExecuteW(NULL, L"open", L"C:\\Users\\Frank M\\Desktop\\RayTracer\\build\\filename.png", L"", L"C:\\Users\\Frank M\\Desktop\\RayTracer\\build\\", SW_SHOW);

	return 0;
}
