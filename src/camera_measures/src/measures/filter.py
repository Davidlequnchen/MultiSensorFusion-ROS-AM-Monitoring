import numpy as np


class Filter():
    def __init__(self, fc=100):
        self.fc = fc
        self.y = 0
        self.t = 0

    def update(self, x, t):
        DT = t - self.t
        a = (2 * np.pi * DT * self.fc) / (2 * np.pi * DT * self.fc + 1)
        y = a * x + (1 - a) * self.y
        self.y = y
        self.t = t
        return y


if __name__ == '__main__':
    import matplotlib.pyplot as plt

    t1 = 1448535428.73
    x1 = 3.0
    t2 = 1448535428.75
    x2 = 3.2
    t3 = 1448535429.22
    x3 = 3.15

    filter = Filter(10)
    print filter.update(x1, t1)
    print filter.update(x2, t2)
    print filter.update(x3, t3)

    filter = Filter(50)
    time = 0.001 * (np.arange(1000) + np.random.random(1000))
    signal = 10 * np.random.random(1000)
    signal[100:500] = 50 + signal[100:500]
    signal[500:700] = 75 + signal[500:700]
    output = []
    for k in range(1000):
        y = filter.update(signal[k], time[k])
        output.append(y)
    output = np.array(output)

    plt.figure()
    plt.plot(time, signal, 'b-')
    plt.plot(time, output, 'r-', lw=2)
    plt.show()
