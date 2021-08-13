import matplotlib.pyplot as plt

x = [i for i in range(0, 1000001, 50000)]
merge = [0, 11, 24, 42, 52, 66, 79, 93, 103, 118,
         135, 152, 159, 176, 186, 210, 218, 232, 245, 264, 267]
quick = [0, 6, 12, 22, 26, 34, 41, 48, 56, 65, 74,
         81, 89, 100, 105, 115, 126, 134, 149, 153, 162]
selection = [0, 2994, 12373, 26995, 47763, 74666, 107442, 146487, 190718, 241365, 297795,
             360671, 428151, 509093, 675927, 886198, 807212, 872610, 979236, 1083728, 1246081]
bubble = [0, 7149, 25071, 48128, 81011, 117353, 182828, 213937, 268941, 321632, 987590,
          462682, 543555, 617775, 703875, 803337, 903364, 1006225, 1128747, 1301994, 1383120]

# plt.plot(x, quick, '.b-', linewidth=2.5, label="Quick Sort")
# plt.plot(x, merge, '.y-', label="Merge Sort")
plt.plot(x, selection, '.g-', label="Selection Sort")
plt.plot(x, bubble, '.r-', label="Bubble Sort")

plt.xlabel("Size")
plt.ylabel("Execution Time (in Clock Cycles) ")

plt.title("Size vs Execution-time")
plt.legend()
plt.show()
