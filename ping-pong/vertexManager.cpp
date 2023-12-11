//
//  vertexManager.cpp
//  ping-pong
//
//  Created by Nkatie3 on 09/12/2023.
//

#include "vertexManager.hpp"
#include <glad/glad.h>
#include <iostream>

void VertexManager::createAndBindBuffers() {
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);
  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
               GL_STATIC_DRAW);

  // Link Vertex Attributes
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

void VertexManager::drawTriangle() {
  glBindVertexArray(
      VAO); // seeing as we only have a single VAO there's no need to bind it
            // every time, but we'll do so to keep things a bit more organized
            //    glDrawArrays(GL_TRIANGLES, 0, 3);
            //    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void VertexManager::deleteShaders() {
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
}
