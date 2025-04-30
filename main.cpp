#include <windows.h>
#include <Xinput.h>
#include <iostream>
#include <thread>
#include <chrono>

#pragma comment(lib, "xinput.lib")

int main() {
    std::cout << "Xbox コントローラのボタン状態を表示します。" << std::endl;

    while (true) {
        XINPUT_STATE state{};
        DWORD result = XInputGetState(0, &state); // 0: 1P コントローラ

        system("cls"); // コンソールをクリア（Windows用）

        if (result == ERROR_SUCCESS) {
            WORD buttons = state.Gamepad.wButtons;

            std::cout << "[現在押されているボタン]\n";
            if (buttons & XINPUT_GAMEPAD_A) std::cout << "A ";
            if (buttons & XINPUT_GAMEPAD_B) std::cout << "B ";
            if (buttons & XINPUT_GAMEPAD_X) std::cout << "X ";
            if (buttons & XINPUT_GAMEPAD_Y) std::cout << "Y ";
            if (buttons & XINPUT_GAMEPAD_LEFT_SHOULDER)  std::cout << "LB ";
            if (buttons & XINPUT_GAMEPAD_RIGHT_SHOULDER) std::cout << "RB ";
            if (buttons & XINPUT_GAMEPAD_START) std::cout << "Start ";
            if (buttons & XINPUT_GAMEPAD_BACK)  std::cout << "Back ";
            if (buttons & XINPUT_GAMEPAD_DPAD_UP)    std::cout << "↑ ";
            if (buttons & XINPUT_GAMEPAD_DPAD_DOWN)  std::cout << "↓ ";
            if (buttons & XINPUT_GAMEPAD_DPAD_LEFT)  std::cout << "← ";
            if (buttons & XINPUT_GAMEPAD_DPAD_RIGHT) std::cout << "→ ";
            if (buttons & XINPUT_GAMEPAD_LEFT_THUMB)  std::cout << "Lスティック押し ";
            if (buttons & XINPUT_GAMEPAD_RIGHT_THUMB) std::cout << "Rスティック押し ";
        }
        else {
            std::cout << "コントローラが接続されていません。\n";
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 100ms待機
    }

    return 0;
}