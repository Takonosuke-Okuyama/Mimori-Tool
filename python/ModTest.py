# -*- coding: utf-8 -*-
"""
Unit Test code for C language code.

Test of function add

Last update: 2018/11/18
"""

import MimoriTool

print("何森?")
num = input()
input_m = MimoriTool.py_makeMimoriSuzuko(int(num))
dec = input_m['mimoriSuzuko'].decode('utf-8')
print(dec)
