#include <iostream>

enum ForeColour {
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
};

void drawBlock(ForeColour colourCode) {
    std::cout << "\x1b[" << colourCode << "m";
    std::cout << "■";
    std::cout << "\x1b[" << ForeColour::Default << "m";
}

int main() {
    std::cout << "화면에 그림을 그리는 프로그램입니다." << std::endl;
    std::cout << "학번: 202127007" << std::endl;
    std::cout << "이름: 송다훈" << std::endl;

    int objectCode;
    do {
        std::cout << "화면에 그릴 물체코드를 입력하세요 (0을 입력하면 종료): ";
        std::cin >> objectCode;

        switch (objectCode) {
        case 1:
            drawBlock(ForeColour::White);
            break;
        case 2:
            drawBlock(ForeColour::Red);
            break;
        case 4:
            drawBlock(ForeColour::Green);
            break;
        case 8:
            drawBlock(ForeColour::Yellow);
            break;
        case 16:
            drawBlock(ForeColour::Cyan);
            break;
        case 32:
            drawBlock(ForeColour::Magenta);
            break;
        case 64:
            break;
        default:
            std::cout << "잘못된 입력입니다. 다시 입력하세요." << std::endl;
            break;
        }
        std::cout << std::endl;
    } while (objectCode != 64);

    return 0;
}