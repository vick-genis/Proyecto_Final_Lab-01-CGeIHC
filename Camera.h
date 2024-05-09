#pragma once

#include <glew.h>

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>

#include <glfw3.h>

class Camera
{
public:
	Camera();
	//Camera(glm::vec3 position, glm::vec3 target, glm::vec3 worldup);
	Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed);
	//Camera(glm::vec3 position, float pitch, float yaw, glm::vec3 worldup);
	virtual void keyControl(bool* keys, GLfloat deltaTime);
	virtual void mouseControl(GLfloat xChange, GLfloat yChange);

	glm::vec3 getCameraPosition();
	glm::vec3 getCameraDirection();
	glm::mat4 calculateViewMatrix();
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;

	GLfloat yaw;
	GLfloat pitch;

	GLfloat moveSpeed;
	GLfloat turnSpeed;

	//Agregamos varaibles para el movimiento del cursor
	float speedZ = 0.0f;
	float speedX = 0.0f;
	float speedY = 0.0f;
	
	~Camera();

private:
	

protected:
	

	void ProcessMouseMovement(float deltaX, float deltaY);
	void UpdateCameraPosition();

	void update();
};
