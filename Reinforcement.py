import numpy as np
import random as rand

counts = np.zeros((5,7))

# here is created my environment 
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

# it's determine the probability of environment
def probability(value):
    for x in range(5):
        for y in range(7):
            value[x][y] = value[x][y] / 35
            value[x][y] = round(value[x][y],2)
    return value

# it is created new real environment 
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

# it is used for increasing our predicted environment correctly otherwise decreasing
def check_environment(new_env,tempi,tempj,prob):
    global success, error
    if new_env[tempi][tempj]==1:
        prob[tempi][tempj] += 0.05
    else:
        prob[tempi][tempj] -= 0.05
    
    return prob

if __name__=="__main__":

    # it create environment then count the number of 1 in each index 
    for x in range(50):
        value = create_environment(x)

    probability_array = probability(value)
    print('probability:')
    print(probability_array)

    # it is used for creating real environment 
    new_environment = real_environment()
    print('New environment:',1)
    print(new_environment)

    # each iteration it will determine the maximum probability value
    for cnt in range(10):
        max_value = probability_array[0][0]
        index1 = 0
        index2 = 0
        for i in range(5):
            for j in range(7):
                if probability_array[i][j] > max_value:
                    max_value = probability_array[i][j]
                    index1 = i
                    index2 = j

        probability_array = check_environment(new_environment,index1,index2,probability_array)
        print('Probability:',cnt+1)
        print(probability_array)

        new_environment = real_environment()
        
        if cnt==9:
            break
        print('New environment:',cnt+2)
        print(new_environment)
