#pragma once
#include <glm.hpp>
#include "Camera.h"

class ThirdPersonCameraWithAvatar : public Camera {
public:
    ThirdPersonCameraWithAvatar(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed);

    void setTarget(glm::vec3 targetPosition);

    void keyControl(bool* keys, GLfloat deltaTime) override;
    void mouseControl(GLfloat xChange, GLfloat yChange) override;
    glm::vec3 targetPosition;
    glm::vec3 getMouse(GLfloat xChange, GLfloat yChange);
    GLfloat getMouseX() { return front.x; }
    GLfloat getMouseZ() { return front.z; }
    GLfloat getMouseY() { return front.y; }
    ~ThirdPersonCameraWithAvatar();
private:
};