#include <iostream>
#include <Windows.h>

void sendPinyin(const std::string& text)
{
    size_t length = text.length();
    bool firstChar = true; // 用于判断是否是第一个字符
    for (size_t i = 0; i < length; ++i) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            BYTE keyCode = c - 'a' + 0x41;
            keybd_event(keyCode, 0, 0, 0);
            keybd_event(keyCode, 0, KEYEVENTF_KEYUP, 0);
            firstChar = false;
        }
        else if (c == ' ') {
            if (!firstChar) {
                keybd_event(VK_SPACE, 0, 0, 0);
                keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
            }
        }
    }
}

int main()
{
    int numSends;
    std::cout << "请输入发送次数：";
    std::cin >> numSends;

    std::string pinyin;
    std::cout << "请输入拼音：";
    std::cin >> pinyin;

    int sleepTime;
    std::cout << "请输入发送时间（1000=1秒）：";
    std::cin >> sleepTime;

    for (int i = 0; i < numSends; ++i) {
        sendPinyin(pinyin);
        keybd_event(VK_SPACE, 0, 0, 0);
        keybd_event(VK_RETURN, 0, 0, 0);
        keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
        Sleep(sleepTime);
    }

    std::cout << "发送完毕，按下任意键关闭窗口..." << std::endl;
    system("pause");  // 等待用户按下任意键关闭窗口

    return 0;
}
