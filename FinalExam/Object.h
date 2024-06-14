#pragma once

#include <GLFW/glfw3.h>

class Object {
public:
    virtual void OnCollisionEnter(Object& other) {
        // 기본적으로 아무 작업도 하지 않음
    }

    virtual void Draw() {
        // 기본적으로 아무 작업도 하지 않음
    }
};

class Player : public Object {
private:
    float size;   // 플레이어의 한 변 길이 (단위: cm)
    float thickness;  // 테두리 두께 (단위: cm)
    float posX, posY; // 플레이어의 위치 (화면 좌표)

public:
    Player(float size_cm, float thickness_cm, float x, float y)
        : size(size_cm), thickness(thickness_cm), posX(x), posY(y)
    {
    }

    void Draw() override {
        // 플레이어 사각형 그리기
        glColor3f(1.0f, 0.0f, 0.0f); // 빨간색 설정
        glBegin(GL_QUADS);
        glVertex2f(posX - size / 2.0f, posY - size / 2.0f);
        glVertex2f(posX + size / 2.0f, posY - size / 2.0f);
        glVertex2f(posX + size / 2.0f, posY + size / 2.0f);
        glVertex2f(posX - size / 2.0f, posY + size / 2.0f);
        glEnd();

        // 테두리 그리기
        glColor3f(0.0f, 0.0f, 0.0f); // 검은색 테두리
        glLineWidth(thickness);
        glBegin(GL_LINE_LOOP);
        glVertex2f(posX - size / 2.0f, posY - size / 2.0f);
        glVertex2f(posX + size / 2.0f, posY - size / 2.0f);
        glVertex2f(posX + size / 2.0f, posY + size / 2.0f);
        glVertex2f(posX - size / 2.0f, posY + size / 2.0f);
        glEnd();
    }

    void OnCollisionEnter(Object& other) override {
        // 충돌 처리 로직
    }
};

class EnemyBlock : public Object {
private:
    float lowObstacleWidth;
    float lowObstacleHeight;
    float highObstacleWidth;
    float highObstacleHeight;

public:
    EnemyBlock()
        : lowObstacleWidth(50.0f), lowObstacleHeight(100.0f), highObstacleWidth(50.0f), highObstacleHeight(300.0f) {}

    void Draw() override {
    }
};

class Floor : public Object {
public:
    void Draw() override {
      
    }

    void OnCollisionEnter(Object& other) override {
        // 충돌 처리 로직
    }
};

class Star : public Object {
public:
    void OnCollisionEnter(Object& other) override {
        // 충돌 처리 로직
    }
};

int PhysicsAABB(Object A, Object B) {
    // 물리 AABB 처리
    return 0;
}
