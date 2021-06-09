#pragma once

#include "DrawComponent.h"
#include "tigl.h"
#include "Texture.h"
#include <vector>

using tigl::Vertex;


class SkyboxComponent : public DrawComponent{

private:
	std::vector<std::vector<Vertex>> verts;
	float x = 0, y = 0, z = 0;

public:
	SkyboxComponent(float size, Texture** textures);
	~SkyboxComponent();

	Texture** textures;

	virtual void draw() override;

	// Inherited via DrawComponent
	virtual std::vector<glm::vec3> getVertices() override;

};

