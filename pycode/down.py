import os
import time
import platform

def set_shutdown_timer():
    print("=== 定时关机工具 ===")
    
    # 获取用户输入的小时和分钟（输入验证）
    while True:
        try:
            hours = int(input("请输入小时数（0-23）："))
            minutes = int(input("请输入分钟数（0-59）："))
            if 0 <= hours < 24 and 0 <= minutes < 60:
                break
            else:
                print("输入不合法！小时需在0-23之间，分钟需在0-59之间。")
        except ValueError:
            print("输入错误！请输入整数。")
    
    # 计算总秒数和预计关机时间
    total_seconds = hours * 3600 + minutes * 60
    shutdown_time = time.strftime("%H:%M:%S", time.localtime(time.time() + total_seconds))
    print(f"\n已设置定时关机：{hours}小时{minutes}分钟后（预计关机时间：{shutdown_time}）")
    print("等待期间可按 Ctrl+C 取消关机")
    
    try:
        # 根据系统执行关机命令（直接提交任务，避免sleep阻塞）
        if platform.system() == "Windows":
            # Windows：直接使用 shutdown /s /t 秒数（无需sleep）
            os.system(f"shutdown /s /t {total_seconds}")
            print("定时任务已提交，系统将在指定时间关机。")
        elif platform.system() == "Linux":
            # Linux：通过 at 命令提交定时任务（需用户手动输入密码）
            os.system(f"echo 'shutdown -h now' | at now + {hours} hours + {minutes} minutes")
            print("请在弹出的提示中输入管理员密码以确认定时任务。")
        elif platform.system() == "Darwin":  # macOS
            # macOS：使用 sudo shutdown 直接设置（需用户手动输入密码）
            os.system(f"sudo shutdown -h {hours * 60 + minutes}")
            print("请输入管理员密码以确认定时任务。")
        
        # 等待期间保持程序运行（用户可按Ctrl+C取消）
        time.sleep(total_seconds)
        
    except KeyboardInterrupt:
        print("\n已取消定时关机")
        if platform.system() == "Windows":
            os.system("shutdown /a")  # Windows取消命令
        elif platform.system() == "Linux":
            os.system("atq | awk '{print $1}' | xargs atrm")  # Linux删除所有at任务
        elif platform.system() == "Darwin":
            os.system("sudo shutdown -c")  # macOS取消命令

if __name__ == "__main__":
    set_shutdown_timer()
