// فانوس رمضان.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iostream>
#include <stdlib.h> //Needed for "exit" function


  //Include OpenGL header files, so that we can use OpenGL
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "imageloader.h"

using namespace std;

GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
		0,                            //0 for now
		GL_RGB,                       //Format OpenGL uses for image
		image->width, image->height,  //Width and height
		0,                            //The border of the image
		GL_RGB, //GL_RGB, because pixels are stored in RGB format
		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
						  //as unsigned numbers
		image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

GLuint _textureId_bottom;
GLuint _textureId_middle;
GLuint _textureId_top;

//Called when a key is pressed
void handleKeypress(unsigned char key, //The key that was pressed
	int x, int y) {    //The current mouse coordinates
	switch (key) {
	case 27://Escape key
		exit(0); //Exit the program
	}
}

//Initializes 3D rendering
void initRendering() {
	//Makes 3D drawing work when something is in front of something else
	glEnable(GL_DEPTH_TEST);
	//Image* image1= loadBMP("bottom2.bmp");
	Image* image2 = loadBMP("pp.bmp");
	//Image* image3 = loadBMP("top2.bmp");

	//_textureId_bottom = loadTexture(image1);
	_textureId_middle= loadTexture(image2);
	// _textureId_top= loadTexture(image3);

	//delete image1;
	delete image2;
	//delete image3;
}

//Called when the window is resized
void handleResize(int w, int h) {
	//Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective


//Called when the window is resized
	//Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0,                  //The camera angle
		(double)w / (double)h, //The width-to-height ratio
		1.0,                   //The near z clipping coordinate
		200.0);                //The far z clipping coordinate
}


//Draws the 3D scene
void drawScene() {
	//Clear information from last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

	glEnable(GL_TEXTURE_2D);
	////////////////front side
	

	
	glBindTexture(GL_TEXTURE_2D, _textureId_middle);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	
	glPushMatrix();  //bottom
	

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.0f,-3.5f, -15.0f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1.0f, -3.5f, -15.0f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.3f, -5.0f, -15.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.3f, -5.0f, -15.0f);
	
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _textureId_middle);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBegin(GL_POLYGON);   //middle

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.6f, 0.0f, -15.0f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1.6f, 0.0f, -15.0f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.0f, -3.5f, -15.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.0f, -3.5f, -15.0f);

	glEnd();
	

	glBegin(GL_POLYGON);   //top
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.7f, 2.0f, -15.0f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.7f, 2.0f, -15.0f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.6f, 0.0f, -15.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.6f, 0.0f, -15.0f);

	glEnd();


	/////////////////back side
	
	//glPushMatrix();  //bottom
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.0f, -3.5f, -30.0f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1.0f, -3.5f, -30.0f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.3f, -5.0f, -30.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.3f, -5.0f, -30.0f);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, _textureId_middle);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBegin(GL_POLYGON);   //middle

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.6f, 0.0f, -30.0f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1.6f, 0.0f, -30.0f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.0f, -3.5f, -30.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.0f, -3.5f, -30.0f);

	glEnd();


	glBegin(GL_POLYGON);   //top
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.7f, 2.0f, -30.0f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.7f, 2.0f, -30.0f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.6f, 0.0f, -30.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.6f, 0.0f, -30.0f);

	glEnd();

	////////////right side


	glBindTexture(GL_TEXTURE_2D, _textureId_middle);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


//	glPushMatrix();  //bottom
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(1.0f, -3.5f, -15.0f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1.0f, -3.5f, -30.0f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.3f, -5.0f, -30.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1.3f, -5.0f, -15.0f);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, _textureId_middle);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBegin(GL_POLYGON);   //middle

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(1.6f, 0.0f, -15.0f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1.6f, 0.0f, -30.0f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.0f, -3.5f, -30.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1.0f, -3.5f, -15.0f);

	glEnd();


	glBegin(GL_POLYGON);   //top
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.7f, 2.0f, -15.0f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.7f, 2.0f, -30.0f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.6f, 0.0f, -30.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1.6f, 0.0f, -15.0f);

	glEnd();

	//left side


	glBindTexture(GL_TEXTURE_2D, _textureId_middle);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBegin(GL_POLYGON);  //bottom
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.0f, -3.5f, -30.0f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f, -3.5f, -15.0f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.3f, -5.0f, -15.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.3f, -5.0f, -30.0f);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, _textureId_middle);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBegin(GL_POLYGON);   //middle

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.6f, 0.0f, -30.0f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.6f, 0.0f, -15.0f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.0f, -3.5f, -15.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.0f, -3.5f, -30.0f);

	glEnd();


	glBegin(GL_POLYGON);   //top
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.7f, 2.0f, -30.0f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.7f, 2.0f, -15.0f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.6f, 0.0f, -15.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.6f, 0.0f, -30.0f);

	glEnd();
	glPopMatrix();
	


	











	glutSwapBuffers(); //Send the 3D scene to the screen
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400); //Set the window size

	//Create the window
	glutCreateWindow("Basic Shapes - videotutorialsrock.com");
	initRendering(); //Initialize rendering

	//Set handler functions for drawing, keypresses, and window resizes
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.
	return 0; //This line is never reached
}