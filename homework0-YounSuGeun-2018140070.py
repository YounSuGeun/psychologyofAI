#problem 1: calculator
def Function(a, b, c):
    if c == '+':
        print(float(a) + float(b))
    elif c == '-':
        print(float(a) - float(b))
    elif c == '*':
        print(float(a) * float(b))
    elif c == '/':
        print(float(a) // float(b), 'remainder=', float(a) % float(b))

Function(1,2,'+')
Function(3,4,'-')
Function(4,5,'*')
Function(5, 4, '/')


#problem 2: counting frequency
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

data = np.random.randint(low=0, high=10, size=(10,10))

a=[]
for k in range(10):
    c = 0
    for i in range(10):
        for j in range(10):
            if data[i][j] == k:
                c = c + 1
    a.append(c)

data = {
    'label': range(10),
    'counts': a
}

df = pd.DataFrame(data, index=data['label'])

plt.bar(df['label'], df['counts'])
plt.show()

#problem 3: sorting
import numpy as np

rdlist = np.random.rand(1000)

a = [0,1]
for i in rdlist:
    for k in range(len(a)):
        if a[k] < i < a[k+1]:
                a.insert(k+1, i)

a.remove(0)
a.remove(1)

print(a)
