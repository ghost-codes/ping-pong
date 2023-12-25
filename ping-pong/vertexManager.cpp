//
//  vertexManager.cpp
//  ping-pong
//
//  Created by Nkatie3 on 09/12/2023.
//

#include "vertexManager.hpp"
#include "shader.hpp"
#include "stb_image.h"
#include <glad/glad.h>
//
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <ostream>

void VertexManager::createAndBindBuffers() {
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
               GL_STATIC_DRAW);

  // position attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);
  // texture coord attribute
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
                        (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);
}

void VertexManager::drawTriangle(Shader ourShader) {
  glBindVertexArray(
      VAO); // seeing as we only have a single VAO there's no need to bind it
            // every time, but we'll do so to keep things a bit more organized
            //    glDrawArrays(GL_TRIANGLES, 0, 3);
            //    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  //
  // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  glm::vec3 cubePositions[] = {
      glm::vec3(0.0f, 0.0f, 0.0f),    glm::vec3(2.0f, 5.0f, -15.0f),
      glm::vec3(-1.5f, -2.2f, -2.5f), glm::vec3(-3.8f, -2.0f, -12.3f),
      glm::vec3(2.4f, -0.4f, -3.5f),  glm::vec3(-1.7f, 3.0f, -7.5f),
      glm::vec3(1.3f, -2.0f, -2.5f),  glm::vec3(1.5f, 2.0f, -2.5f),
      glm::vec3(1.5f, 0.2f, -1.5f),   glm::vec3(-1.3f, 1.0f, -1.5f)};
  for (unsigned int i = 0; i < 10; i++) {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, cubePositions[i]);
    float angle = glfwGetTime() * (i + 1) * 20;
    model =
        glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
    ourShader.setMat4("model", model);

    glDrawArrays(GL_TRIANGLES, 0, 36);
  }
  // glDrawArrays(GL_TRIANGLES, 0, 36);
}

void VertexManager::deleteShaders() {
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
}

void VertexManager::initTextures() {
  // load and create a texture
  // -------------------------
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D,
                texture); // all upcoming GL_TEXTURE_2D operations now have
                          // effect on this texture object
  // set the texture wrapping parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                  GL_REPEAT); // set texture wrapping to GL_REPEAT
                              // (default wrapping method)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  // set texture filtering parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                  GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  // load image, create texture and generate mip:while () {
  int width, height, nrChannels;
  // The FileSystem::getPath(...) is part of the GitHub repository so we can
  // find files on any IDE/platform; replace it with your own image path.
  unsigned char *data = stbi_load("/Users/macbookpro/Documents/personal/"
                                  "graphics/ping-pong/ping-pong/crate.jpeg",
                                  &width, &height, &nrChannels, 0);
  if (data) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
                 GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    std::cout << "Failed to load texture" << std::endl;
  }
  stbi_image_free(data);
}
