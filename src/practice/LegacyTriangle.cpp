#include <GLFW/glfw3.h>

int main() {
   GLFWwindow* window;

   if(!glfwInit())
      return -1;

   window = glfwCreateWindow(750, 650, "Legacy Triangle", NULL, NULL);

   if(!window) {
      glfwTerminate();
      return -1;
   }

   glfwMakeContextCurrent(window);
   
   while(!glfwWindowShouldClose(window)) {
      glClear(GL_COLOR_BUFFER_BIT);

      glBegin(GL_TRIANGLES);

      glVertex2f(-0.75f, -0.75f);
      glVertex2f( 0.00f,  0.65f);
      glVertex2f( 0.75f, -0.75f);

      glEnd();

      glfwSwapBuffers(window);
      glfwPollEvents();
   }

   glfwTerminate();
}