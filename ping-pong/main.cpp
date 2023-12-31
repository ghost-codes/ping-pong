
//  main.cpp
//  ping-pong
//
//  Created by Nkatie3 on 08/12/2023.

#include <OpenGL/OpenGL.h>
#include <cmath>
#include <functional>
#include <glad/glad.h>
// Include Glad before GLFW
#include "stb_image.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <ios>
#include <iostream>
#include <vector>

#include "model.hpp"

// local includes
#include "camera.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/quaternion_geometric.hpp"
#include "glm/fwd.hpp"
#include "glm/geometric.hpp"
#include "glm/trigonometric.hpp"
#include "shader.hpp"
#include "vertexManager.hpp"
#include "windowManager.hpp"

float deltaTime = 0.0f;
float lastFrame = 0.0f;

void process_input(GLFWwindow *window, Camera *camera);
void mouse_callback(GLFWwindow *window, double xposIn, double yposIn);

Camera camera = Camera(0.0f, 20.0f, 0.0f, 0.0f, 1.0f, 0.0f, -90.0f, 0.0f);
float lastX = 800.0 / 2.0f;
float lastY = 600.0 / 2.0f;
bool firstMouse = true;

int main(int argc, const char *argv[]) {

  GLFWManager manager = GLFWManager();
  VertexManager object = VertexManager();
  VertexManager lightObject = VertexManager();

  manager.initializeGLFW();

  GLFWwindow *window = manager.createWindow(800, 600);
  if (window == NULL) {
    std::cout << "Failed to initialize window" << std::endl;
    return -1;
  }

  Shader ourShader("/Users/macbookpro/Documents/personal/graphics/ping-pong/"
                   "ping-pong/shader.vert.glsl",
                   "/Users/macbookpro/Documents/personal/graphics/ping-pong/"
                   "ping-pong/shader2.frag.glsl");
  Shader lightShader("/Users/macbookpro/Documents/personal/graphics/ping-pong/"
                     "ping-pong/lightShader.vert.glsl",
                     "/Users/macbookpro/Documents/personal/graphics/ping-pong/"
                     "ping-pong/lightShader.frag.glsl");

  float green = 186.0 / 255.0;
  float red = 184.0 / 255.0;
  float blue = 108.0 / 255.0;
  object.createAndBindBuffers();
  lightObject.createAndBindBuffers();
  std::vector<char *> textures;
  // stbi_set_flip_vertically_on_load(true);

  Model ourModel(
      "/Users/macbookpro/Downloads/baker-and-the-bridge/source/untitled.obj");

  glfwSetCursorPosCallback(window, mouse_callback);
  const int diffuseMap = object.initTextures(
      "/Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/"
      "crate.jpeg");
  const int specularMap = object.initTextures(
      "/Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/"
      "crate_specular.jpg");
  glEnable(GL_DEPTH_TEST);
  // glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);
  //

  while (!glfwWindowShouldClose(window)) {
    // inputt
    float currentTime = glfwGetTime();
    deltaTime = currentTime - lastFrame;
    lastFrame = currentTime;
    process_input(window, &camera);
    double xpos, ypos;
    // getting cursor position
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // rendering commands'
    float timeValue = glfwGetTime();
    float greenValue = (sin(timeValue) / 2.0f) + 0.5f;

    // glClearColor(red, green, blue, 1.0f);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float vertexLocation = glGetUniformLocation(ourShader.ID, "ourColor");
    float iTimeLocation = glGetUniformLocation(ourShader.ID, "iTime");
    float iResolution = glGetUniformLocation(ourShader.ID, "iResolution");
    float iMouse = glGetUniformLocation(ourShader.ID, "iMouse");

    // glm::mat4 trans = glm::mat4(1.0f);
    // trans =
    //     glm::rotate(trans, (float)atan(xpos / ypos), glm::vec3(0.0, 1.0,
    //     0.0));
    // trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
    // glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
    //
    // glm::mat4 model = glm::mat4(1.0f);
    // model =
    //     glm::rotate(model, glm::radians(-65.0f), glm::vec3(1.0f, 0.0f,
    //     0.0f));
    // glBindTexture(GL_TEXTURE_2D, object.texture);
    // model = glm::rotate(model, (float)atan(xpos / ypos) *
    // glm::radians(50.0f),
    //                     glm::vec3(0.5f, 1.0f, 0.0f));
    //
    const float radius = 10.0f;
    glm::mat4 view;
    view =
        glm::lookAt(camera.Position, camera.Position + camera.Front, camera.Up);
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(camera.Zoom), 800.0f / 600.0f,
                                  0.1f, 100.0f);

    // glm::vec3 lightPos = glm::vec3(1.5f, 2.0f, -6.0f);
    float lightX = 10.0f * sin(glfwGetTime());
    float lightY = -0.3f;
    float lightZ = 15.0f * cos(glfwGetTime());
    glm::vec3 lightPos = glm::vec3(lightX, lightY, lightZ);
    // render object

    ourShader.use();
    glm::mat4 model = glm::mat4(1.0f);
    // model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
    // ourShader.setMat4("model", model);
    ourShader.setVec3("viewPos", camera.Position);

    // bind diffuse map
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, diffuseMap);
    // bind specular map
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, specularMap);

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
    unsigned int lightLoc = glGetUniformLocation(ourShader.ID, "lightColor");
    glUniform3f(lightLoc, 1.0f, 1.0f, 1.0f);

    ourShader.setVec3("lightPos", camera.Position);
    ourShader.setVec3("material.ambient", glm::vec3(0.10, 0.10, 0.10));
    ourShader.setInt("material.diffuse", 0);
    // ourShader.setVec("material.diffuse", glm::vec3(1.0, 1.0, 1.0));
    ourShader.setInt("material.specular", 1);
    ourShader.setFloat("material.shininess", 32.0);
    ourShader.setVec3("light.ambient", glm::vec3(0.10, 0.10, 0.10));
    ourShader.setVec3("light.diffuse", glm::vec3(1.0, 1.0, 1.0));
    ourShader.setVec3("light.specular", glm::vec3(1.0, 1.0, 1.0));
    ourShader.setVec3("light.direction", glm::vec3(-0.2f, -1.0f, -0.3f));
    // ourShader.setVec3("light.direction", camera.Front);
    ourShader.setFloat("light.cutoff", glm::cos(glm::radians(12.5f)));
    ourShader.setFloat("light.outerCutOff", glm::cos(glm::radians(17.5f)));
    // ourShader.setVec3("light.position", lightPos);
    ourShader.setVec3("light.position", camera.Position);
    ourShader.setFloat("light.constant", 1.0f);
    ourShader.setFloat("light.linear", 0.09f);
    ourShader.setFloat("light.quadratic", 0.032f);

    // glm::vec3 cubePositions[] = {
    //     glm::vec3(0.0f, 0.0f, 0.0f),    glm::vec3(2.0f, 5.0f, -15.0f),
    //     glm::vec3(-1.5f, -2.2f, -2.5f), glm::vec3(-3.8f, -2.0f, -12.3f),
    //     glm::vec3(2.4f, -0.4f, -3.5f),  glm::vec3(-1.7f, 3.0f, -7.5f),
    //     glm::vec3(1.3f, -2.0f, -2.5f),  glm::vec3(1.5f, 2.0f, -2.5f),
    //     glm::vec3(1.5f, 0.2f, -1.5f),   glm::vec3(-1.3f, 1.0f, -1.5f)};
    // for (unsigned int i = 0; i < 10; i++) {
    //   //
    //   glm::mat4 model = glm::mat4(1.0f);
    //   model = glm::translate(model, cubePositions[i]);
    //   float angle = 20.0f * i;
    //   model =
    //       glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f,
    //       0.5f));
    //   ourShader.setMat4("model", model);
    //
    // object.drawTriangle(ourShader);
    //   ourModel.Draw(ourShader);
    //   // glDrawArrays(GL_TRIANGLES, 0, 36);
    // }
    ourModel.Draw(ourShader);
    lightShader.use();
    model = glm::mat4(1.0f);
    model = glm::translate(model, lightPos);
    // lightShader.setMat4("model", model);

    transformLoc = glGetUniformLocation(lightShader.ID, "model");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(model));

    viewLoc = glGetUniformLocation(lightShader.ID, "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

    projectionLoc = glGetUniformLocation(lightShader.ID, "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

    // lightObject.drawTriangle(ourShader);
    // check and call events and swap the buffers
    manager.swapAndPool(window);
  }
  glfwTerminate();

  return 0;
}

void mouse_callback(GLFWwindow *window, double xposIn, double yposIn) {
  float xpos = static_cast<float>(xposIn);
  float ypos = static_cast<float>(yposIn);

  if (firstMouse) {
    lastX = xpos;
    lastY = ypos;
    firstMouse = false;
  }

  float xoffset = xpos - lastX;
  float yoffset =
      lastY - ypos; // reversed since y-coordinates go from bottom to top

  lastX = xpos;
  lastY = ypos;
  camera.ProcessMouseMovement(xoffset, yoffset);
}

void process_input(GLFWwindow *window, Camera *camera) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
  float acc = 1.0f;
  if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
    acc = 5.0f;
  }

  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS |
      glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    camera->ProcessKeyboard(FORWARD, deltaTime, acc);
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS |
      glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    camera->ProcessKeyboard(BACKWARD, deltaTime, acc);

  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS |
      glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    camera->ProcessKeyboard(LEFT, deltaTime, acc);

  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS |
      glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    camera->ProcessKeyboard(RIGHT, deltaTime, acc);

  if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
    camera->Position = glm::vec3(0.0f, 1.0f, 5.0f);
}
