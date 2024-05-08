#pragma once
#include <glew.h>

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>

#include <glfw3.h>
#include "ThirdPersonCameraWithAvatar.h"

class Avatar {
private:
    glm::vec3 position; // Posición del avatar
    // Otros miembros relevantes, como modelo, texturas, etc.
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;

    GLfloat yaw;
    GLfloat pitch;

    GLfloat moveSpeed;
    GLfloat turnSpeed;
    ThirdPersonCameraWithAvatar* thirdPersonCameraAvatar; // Puntero a la tercera cámara
public:
    Avatar(glm::vec3 startPosition);
    // Métodos para establecer y obtener la posición del avatar
    void setPosition(glm::vec3 newPosition);
    glm::vec3 move(bool* keys, GLfloat deltaTime);
    glm::vec3 getPosition() const;

};