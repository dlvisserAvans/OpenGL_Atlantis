#include "StartupScene.h"
#include "Texture.h"
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include "Scene.h"
#include <map>
#include "imgui.h"

extern std::map<Scenes, Scene*> scenes;
extern Scene* currentScene;
extern GLFWwindow* window;

StartupScene::StartupScene()
{
	startupTexture = new Texture("data/startupScreen.png");
}

void StartupScene::draw()
{
	tigl::shader->setProjectionMatrix(glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -100.0f, 100.0f));
	tigl::shader->setViewMatrix(glm::mat4(1.0f));
	tigl::shader->setModelMatrix(glm::mat4(1.0f));
	tigl::shader->enableTexture(true);
	startupTexture->bind();
	tigl::begin(GL_QUADS);
	tigl::addVertex(tigl::Vertex::PT(glm::vec3(-1, 1, 0), glm::vec2(0, 1)));
	tigl::addVertex(tigl::Vertex::PT(glm::vec3(1, 1, 0), glm::vec2(1, 1)));
	tigl::addVertex(tigl::Vertex::PT(glm::vec3(1, -1, 0), glm::vec2(1, 0)));
	tigl::addVertex(tigl::Vertex::PT(glm::vec3(-1, -1, 0), glm::vec2(0, 0)));
	tigl::end();


	glEnable(GL_DEPTH_TEST);
	tigl::shader->enableLighting(true);
	tigl::shader->setLightCount(1);
	tigl::shader->setLightDirectional(0, true);
	tigl::shader->setLightPosition(0, glm::vec3(1, 1, 1));
	tigl::shader->setLightAmbient(0, glm::vec3(0.2f, 0.2f, 0.2f));
	tigl::shader->setLightDiffuse(0, glm::vec3(0.9f, 0.9f, 0.9f));
	tigl::shader->setLightSpecular(0, glm::vec3(0.1f, 0.1f, 0.1f));
	tigl::shader->setProjectionMatrix(glm::ortho(0.0f, 1400.0f, 0.0f, 800.0f, -100.0f, 100.0f));
	tigl::shader->enableTexture(false);
	tigl::shader->enableColor(true);


	tigl::shader->enableLighting(false);
	glDisable(GL_DEPTH_TEST);



}

void StartupScene::onKey(int key, int scancode, int action, int mods)
{
}

void StartupScene::update()
{
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		currentScene = scenes[Scenes::INGAME];
	}
}
