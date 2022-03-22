from ctypes import CDLL
import os

absdirpath = os.path.dirname(os.path.realpath(__file__)) + "/CmainLib.so"
MAIN_LIB_C = CDLL(absdirpath)
