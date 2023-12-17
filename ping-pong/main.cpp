
//  main.cpp
//  ping-pong
//
//  Created by Nkatie3 on 08/12/2023.

#include <OpenGL/OpenGL.h>
#include <cmath>
#include <glad/glad.h>
// Include Glad before GLFW
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <iterator>

// local includes
#include "glm/ext/matrix_transform.hpp"
#include "glm/fwd.hpp"
#include "shader.hpp"
#include "vertexManager.hpp"
#include "windowManager.hpp"

void process_input(GLFWwindow *window);

int main(int argc, const char *argv[]) {

  GLFWManager manager = GLFWManager();
  VertexManager triangle = VertexManager();

  manager.initializeGLFW();

  GLFWwindow *window = manager.createWindow(800, 600);
  if (window == NULL) {
    std::cout << "Failed to initialize window" << std::endl;
    return -1;
  }

  Shader ourShader("/Users/macbookpro/Documents/personal/graphics/ping-pong/"
                   "ping-pong/shader.vs",
                   "/Users/macbookpro/Documents/personal/graphics/ping-pong/"
                   "ping-pong/shader2.fs");

  float green = 186.0 / 255.0;
  float red = 184.0 / 255.0;
  float blue = 108.0 / 255.0;
  glEnable(GL_DEPTH_TEST);

  triangle.createAndBindBuffers();
  triangle.initTextures();

  while (!glfwWindowShouldClose(window)) {
    // inputt
    process_input(window);
    double xpos, ypos;
    // getting cursor position
    glfwGetCursorPos(window, &xpos, &ypos);

    // rendering commands'
    float timeValue = glfwGetTime();
    float greenValue = (sin(timeValue) / 2.0f) + 0.5f;

    glClearColor(red, green, blue, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float vertexLocation = glGetUniformLocation(ourShader.ID, "ourColor");
    float iTimeLocation = glGetUniformLocation(ourShader.ID, "iTime");
    float iResolution = glGetUniformLocation(ourShader.ID, "iResolution");
    float iMouse = glGetUniformLocation(ourShader.ID, "iMouse");

    glm::mat4 trans = glm::mat4(1.0f);
    trans =
        glm::rotate(trans, (float)atan(xpos / ypos), glm::vec3(0.0, 1.0, 0.0));
    trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
    glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);

    glm::mat4 model = glm::mat4(1.0f);
    model =
        glm::rotate(model, glm::radians(-65.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    glBindTexture(GL_TEXTURE_2D, triangle.texture);
    model = glm::rotate(model, (float)atan(xpos / ypos) * glm::radians(50.0f),
                        glm::vec3(0.5f, 1.0f, 0.0f));

    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    glm::mat4 projection;
    projection =
        glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

    ourShader.use();

    // unsigned int transformLoccc =
    // glGetUniformLocation(ourShader.ID, "transform");
    // glUniformMatrix4fv(transformLoccc, 1, GL_FALSE, glm::value_ptr(trans));

    unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "model");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(model));

    unsigned int viewLoc = glGetUniformLocation(ourShader.ID, "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

    unsigned int projectionLoc =
        glGetUniformLocation(ourShader.ID, "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

    triangle.drawTriangle(ourShader);
    glUniform4f(vertexLocation, 0.0F, greenValue, 0.0f, 1.0f);
    glUniform1f(iTimeLocation, timeValue);
    glUniform2f(iResolution, 600.0, 800.0);
    glUniform4f(iMouse, 0.0, 0.0, 0.0, 0.0);

    // check and call events and swap the buffers
    manager.swapAndPool(window);
  }
  glfwTerminate();

  return 0;
}

void process_input(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}
