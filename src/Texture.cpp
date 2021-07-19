#include "Texture.h"

Texture::Texture(const char* filepath) {
	ReadPPMImage(filepath);
}

Texture::~Texture() {
}

void Texture::Update() {

}

void Texture::Draw() {

}

void Texture::ReadPPMImage(const char* filepath)
{
	FILE* fp;
	int  ch, i;
	if (fopen_s(&fp, filepath, "r") != 0) {
		fprintf(stderr, "Cannot open ppm file %s\n", filepath);
		exit(1);
	}
	for (i = 0; i < 4; i++) { 						// skip four in header
		while (1) {
			if ((ch = fgetc(fp)) != '#') break;		// skip comment
			fgets((char*)texImage, 1024, fp);   	// dummy read
			while (isspace(ch)) ch = fgetc(fp);  	// skip space
		}
		while (!isspace(ch)) ch = fgetc(fp);		// read header
		if (i < 3) {
			while (isspace(ch)) ch = fgetc(fp);		// skip terminator
		}
	}
	fread(texImage, 1, imageWidth * imageHeight * 3, fp);	// read RGB data
	fclose(fp);
}

void Texture::SetTexture()
{
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0,
		GL_RGB, GL_UNSIGNED_BYTE, texImage);
}
