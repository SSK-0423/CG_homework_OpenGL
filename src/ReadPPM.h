//#pragma once
//#include <stdio.h>
//#include <GL/glut.h>
//#define	imageWidth 256
//#define	imageHeight 256
//
//unsigned char texImage[imageHeight][imageWidth][3];
//
//void readPPMImage(const char* filename)
//{
//	FILE* fp;
//	int  ch, i;
//
//	if (fopen_s(&fp, filename, "r") != 0) {
//		fprintf(stderr, "Cannot open ppm file %s\n", filename);
//		exit(1);
//	}
//	for (i = 0; i < 4; i++) { 						// skip four in header
//		while (1) {
//			if ((ch = fgetc(fp)) != '#') break;		// skip comment
//			fgets((char*)texImage, 1024, fp);   	// dummy read
//			while (isspace(ch)) ch = fgetc(fp);  	// skip space
//		}
//		while (!isspace(ch)) ch = fgetc(fp);		// read header
///* Newline or other single terminator after header may exist. */
//		if (i < 3) {
//			while (isspace(ch)) ch = fgetc(fp);		// skip terminator
//		}
//	}
//	fread(texImage, 1, imageWidth * imageHeight * 3, fp);	// read RGB data
//	fclose(fp);
//}