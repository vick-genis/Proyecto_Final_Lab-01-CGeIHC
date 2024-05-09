#include "Avatar.h"

// Implementaci�n del constructor
Avatar::Avatar(glm::vec3 startPosition) : position(startPosition) {
    // Constructor para inicializar la posici�n del avatar
}

// Implementaci�n del m�todo para establecer la posici�n del avatar
void Avatar::setPosition(glm::vec3 newPosition) {
    position = newPosition;
    //printf("Posicion v�cambio");
}

glm::vec3 Avatar::move(bool* keys, GLfloat deltaTime) {
    GLfloat velocity = moveSpeed * deltaTime;
    // Movimiento hacia adelante en direcci�n al objetivo
    if (keys[GLFW_KEY_W])
    {
        position += front * velocity;
        //avatar.setPosition(position); // Actualiza la posici�n del avatar
    }

    // Movimiento hacia atr�s en direcci�n opuesta al objetivo
    if (keys[GLFW_KEY_S])
    {
        position -= front * velocity;
        //avatar.setPosition(position); // Actualiza la posici�n del avatar
    }

    // Movimiento hacia la izquierda (lateral) relativo al objetivo
    if (keys[GLFW_KEY_A])
    {
        position -= right * velocity;
        // avatar.setPosition(position); // Actualiza la posici�n del avatar
    }

    // Movimiento hacia la derecha (lateral) relativo al objetivo
    if (keys[GLFW_KEY_D])
    {
        position += right * velocity;
        //avatar.setPosition(position); // Actualiza la posici�n del avatar
    }
    return position;
}
// Implementaci�n del m�todo para obtener la posici�n del avatar
glm::vec3 Avatar::getPosition() const {
    return position;
}
