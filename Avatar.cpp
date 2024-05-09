#include "Avatar.h"

// Implementación del constructor
Avatar::Avatar(glm::vec3 startPosition) : position(startPosition) {
    // Constructor para inicializar la posición del avatar
}

// Implementación del método para establecer la posición del avatar
void Avatar::setPosition(glm::vec3 newPosition) {
    position = newPosition;
    //printf("Posicion v¿cambio");
}

glm::vec3 Avatar::move(bool* keys, GLfloat deltaTime) {
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
    return position;
}
// Implementación del método para obtener la posición del avatar
glm::vec3 Avatar::getPosition() const {
    return position;
}
