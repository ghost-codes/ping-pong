
//  main.cpp
//  ping-pong
//
//  Created by Nkatie3 on 08/12/2023.

#include <OpenGL/OpenGL.h>
#include <cmath>
#include <glad/glad.h>
// Include Glad before GLFW
#include <GLFW/glfw3.h>
#include <iostream>

// local includes
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
                   "ping-pong/shader.fs");

  float green = 0.3l;
  float red = 0.1;
  float blue = 0.4;

  triangle.createAndBindBuffers();

  while (!glfwWindowShouldClose(window)) {
    // input
    process_input(window);

    // rendering commands'
    float timeValue = glfwGetTime();
    float greenValue = (sin(timeValue) / 2.0f) + 0.5f;

    glClearColor(red, green, blue, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    float vertexLocation = glGetUniformLocation(ourShader.ID, "ourColor");
    ourShader.use();
    triangle.drawTriangle();
    glUniform4f(vertexLocation, 0.0F, greenValue, 0.0f, 1.0f);

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
