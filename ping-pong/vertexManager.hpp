//
//  vertexManager.hpp
//  ping-pong
//
//  Created by Nkatie3 on 09/12/2023.
//

#ifndef vertexManager_hpp
#define vertexManager_hpp

#include "shader.hpp"
class VertexManager {
public:
  float vertices[288] = {
      -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  0.0f,  0.0f,  -1.0f, 0.5f,  -0.5f,
      -0.5f, 1.0f,  0.0f,  0.0f,  0.0f,  -1.0f, 0.5f,  0.5f,  -0.5f, 1.0f,
      1.0f,  0.0f,  0.0f,  -1.0f, 0.5f,  0.5f,  -0.5f, 1.0f,  1.0f,  0.0f,
      0.0f,  -1.0f, -0.5f, 0.5f,  -0.5f, 0.0f,  1.0f,  0.0f,  0.0f,  -1.0f,
      -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  0.0f,  0.0f,  -1.0f,

      -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  0.0f,  0.0f,  1.0f,  0.5f,  -0.5f,
      0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,  0.5f,  0.5f,  0.5f,  1.0f,
      1.0f,  0.0f,  0.0f,  1.0f,  0.5f,  0.5f,  0.5f,  1.0f,  1.0f,  0.0f,
      0.0f,  1.0f,  -0.5f, 0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
      -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  0.0f,  0.0f,  1.0f,

      -0.5f, 0.5f,  0.5f,  1.0f,  0.0f,  -1.0f, 0.0f,  0.0f,  -0.5f, 0.5f,
      -0.5f, 1.0f,  1.0f,  -1.0f, 0.0f,  0.0f,  -0.5f, -0.5f, -0.5f, 0.0f,
      1.0f,  -1.0f, 0.0f,  0.0f,  -0.5f, -0.5f, -0.5f, 0.0f,  1.0f,  -1.0f,
      0.0f,  0.0f,  -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  -1.0f, 0.0f,  0.0f,
      -0.5f, 0.5f,  0.5f,  1.0f,  0.0f,  -1.0f, 0.0f,  0.0f,

      0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  1.0f,  0.0f,  0.0f,  0.5f,  0.5f,
      -0.5f, 1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  0.5f,  -0.5f, -0.5f, 0.0f,
      1.0f,  1.0f,  0.0f,  0.0f,  0.5f,  -0.5f, -0.5f, 0.0f,  1.0f,  1.0f,
      0.0f,  0.0f,  0.5f,  -0.5f, 0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
      0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  1.0f,  0.0f,  0.0f,

      -0.5f, -0.5f, -0.5f, 0.0f,  1.0f,  0.0f,  -1.0f, 0.0f,  0.5f,  -0.5f,
      -0.5f, 1.0f,  1.0f,  0.0f,  -1.0f, 0.0f,  0.5f,  -0.5f, 0.5f,  1.0f,
      0.0f,  0.0f,  -1.0f, 0.0f,  0.5f,  -0.5f, 0.5f,  1.0f,  0.0f,  0.0f,
      -1.0f, 0.0f,  -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  0.0f,  -1.0f, 0.0f,
      -0.5f, -0.5f, -0.5f, 0.0f,  1.0f,  0.0f,  -1.0f, 0.0f,

      -0.5f, 0.5f,  -0.5f, 0.0f,  1.0f,  0.0f,  1.0f,  0.0f,  0.5f,  0.5f,
      -0.5f, 1.0f,  1.0f,  0.0f,  1.0f,  0.0f,  0.5f,  0.5f,  0.5f,  1.0f,
      0.0f,  0.0f,  1.0f,  0.0f,  0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
      1.0f,  0.0f,  -0.5f, 0.5f,  0.5f,  0.0f,  0.0f,  0.0f,  1.0f,  0.0f,
      -0.5f, 0.5f,  -0.5f, 0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
  };

  float textureCoord[9] = {
      0.0f, 0.0f, // bottom left
      1.0f, 0.0f, // bottom rignt
      0.5f, 0.1f,
  };

  unsigned int texture;
  unsigned int indices[6] = {
      // note that we start from 0!
      0, 1, 3, // first triangle
      1, 2, 3  // second triangle
  };

  unsigned int VBO, VAO, EBO;
  void createAndBindBuffers();
  void drawTriangle(Shader ourShader);
  void deleteShaders();
  int initTextures(char *path);
  unsigned int fragmentShader, vertexShader;
  unsigned int shaderProgram;
};

#endif /* vertexManager_hpp */
