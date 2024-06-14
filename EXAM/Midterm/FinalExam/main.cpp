#pragma comment(lib, "Opengl32.lib")

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

#include <GLFW/glfw3.h>
#include <stdio.h>

#include "Object.h"

void errorCallback(int error, const char* description)
{
    printf("GLFW Error: %s\n", description);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // 키 입력 처리
}

int Physics()
{
    // 물리 처리
    return 0;
}

int Initialize()
{
    // 초기화
    return 0;
}

int Update()
{
    // 업데이트
    return 0;
}

int Render(Player& player)
{
    // 렌더링
    glClear(GL_COLOR_BUFFER_BIT);

    player.Draw();

    return 0;
}

int main(void)
{
    // 메모리 누수 검사 활성화
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // GLFW 초기화
    if (!glfwInit())
        return -1;

    // 윈도우 생성
    GLFWwindow* window = glfwCreateWindow(800, 600, "Google Dino Run Copy Game", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // OpenGL 컨텍스트를 현재 쓰레드의 컨텍스트로 설정
    glfwMakeContextCurrent(window);

    // 콜백 함수 설정
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);

    // 초기화 함수 호출
    Initialize();

    // 배경색 설정 (하늘색, R:0, G:30, B:100)
    glClearColor(0.0f, 30.0f / 255.0f, 100.0f / 255.0f, 1.0f);

    // 플레이어 객체 생성
    Player player(50.0f, 3.0f, 400.0f, 300.0f); // 크기 50cm, 테두리 두께 3cm, 초기 위치 (400, 300)

    // 메인 루프
    while (!glfwWindowShouldClose(window))
    {
        // 이벤트 처리
        glfwPollEvents();
        Physics();
        Update();

        // 화면 지우기 (배경색 적용)
        glClear(GL_COLOR_BUFFER_BIT);

        // 렌더링 함수 호출
        Render(player);

        // 버퍼 스왑
        glfwSwapBuffers(window);
    }

    // GLFW 종료
    glfwTerminate();
    return 0;
}
