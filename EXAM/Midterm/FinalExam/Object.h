#pragma once

#include <GLFW/glfw3.h>

class Object {
public:
    virtual void OnCollisionEnter(Object& other) {
        // �⺻������ �ƹ� �۾��� ���� ����
    }

    virtual void Draw() {
        // �⺻������ �ƹ� �۾��� ���� ����
    }
};

class Player : public Object {
private:
    float size;   // �÷��̾��� �� �� ���� (����: cm)
    float thickness;  // �׵θ� �β� (����: cm)
    float posX, posY; // �÷��̾��� ��ġ (ȭ�� ��ǥ)

public:
    Player(float size_cm, float thickness_cm, float x, float y)
        : size(size_cm), thickness(thickness_cm), posX(x), posY(y)
    {
    }

    void Draw() override {
        // �÷��̾� �簢�� �׸���
        glColor3f(1.0f, 0.0f, 0.0f); // ������ ����
        glBegin(GL_QUADS);
        glVertex2f(posX - size / 2.0f, posY - size / 2.0f);
        glVertex2f(posX + size / 2.0f, posY - size / 2.0f);
        glVertex2f(posX + size / 2.0f, posY + size / 2.0f);
        glVertex2f(posX - size / 2.0f, posY + size / 2.0f);
        glEnd();

        // �׵θ� �׸���
        glColor3f(0.0f, 0.0f, 0.0f); // ������ �׵θ�
        glLineWidth(thickness);
        glBegin(GL_LINE_LOOP);
        glVertex2f(posX - size / 2.0f, posY - size / 2.0f);
        glVertex2f(posX + size / 2.0f, posY - size / 2.0f);
        glVertex2f(posX + size / 2.0f, posY + size / 2.0f);
        glVertex2f(posX - size / 2.0f, posY + size / 2.0f);
        glEnd();
    }

    void OnCollisionEnter(Object& other) override {
        // �浹 ó�� ����
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
        // �浹 ó�� ����
    }
};

class Star : public Object {
public:
    void OnCollisionEnter(Object& other) override {
        // �浹 ó�� ����
    }
};

int PhysicsAABB(Object A, Object B) {
    // ���� AABB ó��
    return 0;
}
