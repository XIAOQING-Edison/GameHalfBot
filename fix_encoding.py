#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
GameHalfBot 项目编码修复工具
功能：批量修复C++源文件中的中文编码问题
作者：AI助手
版本：1.0
"""

import os
import glob
import codecs
import shutil
from pathlib import Path

def detect_encoding(file_path):
    """检测文件编码"""
    encodings = ['utf-8', 'gbk', 'gb2312', 'utf-16', 'latin1']
    
    for encoding in encodings:
        try:
            with codecs.open(file_path, 'r', encoding=encoding) as f:
                content = f.read()
                # 检查是否包含中文字符
                if any('\u4e00' <= char <= '\u9fff' for char in content):
                    return encoding
        except (UnicodeDecodeError, UnicodeError):
            continue
    
    return 'utf-8'  # 默认返回utf-8

def fix_file_encoding(file_path):
    """修复单个文件的编码问题"""
    try:
        # 检测原始编码
        original_encoding = detect_encoding(file_path)
        
        # 读取文件内容
        with codecs.open(file_path, 'r', encoding=original_encoding, errors='ignore') as f:
            content = f.read()
        
        # 检查是否需要修复
        if '' in content or 'ʾ' in content or 'ң' in content:
            print(f"修复文件: {file_path}")
            
            # 创建备份
            backup_path = file_path + '.backup'
            shutil.copy2(file_path, backup_path)
            
            # 尝试不同的编码组合来修复
            encodings_to_try = [
                ('gbk', 'utf-8'),
                ('gb2312', 'utf-8'),
                ('latin1', 'utf-8'),
                ('cp1252', 'utf-8')
            ]
            
            for from_enc, to_enc in encodings_to_try:
                try:
                    with codecs.open(file_path, 'r', encoding=from_enc, errors='ignore') as f:
                        content = f.read()
                    
                    # 写回文件
                    with codecs.open(file_path, 'w', encoding=to_enc) as f:
                        f.write(content)
                    
                    print(f"  使用 {from_enc} -> {to_enc} 编码修复")
                    return True
                    
                except Exception as e:
                    continue
            
            # 如果所有编码都失败，恢复备份
            shutil.copy2(backup_path, file_path)
            print(f"  修复失败，已恢复备份")
            return False
            
        else:
            print(f"跳过文件: {file_path} (无需修复)")
            return True
            
    except Exception as e:
        print(f"处理文件 {file_path} 时出错: {e}")
        return False

def main():
    """主函数"""
    print("GameHalfBot 项目编码修复工具")
    print("=" * 50)
    
    # 查找所有需要修复的文件
    file_patterns = [
        "GameBot/**/*.cpp",
        "GameBot/**/*.h",
        "Proxy/**/*.cpp", 
        "Proxy/**/*.h"
    ]
    
    all_files = []
    for pattern in file_patterns:
        files = glob.glob(pattern, recursive=True)
        all_files.extend(files)
    
    print(f"找到 {len(all_files)} 个C++文件")
    
    # 修复文件
    success_count = 0
    for file_path in all_files:
        if fix_file_encoding(file_path):
            success_count += 1
    
    print(f"\n完成！成功处理 {success_count}/{len(all_files)} 个文件")
    print("注意：已修复的文件会创建 .backup 备份文件")

if __name__ == "__main__":
    main() 