import keyboard
import pyautogui
import time
import tkinter as tk
from tkinter import ttk


def zrhwrite(text, interval=0.05):
    pyautogui.typewrite(text, interval=interval)

def on_reload_input():
    global text
    print("🔄 F10热键被触发！请重新输入内容...")
    new_text = get_multiline_input()
    if new_text is not None:
        text = new_text
        print("✅ 内容已更新为：\n", text)
    else:
        print("⚠️ 取消更新内容。")
def on_hotkey():
    print("F12热键被触发！")
    time.sleep(10)
    zrhwrite(text, interval=0.01)

def get_multiline_input():
    result = {"text": None}

    def on_submit():
        result["text"] = text_box.get("1.0", tk.END).strip()
        root.destroy()

    def on_cancel():
        result["text"] = None
        root.destroy()

    # 创建主窗口
    root = tk.Tk()
    root.title("多行输入框")
    root.geometry("500x300")
    root.protocol("WM_DELETE_WINDOW", on_cancel)  # 点击关闭按钮时触发取消

    # 标签
    label = ttk.Label(root, text="请输入多行文本（支持换行）：")
    label.pack(pady=10)

    # 多行文本框
    text_box = tk.Text(root, wrap="word", font=("微软雅黑", 12), height=10)
    text_box.pack(padx=10, pady=5, expand=True, fill="both")

    # 按钮框架
    button_frame = ttk.Frame(root)
    button_frame.pack(pady=10)

    # 提交按钮
    submit_button = ttk.Button(button_frame, text="确认", command=on_submit)
    submit_button.pack(side="left", padx=5)

    # 取消按钮
    cancel_button = ttk.Button(button_frame, text="取消", command=on_cancel)
    cancel_button.pack(side="left", padx=5)

    # 禁用主窗口外的其他操作
    root.grab_set()

    # 运行窗口主循环
    root.mainloop()

    return result["text"]

if __name__ == "__main__":
    text = get_multiline_input()
    keyboard.add_hotkey('f12', on_hotkey)
    keyboard.add_hotkey('f10',on_reload_input)
    print("=" * 30)
    print("程序已启动！操作说明：")
    print(f"按{'F10'.upper()}:重新输入")
    print(f"→ 按 {'F11'.upper()}：安全退出程序")
    print("=" * 30)
    root = tk.Tk()
    root.withdraw()

    print("Input finished")

    if text is None:
        print("❌ 用户取消输入，程序退出。")
    else:
        print("✅ 你输入的内容如下：\n")
        print(text)
    keyboard.wait('f11')
