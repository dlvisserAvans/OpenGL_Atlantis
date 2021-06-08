#include <GL/glew.h>
#include <Gl/GLU.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <map>
#include <thread>

#include "InGameScene.h"
#include "Texture.h"
#include "tigl.h"
#include "Scene.h"
#include "imgui.h"
#include "GameObject.h"
#include "SkyboxComponent.h"

extern std::map<Scenes, Scene*> scenes;
extern Scene* currentScene;
extern GLFWwindow* window;
FpsCam* camera;

GameObject* backgroundBox;

InGameScene::InGameScene()
{
	initSkyboxTextures();

	backgroundBox = new GameObject(0);
	backgroundBox->position = glm::vec3(0, 0, 5);
	backgroundBox->addComponent(new SkyboxComponent(100, textureSkybox));

	camera = new FpsCam(window);
	std::thread fpsCamThread(&FpsCam::update, camera, window);
	fpsCamThread.join();

	//glm::vec4 color(1.0f, 0, 1.0f, 1.0f);

	//std::vector<tigl::Vertex> vertices;
	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(-1, -1, -1), color, glm::vec3(0, 0, -1)));
	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(-1, 1, -1), color, glm::vec3(0, 0, -1)));
	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(1, 1, -1), color, glm::vec3(0, 0, -1)));
	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(1, -1, -1), color, glm::vec3(0, 0, -1)));

	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(-1, -1, 1), color, glm::vec3(0, 0, 1)));
	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(-1, 1, 1), color, glm::vec3(0, 0, 1)));
	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(1, 1, 1), color, glm::vec3(0, 0, 1)));
	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(1, -1, 1), color, glm::vec3(0, 0, 1)));

	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(1, -1, -1), color, glm::vec3(1, 0, 0)));
	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(1, -1, 1), color, glm::vec3(1, 0, 0)));
	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(1, 1, 1), color, glm::vec3(1, 0, 0)));
	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(1, 1, -1), color, glm::vec3(1, 0, 0)));

	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(-1, -1, -1), color, glm::vec3(-1, 0, 0)));
	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(-1, -1, 1), color, glm::vec3(-1, 0, 0)));
	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(-1, 1, 1), color, glm::vec3(-1, 0, 0)));
	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(-1, 1, -1), color, glm::vec3(-1, 0, 0)));

	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(-1, 1, -1), color, glm::vec3(0, 1, 0)));
	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(-1, 1, 1), color, glm::vec3(0, 1, 0)));
	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(1, 1, 1), color, glm::vec3(0, 1, 0)));
	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(1, 1, -1), color, glm::vec3(0, 1, 0)));

	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(-1, -1, -1), color, glm::vec3(0, -1, 0)));
	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(-1, -1, 1), color, glm::vec3(0, -1, 0)));
	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(1, -1, 1), color, glm::vec3(0, -1, 0)));
	//vertices.push_back(tigl::Vertex::PCN(glm::vec3(1, -1, -1), color, glm::vec3(0, -1, 0)));

	//kubusVbo = tigl::createVbo(vertices);
	//time = 0;
	//menuIndex = 0;
	//camera = new FpsCam(window);
}

void InGameScene::draw()
{	
	glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	glm::mat4 projection = glm::perspective(glm::radians(75.0f), viewport[2] / (float)viewport[3], 0.01f, 100.0f);


	tigl::shader->setProjectionMatrix(projection);
	tigl::shader->setViewMatrix(camera->getMatrix());

	backgroundBox->draw();

	//int viewport[4];
	//glGetIntegerv(GL_VIEWPORT, viewport);
	//glm::mat4 projection = glm::perspective(glm::radians(75.0f), viewport[2] / (float)viewport[3], 0.01f, 100.0f);

	//tigl::shader->setProjectionMatrix(projection);
	//tigl::shader->setViewMatrix(camera->getMatrix());
	////tigl::shader->setModelMatrix(glm::mat4(1.0f));

	//tigl::begin(GL_QUADS);
	//tigl::addVertex(tigl::Vertex::PT(glm::vec3(-1, 1, 0), glm::vec2(0, 1)));
	//tigl::addVertex(tigl::Vertex::PT(glm::vec3(1, 1, 0), glm::vec2(1, 1)));
	//tigl::addVertex(tigl::Vertex::PT(glm::vec3(1, -1, 0), glm::vec2(1, 0)));
	//tigl::addVertex(tigl::Vertex::PT(glm::vec3(-1, -1, 0), glm::vec2(0, 0)));
	//tigl::end();


	//glEnable(GL_DEPTH_TEST);
	//tigl::shader->enableLighting(true);
	//tigl::shader->setLightCount(1);
	//tigl::shader->setLightDirectional(0, true);
	//tigl::shader->setLightPosition(0, glm::vec3(1, 1, 1));
	//tigl::shader->setLightAmbient(0, glm::vec3(0.2f, 0.2f, 0.2f));
	//tigl::shader->setLightDiffuse(0, glm::vec3(0.9f, 0.9f, 0.9f));
	//tigl::shader->setLightSpecular(0, glm::vec3(0.1f, 0.1f, 0.1f));
	//tigl::shader->setProjectionMatrix(glm::ortho(0.0f, 1400.0f, 0.0f, 800.0f, -100.0f, 100.0f));
	//glm::mat4 modelMatrix(1.0f);
	//modelMatrix = glm::translate(modelMatrix, glm::vec3(200, 600 - 200 * menuIndex, 0));
	//modelMatrix = glm::rotate(modelMatrix, time, glm::vec3(1, 0, 0));
	//modelMatrix = glm::rotate(modelMatrix, glm::radians(45.0f), glm::vec3(0, 1, 0));
	//modelMatrix = glm::scale(modelMatrix, glm::vec3(50, 50, 50));
	//tigl::shader->setModelMatrix(modelMatrix);

	//tigl::shader->enableTexture(false);
	//tigl::shader->enableColor(true);

	//tigl::drawVertices(GL_QUADS, kubusVbo);
	//tigl::shader->enableLighting(false);
	//glDisable(GL_DEPTH_TEST);

	//ImGui::Begin("Startup screen inspector");
	//ImGui::DragFloat("Time", &time);
	//ImGui::InputInt("Menuoptie", &menuIndex);
	//ImGui::BeginChild("Dingen");
	//ImGui::LabelText("Hallo!", "Wereld");
	//ImGui::EndChild();
	//ImGui::End();
}

void InGameScene::onKey(int key, int scancode, int action, int mods)
{
	/*if (key == GLFW_KEY_DOWN && action == GLFW_RELEASE)
	{
		menuIndex = (menuIndex + 1) % 4;
	}*/
}

void InGameScene::update()
{
	if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
	{
		currentScene = scenes[Scenes::PAUSE];
	}
	camera->update(window);
	//time += 0.01f;

}


void InGameScene::initSkyboxTextures(){

	textureSkybox[0] = new Texture("data/images/uw_ft.jpg"); //middle
	textureSkybox[1] = new Texture("data/images/uw_lf.jpg"); //right
	textureSkybox[2] = new Texture("data/images/uw_rt.jpg"); //left
	textureSkybox[3] = new Texture("data/images/uw_bk.jpg"); //back
	textureSkybox[4] = new Texture("data/images/uw_dn.jpg"); // bottom
	textureSkybox[5] = new Texture("data/images/uw_up.jpg"); // top

}


