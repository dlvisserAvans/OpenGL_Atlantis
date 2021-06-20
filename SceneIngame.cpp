#include <iostream>

#include <GL/glew.h>
#include <Gl/GLU.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <map>
#include <thread>

#include "SceneInGame.h"
#include "Texture.h"
#include "tigl.h"
#include "Scene.h"
#include "imgui.h"
#include "GameObject.h"
#include "SkyboxComponent.h"
#include "FishModelComponent.h"
#include "ObjModel.h"

extern std::map<Scenes, Scene*> scenes;
extern Scene* currentScene;
extern GLFWwindow* window;
FpsCam* camera;

GameObject* backgroundBox;
std::list<GameObject*> objects;
std::vector<ObjModel*> models;


SceneInGame::SceneInGame()
{
	initSkyboxTextures();
	buildupSkybox();
	camera = new FpsCam(window);

	createFaunaModels();

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

SceneInGame::~SceneInGame(){}

void SceneInGame::draw()
{	
	//glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//int viewport[4];
	//glGetIntegerv(GL_VIEWPORT, viewport);
	//glm::mat4 projection = glm::perspective(glm::radians(75.0f), viewport[2] / (float)viewport[3], 0.01f, 100.0f);


	//tigl::shader->setProjectionMatrix(projection);
	//tigl::shader->setViewMatrix(camera->getMatrix());
	initShaderDrawing();
	backgroundBox->draw();


	//glEnable(GL_DEPTH_TEST);


	for (auto& o : models) {
			tigl::shader->enableColor(false);
			tigl::shader->enableTexture(true);
			o->draw();
	}

	glDisable(GL_DEPTH_TEST);

	


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

void SceneInGame::initShaderDrawing() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	glm::mat4 projection = glm::perspective(glm::radians(75.0f), viewport[2] / (float)viewport[3], 0.01f, 1000.0f);
	tigl::shader->setViewMatrix(camera->getMatrix());
	tigl::shader->setProjectionMatrix(projection);
	tigl::shader->setModelMatrix(glm::mat4(1.0f));
	tigl::shader->enableColor(true);
	glEnable(GL_DEPTH_TEST);
}

void SceneInGame::buildupSkybox()
{
	backgroundBox = new GameObject(0);
	backgroundBox->position = glm::vec3(0, 0, 5);
	backgroundBox->addComponent(new SkyboxComponent(300, textureSkybox));
	objects.push_back(backgroundBox);
}

void SceneInGame::drawModels()
{
	for (auto model : models)
	{
		if (model->hasTexture())
		{
			//if (model->getName() == "RocketShip")
			//{
			//	//Static planet moon
			//	glm::mat4 modelMatrix(1.0f); // for scaling the rocket
			//	glm::vec3 movingVector(0, 0, movingRocket); // for moving the rocket
			//	modelMatrix = glm::rotate(modelMatrix, 180.0f, glm::vec3(1));
			//	//Rotate the rocket, wasnt rendered correctly
			//	modelMatrix = glm::scale(modelMatrix, glm::vec3(0.1f)); // for scaling the rocket
			//	modelMatrix = glm::translate(modelMatrix, movingVector); //translate vector for moving
			//	if (rocketLaunching)
			//	{
			//		movingRocket++;
			//		if (movingRocket >= 600)
			//		{
			//			rocketLaunching = false;
			//		}
			//	}

			//	if (!rocketLaunching)
			//	{
			//		movingRocket--;
			//		if (movingRocket <= 204)
			//		{
			//			rocketLaunching = true;
			//		}
			//	}
			//	tigl::shader->setModelMatrix(modelMatrix); // for scaling the rocket
			//}

			//if (model->getName() == "UFO")
			//{
			//	//Static UFO
			//	glm::mat4 matrixUFO(1.0f); // for scaling the rocket
			//	glm::vec3 movingVector(-40, -20, -175); // for moving the rocket
			//	matrixUFO = glm::rotate(matrixUFO, rotationUfo, glm::vec3(1));
			//	//Rotate the rocket, wasnt rendered correctly
			//	matrixUFO = glm::scale(matrixUFO, glm::vec3(0.5f)); // for scaling the rocket
			//	matrixUFO = glm::translate(matrixUFO, movingVector); //translate vector for moving
			//	rotationUfo = rotationUfo + 0.006f;
			//	tigl::shader->setModelMatrix(matrixUFO); // for scaling the rocket
			//}

			//if (model->getName() == "Sun")
			//{
			//	glm::mat4 scalingMatrixPlane(1.0f); // for scaling the moon
			//	glm::vec3 movingVector(-1400, -50, 0); // for moving the moon
			//	scalingMatrixPlane = glm::rotate(scalingMatrixPlane, glm::radians(rotationtest),
			//		glm::vec3(0.0f, 1.0f, 0.0f));
			//	scalingMatrixPlane = glm::scale(scalingMatrixPlane, glm::vec3(0.03f)); // for scaling the moon
			//	scalingMatrixPlane = glm::translate(scalingMatrixPlane, movingVector); //translate vector for moving
			//	tigl::shader->setModelMatrix(scalingMatrixPlane); // for scaling the moon
			//	rotationtest = rotationtest + 1.0f;
			//}

			if (model->getName() == "fish")
			{
				glm::mat4 scalingMatrixPlane(1.0f); // for scaling the moon
				//rotate the plane
				std::cout << "X IS" << camera->getPosition().x * 5 << std::endl;
				//std::cout << "Y IS" << camera->getPosition().y << std::endl;
				//std::cout << "Z IS" << camera->getPosition().z << std::endl;
				glm::vec3 movingVector((camera->getPosition().x * 10) - 80, (camera->getPosition().y * 10) - 150, camera->getPosition().z * 10);
				scalingMatrixPlane = glm::rotate(scalingMatrixPlane, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
				scalingMatrixPlane = glm::scale(scalingMatrixPlane, glm::vec3(0.1f)); // for scaling the moon
				scalingMatrixPlane = glm::translate(scalingMatrixPlane, movingVector); //translate vector for moving
				tigl::shader->setModelMatrix(scalingMatrixPlane); // for scaling the moon
			}


			tigl::shader->enableColor(false);
			tigl::shader->enableTexture(true);
		}
		else
		{
			tigl::shader->enableColor(true);
			tigl::shader->enableTexture(false);
		}
		model->draw();
		//std::cout << rotationtest << std::endl;
	}
}

void SceneInGame::onKey(int key, int scancode, int action, int mods)
{
	/*if (key == GLFW_KEY_DOWN && action == GLFW_RELEASE)
	{
		menuIndex = (menuIndex + 1) % 4;
	}*/
}

void SceneInGame::update()
{
	if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
	{
		currentScene = scenes[Scenes::PAUSE];
	}
	camera->update(window);
	//time += 0.01f;

}

void SceneInGame::initSkyboxTextures(){

	textureSkybox[0] = new Texture("data/images/uw_ft.jpg"); //middle
	textureSkybox[1] = new Texture("data/images/uw_rt.jpg"); //right
	textureSkybox[2] = new Texture("data/images/uw_lf.jpg"); //left
	textureSkybox[3] = new Texture("data/images/uw_bk.jpg"); //back
	textureSkybox[4] = new Texture("data/images/uw_dn.jpg"); // bottom
	textureSkybox[5] = new Texture("data/images/uw_up.jpg"); // top
}

void SceneInGame::createFaunaModels()
{
	//objects.clear();
	//GameObject* o = new GameObject(1);
	//o->addComponent(new FishModelComponent());
	//glm::vec3 pos = glm::vec3(0, 0, 0);
	//o->position = pos;
	//o->scale = glm::vec3(1.0f);
	////o->draw();
	//models.push_back(new ObjModel("data/models/Cube_Word_RaidersA.obj", "fish"));
	models.push_back(new ObjModel("data/models/fish.obj", "fish"));
	//models.push_back(new ObjModel("data/models/12265_Fish_v1_L2.obj", "fish2"));
	//models.push_back(new ObjModel("data/models/10010_Coral_v1_L3.obj", "Coral"));
	//models.push_back(new ObjModel("data/models/13007_Blue-Green_Reef_Chromis_v2_l3.obj", "fish3"));
}


