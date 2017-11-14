import os
from sys import argv

script, name = argv

print("Compiling...")

os.system("g++ -O2 -Wl,--stack,268435456 -std=c++14 -DTr___ " + name + ".cpp -o " + name)

print("Running...")

os.system(name)

print("Complete")

