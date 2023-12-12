//
//  vertexManager.hpp
//  ping-pong
//
//  Created by Nkatie3 on 09/12/2023.
//

#ifndef vertexManager_hpp
#define vertexManager_hpp

class VertexManager {
public:
  float vertices[12] = {
      1.0f,  1.0f,  0.0f, // top right
      1.0f,  -1.0f, 0.0f, // bottom right
      -1.0f, -1.0f, 0.0f, // bottom left
      -1.0f, 1.0f,  0.0f  // top left
  };

  unsigned int indices[6] = {
      // note that we start from 0!
      0, 1, 3, // first triangle
      1, 2, 3  // second triangle
  };

  unsigned int VBO, VAO, EBO;
  void createAndBindBuffers();
  void drawTriangle();
  void deleteShaders();
  unsigned int fragmentShader, vertexShader;
  unsigned int shaderProgram;
  const char *vertexShaderSource = "#version 410 core\n"
                                   "layout (location = 0) in vec3 aPos;\n"
                                   "out vec4 vertexColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   gl_Position = vec4(aPos, 1.0);\n"
                                   "   vertexColor=vec4(0.5,0.0,0.0,1.0);\n"
                                   "}\0";
  const char *fragmentShaderSource = "#version 410 core\n"
                                     "out vec4 FragColor;\n"
                                     "in vec4 vertexColor;\n"
                                     "uniform vec4 ourColor;\n"
                                     "void main()\n"
                                     "{\n"
                                     "   FragColor = ourColor;\n"
                                     "}\n\0";
};

#endif /* vertexManager_hpp */
