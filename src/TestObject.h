#pragma once
#include "Component.hpp"
#include "GameData.h"
#include "Texture.h"
#include "Transform.hpp"
#include <GL/glut.h>

class TestObjcet : public Component {
private:
	Texture* texture;
public:
	TestObjcet() {
		texture = new Texture("textures/building2.ppm");
	}

	~TestObjcet() {
	}

	void Update() {}
	void Draw() {
		texture->SetTexture();
		glEnable(GL_TEXTURE_2D);
		glPushMatrix();
		{
			Size3D<float> size;
			size = parent->GetComponent<Transform>()->GetSize();
			glTranslated(0, 2, 0);
			glScaled(size.width, size.height, size.depth);
			glutSolidCube(1);
		}
		glPopMatrix();

		//éläpå`É|ÉäÉSÉì	
		glBegin(GL_QUADS);
		{
			glVertex3d(0, 0, -10);
			glVertex3d(0, 5, -10);
			glVertex3d(5, 5, -10);
			glVertex3d(5, 0, -10);
		}
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
};