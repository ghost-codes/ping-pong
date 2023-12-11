//
//  windowManager.cpp
//  ping-pong
//
//  Created by Nkatie3 on 09/12/2023.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "windowManager.hpp"
#include <iostream>


void frame_buffer_size_callback(GLFWwindow* window, int width,int height);

void  GLFWManager::initializeGLFW(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
};

GLFWwindow* GLFWManager::createWindow(int windowWidth,int windowHeight){
    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Ping Pong", NULL, NULL);
    
    if(window ==NULL){
        std::cout<< "Failed to create window"<<std::endl;
        glfwTerminate();
        return NULL;
    }
    
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window,frame_buffer_size_callback);
    
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout<< "Failed to load GLAD"<<std::endl;
        return NULL;
    }
    
    
    
    return window;
}

void GLFWManager::swapAndPool(GLFWwindow* window){
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void frame_buffer_size_callback(GLFWwindow* window,int width, int height){
    glViewport(0,0,width,height);
}
