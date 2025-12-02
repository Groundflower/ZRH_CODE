import keyboard
import pyautogui
import time
import sys


def zrhwrite(text, interval=0.05):
    pyautogui.typewrite(text, interval=interval)


def on_hotkey():
    print("F12热键被触发！")
    time.sleep(10)
    zrhwrite(text, interval=0.05)
if __name__ == "__main__":

    keyboard.add_hotkey('f12',on_hotkey)
    print("="*30)
    print("程序已启动！操作说明：")
    print(f"→ 按 {'F11'.upper()}：安全退出程序")
    print("="*30)
    print("please input(ctrl+z-->enter to stop)")
    text = sys.stdin.read()


    keyboard.wait('f11')
