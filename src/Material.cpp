#include "Material.h"

Material::Material()
{
	material = {
		{0.2,0.2,0.2,1.0},
		{0.8,0.8,0.8,0.8},
		{0.0,0.0,0.0,1.0},
		{0.0,0.0,0.0,1.0},
		0.0,
	};
}

Material::Material(MaterialParam mat)
{
	material = mat;
}

Material::~Material()
{

}

void Material::EnableMaterial(const int& option = 31)
{
	if (option & AMBIENT) glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
	if (option & DIFFUSE) glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
	if (option & SPECULAR) glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
	if (option & EMISSION) glMaterialfv(GL_FRONT, GL_EMISSION, material.emission);
	if (option & SHININESS) glMaterialfv(GL_FRONT, GL_SHININESS, &material.shininess);
}

void Material::SetMaterial(MaterialParam mat)
{
	material = mat;
}

MaterialParam Material::GetMaterial()
{
	return material;
}


