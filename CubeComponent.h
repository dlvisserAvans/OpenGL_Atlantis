#pragma once

#include "DrawComponent.h"
#include "tigl.h"
#include "Texture.h"
using tigl::Vertex;

#include <vector>

class CubeComponent : public DrawComponent
{
	std::vector<Vertex> verts;
	Texture* texture;
public:
	CubeComponent(float size);
	~CubeComponent();

	//virtual void setTexture(Texture* t) override;
	virtual void draw() override;

};

