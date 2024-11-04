import numpy as np
import random as rand

success = 0
error = 0

counts = np.zeros((5,7))

def create_environment(step):
    numbers = np.zeros((5, 7))
    numbers = np.uint16(numbers)
    for p in range(10):
        x = rand.randint(0,4)
        y = rand.randint(0,6)
        while numbers[x][y]==1.0:
            x = rand.randint(0,4)
            y = rand.randint(0,6)
        numbers[x][y] = 1
        counts[x][y] += 1
    print('step:',step+1)
    print(numbers)
    return counts

def probability(value):
    for x in range(5):
        for y in range(7):
            value[x][y] = value[x][y] / 35
            value[x][y] = round(value[x][y],2)
    return value

def real_environment():
    numbers = np.zeros((5, 7))
    numbers = np.uint16(numbers)
    for p in range(10):
        x = rand.randint(0,4)
        y = rand.randint(0,6)
        while numbers[x][y]==1:
            x = rand.randint(0,4)
            y = rand.randint(0,6)
        numbers[x][y] = 1
    return numbers

def check_environment(new_env,tempi,tempj):
    global success, error
    if new_env[tempi][tempj]==0:
        error += 1
    else:
        success += 1

if __name__=="__main__":

    for x in range(50):
        value = create_environment(x)

    prob = probability(value)
    print('probability:')
    print(prob)

    new_env = real_environment()
    print(new_env)
    max_value = prob[0][0]
    index1 = 0
    index2 = 0

    for cnt in range(10):
        for i in range(5):
            for j in range(7):
                if prob[i][j] > max_value:
                    max_value = prob[i][j]
                    index1 = i
                    index2 = j

        check_environment(new_env,index1,index2)
        max_value = 0
        prob[index1][index2] = 0
    print('Total success:',success)
    print('Total error:',error)