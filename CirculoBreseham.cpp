#include "CirculoBreseham.h"

CirculoBreseham::CirculoBreseham(float radius, int numSegments) :
    radius(radius), numSegments(numSegments),
    VAO(0), VBO(0), EBO(0) {
}

CirculoBreseham::~CirculoBreseham() {
    // Liberar recursos
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteVertexArrays(1, &VAO);
}
/*
void CirculoBreseham::init() {
    vertices.clear();
    indices.clear();

    // Algoritmo de Bresenham para dibujar un c�rculo
    float theta = 2.0f * 3.1416 / numSegments;
    float c = cos(theta); // Pre-calcular el valor de coseno
    float s = sin(theta); // Pre-calcular el valor de seno
    float x = radius; // Coordenada x del primer punto
    float y = 0; // Coordenada y del primer punto

    for (int i = 0; i < numSegments; ++i) {
        // A�adir el punto al vector de v�rtices
        vertices.push_back(VertexColor(glm::vec3(x, y, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f))); // Ajusta el color seg�n sea necesario

        // Aplicar la rotaci�n a trav�s de la multiplicaci�n de una matriz de rotaci�n
        float newX = x * c - y * s;
        float newY = x * s + y * c;
        x = newX;
        y = newY;
    }

    // Crear los �ndices para formar tri�ngulos
    for (int i = 0; i < numSegments - 1; ++i) {
        indices.push_back(i);
        indices.push_back(i + 1);
        indices.push_back(numSegments);
    }
    // �ltimo tri�ngulo que conecta el �ltimo punto con el primero
    indices.push_back(numSegments - 1);
    indices.push_back(0);
    indices.push_back(numSegments);

    // Crear y cargar los datos en el VAO y VBO
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(VertexColor), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    // Atributo de posici�n
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexColor), (GLvoid*)offsetof(VertexColor, position));
    glEnableVertexAttribArray(0);
    // Atributo de color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexColor), (GLvoid*)offsetof(VertexColor, color));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0); // Desvincular VAO
}
*/
void CirculoBreseham::init() {
    vertices.clear();
    indices.clear();

    // Algoritmo de Bresenham para dibujar un c�rculo
    float theta = 2.0f * 3.1416 / numSegments;
    float c = cos(theta); // Pre-calcular el valor de coseno
    float s = sin(theta); // Pre-calcular el valor de seno
    float x = radius; // Coordenada x del primer punto
    float y = 0; // Coordenada y del primer punto

    for (int i = 0; i < numSegments; ++i) {
        // A�adir el punto al vector de v�rtices
        vertices.push_back(VertexColor(glm::vec3(x, y, 0.0f), glm::vec3(1.0f,0.0f, 1.0f), glm::vec3(0.0f))); // Color rojo

        // Aplicar la rotaci�n a trav�s de la multiplicaci�n de una matriz de rotaci�n
        float newX = x * c - y * s;
        float newY = x * s + y * c;
        x = newX;
        y = newY;
    }

    // Crear los �ndices para formar las l�neas del borde del c�rculo
    for (int i = 0; i < numSegments; ++i) {
        indices.push_back(i);
        indices.push_back((i + 1) % numSegments);
    }

    // Crear y cargar los datos en el VAO y VBO
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(VertexColor), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    // Atributo de posici�n
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexColor), (GLvoid*)offsetof(VertexColor, position));
    glEnableVertexAttribArray(0);
    // Atributo de color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexColor), (GLvoid*)offsetof(VertexColor, color));
    glEnableVertexAttribArray(1);
    // Atributo de normal
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(VertexColor), (GLvoid*)offsetof(VertexColor, normal));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0); // Desvincular VAO
}
void CirculoBreseham::load() {
    // No se necesita cargar nada aqu� en este caso
}

void CirculoBreseham::render() {
    glBindVertexArray(VAO);
    glLineWidth(30.0f); // Ajusta el grosor de las l�neas aqu� (en este caso, 5.0f)
    glDrawElements(GL_LINES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
