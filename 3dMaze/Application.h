#pragma once
#include <memory>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include "Game.h"
#include <glm/glm.hpp>
class Application
{
private:
	int _versionMajor,_versionMinor;

	GLFWwindow* _window;

	unsigned int _width, _height;

	std::string _title;

	GamePtr _game;

	double _time;

	static std::shared_ptr<Application> _instance;

	glm::vec2 _mousePos;

	bool _shutdown;

	void initWindow();

	void startLoop();

	void update();

	void render();

	static void windowResized(GLFWwindow* window, int width, int height);

	static void mouseMotion(GLFWwindow* window,double x, double y);

	static void KeyboardKeys(GLFWwindow* window,int key, int scancode,int action,int mods);

	static void MouseButtons(GLFWwindow* window,int button,int action,int mods);

	Application(int GLMAJOR = 2, int GLMINOR = 1);


public:
	static std::shared_ptr<Application> get(int GLMajor=2,int GLMinor = 1);

	static GamePtr getGame();

	glm::vec2 getMousePosition();

	void setMousePosition(float x, float y);

	~Application();

	bool init(unsigned int width = 800, unsigned int height = 600, std::string title = "Window");

	void start(GamePtr game);

	glm::vec2 getWindowSize();
	void shutdown();
};
typedef std::shared_ptr<Application> ApplicationPtr;