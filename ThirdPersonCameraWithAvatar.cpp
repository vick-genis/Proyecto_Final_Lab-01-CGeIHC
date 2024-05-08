#include "ThirdPersonCameraWithAvatar.h"
#include <glew.h>
#include <glfw3.h>
#include <gtc\matrix_transform.hpp>

ThirdPersonCameraWithAvatar::ThirdPersonCameraWithAvatar(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed)
    : Camera(startPosition, startUp, startYaw, startPitch, startMoveSpeed, startTurnSpeed){}

void ThirdPersonCameraWithAvatar::setTarget(glm::vec3 targetPosition) {
    this->targetPosition = targetPosition;
}

void ThirdPersonCameraWithAvatar::keyControl(bool* keys, GLfloat deltaTime) {
    // Implementación para control de teclado específico de la cámara en tercera persona
    GLfloat velocity = moveSpeed * deltaTime;
    // Movimiento hacia adelante en dirección al objetivo
    if (keys[GLFW_KEY_W])
    {
        position += front * velocity;
        //avatar.setPosition(position); // Actualiza la posición del avatar
    }

    // Movimiento hacia atrás en dirección opuesta al objetivo
    if (keys[GLFW_KEY_S])
    {
        position -= front * velocity;
        //avatar.setPosition(position); // Actualiza la posición del avatar
    }

    // Movimiento hacia la izquierda (lateral) relativo al objetivo
    if (keys[GLFW_KEY_A])
    {
        position -= right * velocity;
        // avatar.setPosition(position); // Actualiza la posición del avatar
    }

    // Movimiento hacia la derecha (lateral) relativo al objetivo
    if (keys[GLFW_KEY_D])
    {
        position += right * velocity;
        //avatar.setPosition(position); // Actualiza la posición del avatar
    }
}

void ThirdPersonCameraWithAvatar::mouseControl(GLfloat xChange, GLfloat yChange) {
    // Implementación para control de mouse específico de la cámara en tercera persona
    xChange *= turnSpeed;
    yChange *= turnSpeed;

    yaw += xChange;
    pitch += yChange;

    // Limitar el ángulo de inclinación para evitar giros excesivos
    if (pitch > 89.0f)
    {
        pitch = 89.0f;
    }
    if (pitch < -89.0f)
    {
        pitch = -89.0f;
    }

    getMouse(xChange, yChange);
   //printf("El valor de floatValue es: %f y %f\n", xChange, yChange);
    update(); // Actualizar la dirección de la cámara según los cambios en el ángulo de vista
}
// Función para obtener los valores de xChange, yChange y 0.0f
glm::vec3 ThirdPersonCameraWithAvatar::getMouse(GLfloat xChange, GLfloat yChange) {
    // Multiplica los valores de cambio por la velocidad de giro
    
    //printf("El valor de floatValue es: %f y %f\n", xChange, yChange);
    // Devuelve los valores en un vector glm::vec3
    return glm::vec3(xChange, yChange, 0.0f);
}

ThirdPersonCameraWithAvatar::~ThirdPersonCameraWithAvatar()
{
}