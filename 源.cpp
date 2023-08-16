#include <iostream>
#include <Windows.h>

void sendPinyin(const std::string& text)
{
    size_t length = text.length();
    bool firstChar = true; // �����ж��Ƿ��ǵ�һ���ַ�
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
    std::cout << "�����뷢�ʹ�����";
    std::cin >> numSends;

    std::string pinyin;
    std::cout << "������ƴ����";
    std::cin >> pinyin;

    int sleepTime;
    std::cout << "�����뷢��ʱ�䣨1000=1�룩��";
    std::cin >> sleepTime;

    for (int i = 0; i < numSends; ++i) {
        sendPinyin(pinyin);
        keybd_event(VK_SPACE, 0, 0, 0);
        keybd_event(VK_RETURN, 0, 0, 0);
        keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
        Sleep(sleepTime);
    }

    std::cout << "������ϣ�����������رմ���..." << std::endl;
    system("pause");  // �ȴ��û�����������رմ���

    return 0;
}
