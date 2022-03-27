from ctypes import CDLL
import os

absdirpath = os.path.dirname(os.path.realpath(__file__))

Allfiles = os.listdir(absdirpath)


sharedlib_dict = {}

for f in Allfiles:
    if f.endswith('.so'):
        abspathwithfile = absdirpath + "/"+str(f)
        sharedlib_dict[f[0:-3]] = CDLL(abspathwithfile)


class Library:
    def __init__(self):
        for k, v in sharedlib_dict.items():
            setattr(self, k, v)

# now you can get the data of sharedlib_dict throught Library class
# -eg : d = Library()
#       testc = d.mainfile
