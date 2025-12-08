import zipfile
import time

def rock_zip(zip_path, dic_path):
    # 打开 ZIP 文件
    zip_file = zipfile.ZipFile(zip_path)

    # 读取密码字典文件
    with open(dic_path, 'r', encoding='utf-8', errors='ignore') as f:
        passwords = f.read().splitlines()  # 正确读取所有行，去掉换行符

    # 尝试每个密码
    for i, password in enumerate(passwords):
        try:
            print(f"尝试第 {i+1} 个密码：{password}")
            zip_file.extractall(pwd=password.encode('utf-8'))  # 使用 UTF-8 编码
            print(f"🎉 成功破解！密码是：{password}")
            return password
        except (RuntimeError, zipfile.BadZipFile, UnicodeEncodeError) as e:
            # RuntimeError: ZIP 文件密码错误
            # BadZipFile: ZIP 文件损坏
            # UnicodeEncodeError: 密码包含不支持的字符
            print(f"❌ 尝试失败：{password}")
            continue
        except Exception as e:
            print(f"⚠️ 出现未知错误：{e}")
            time.sleep(1)  # 遇到异常暂停一下
            continue

    print("💔 所有密码尝试失败")
    return None

# 示例调用
rock_zip(
    zip_path='D:\\CODE\\ZRH_CODE\\pycode\\homework.zip',
    dic_path='D:\\CODE\\ZRH_CODE\\pycode\\rockyou.txt'
)
