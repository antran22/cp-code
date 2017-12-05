import os
import sys
from random import randint
from shutil import copyfile, copy
from sys import argv
try:
    script, prob_name = argv
except:
    print ('running error')
    print ('try again with: python gentest.py [gen input file] [prob name]')
    exit()

def gen_input(iTest):
    with open(prob_name + '.inp', 'w') as f:
        if iTest < 20:
            N = randint(1, 10)
            D = randint(0, 9)
        elif iTest < 40:
            N = randint(10, 1000000)
            D = randint(0, 9)
        elif iTest < 60:
            N = randint(1000000, 1000000000000)
            D = randint(0, 9)
        else:
            N = randint(100000000000, 1000000000000000)
            D = randint(0, 9)

        f.write(str(N) + ' ' + str(D) + '\n')
        f.close()


def gen_output(iTest):
    copy(workspace + '\\' + prob_name + '\\' + prob_name + '.exe', os.getcwd() + '\\' + prob_name + '.exe')
    os.system(prob_name)
    os.remove(prob_name + '.exe')
    return


if __name__ == '__main__':
    #workspace
    workspace = 'E:\workspace C++'

    os.chdir(workspace)
    os.chdir(prob_name)

    #firtly compile program
    os.system('py cl.py ' + prob_name)

    if not os.path.exists(prob_name):
        os.mkdir(prob_name)

    prob_workspace = workspace + '\\' + prob_name + '\\' + prob_name

    os.chdir(prob_name)

    nTest = 100
    for iTest in range(nTest):
        test_name = str(iTest)

        while len(test_name) < 2:
            test_name = '0' + test_name
        print("Processing testcase: " + test_name)

        test_name = prob_name + test_name

        os.chdir(prob_workspace)

        if not os.path.exists(test_name):
            os.mkdir(test_name)

        os.chdir(test_name)

        gen_input(iTest)
        gen_output(iTest)
        print("Done!")
