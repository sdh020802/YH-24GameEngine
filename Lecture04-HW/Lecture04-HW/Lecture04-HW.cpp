// Lecture04-HW.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <GLFW/glfw3.h>
#pragma comment(lib, "Opengl32.lib")
//과제물 프로젝트명: Lecture04_HW
//idle : 화면색 검정색으로 clear
//마우스 오른쪽 KeyDown하면 : 빨간색
//마우스 오른쪽 KeyUp하면 : 원상복구
//마우스 왼쪽 KeyDown하면 : 녹색
//마우스 왼쪽 KeyUp하면 : 원상복구
//마우스 오른쪽 KeyDown하고 드래그 중이면 : 파랑색
//마우스 왼쪽 KeyDown하고 드래그 중이면 : 마젠타색

void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void buttonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_RIGHT)
    {
        if (action == GLFW_PRESS)
        {
            glClearColor(1, 0, 0, 0);
        }
        else if (action == GLFW_RELEASE)
        {
            glClearColor(0, 0, 0, 0);
        }
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT)
    {
        if (action == GLFW_PRESS)
        {
            glClearColor(0, 1, 0, 0);
        }
        else if (action == GLFW_RELEASE)
        {
            glClearColor(0, 0, 0, 0);
        }
    }
}

void cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
    int LB = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
    int RB = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);

    if (LB == GLFW_PRESS)
    {
        glClearColor(1, 0, 1, 0);
    }
    else if (RB == GLFW_PRESS)
    {
        glClearColor(0, 0, 1, 0);
    }
}

int main(void)
{
    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, buttonCallback);
    glfwSetCursorPosCallback(window, cursorPosCallback);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}