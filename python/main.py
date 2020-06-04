import MimoriTool

print("何森?")
num = input()
input_m = MimoriTool.py_makeMimoriSuzuko(int(num))
dec = input_m['mimoriSuzuko'].decode('utf-8')
print(dec)
