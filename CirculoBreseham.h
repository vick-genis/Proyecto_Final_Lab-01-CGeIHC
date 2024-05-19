#pragma once
#ifndef CIRCULO_BRESEHAM_H
#define CIRCULO_BRESEHAM_H
#include <vector>
#include <cmath>
#include "definition.h" 

class CirculoBreseham {
public:
    CirculoBreseham(float radius, int numSegments);
    void init();
    void load();
    void render();
    virtual ~CirculoBreseham();
private:
    std::vector<VertexColor> vertices;
    std::vector<GLuint> indices;
    float radius;
    int numSegments;

    GLuint VAO, VBO, EBO;
};
#endif // CIRCULO_BRESEHAM_H