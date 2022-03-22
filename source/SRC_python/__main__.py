from ctypes import CDLL

cmainlib = CDLL('libMainfile.so')

print(cmainlib)
