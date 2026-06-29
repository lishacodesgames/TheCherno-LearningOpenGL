#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <cstdio>

int main() {
   GLFWwindow* window;

   if(!glfwInit())
      return -1;

   window = glfwCreateWindow(750, 650, "Modern Triangle", NULL, NULL);

   if(!window) {
      glfwTerminate();
      return -1;
   }

   glfwMakeContextCurrent(window);

   // MUST be after the context is created
   if (!gladLoadGL(glfwGetProcAddress))
      return -1;

   printf("Using OpenGL version %s\n", glGetString(GL_VERSION));

   // Making the triangle
   GLuint bufferID; // GLuint is just an alias for unsigned int
   glGenBuffers(1, &bufferID); // generate 1 buffer, write its id into bufferID
   // select this buffer to be worked in in following functions
   glBindBuffer(GL_ARRAY_BUFFER, bufferID); // ARRAY BUFFER is basically a vertex buffer 

   // buffers don't need to be updated with data straight away, but they do need size allocated
   // But we js wanna draw a simple triangle, so let's init the data
   // we've selected our buffer using Bind already

   constexpr int vCount = 3; // How many actual physical points
   constexpr int vSize = 2; // How many floats per vertex 
   constexpr float vertices[vCount * vSize] = {
      -0.5f, -0.5f,
      +0.0f, +0.5f,
      +0.5f, -0.5f
   };

   // * sizeof(float) bcz glBufferData() takes size in bytes

   /**
    * USAGE:
    * - STREAM = modified once, used a few times 
    * - STATIC = modified once, used many times (our case, stored outside while loop, drawn every frame) 
    * - DYNAMIC = modified many tiumes, used many times
    * 
    * NATURE OF ACCESS (definition of "used" in USAGE): DRAW, READ, COPY
    */
   glBufferData(GL_ARRAY_BUFFER, vCount * vSize * sizeof(float), vertices, GL_STATIC_DRAW);

   while(!glfwWindowShouldClose(window)) {
      glClear(GL_COLOR_BUFFER_BIT);

      // draws the currently bound vertex buffer, only useful in absence of index buffers
      //  (primitive type, first v index, how many vertices)
      glDrawArrays(GL_TRIANGLES, 0, vCount);

      glfwSwapBuffers(window);
      glfwPollEvents();
   }

   glfwTerminate();
}