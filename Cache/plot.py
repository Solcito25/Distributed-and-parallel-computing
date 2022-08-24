# Importing packages
import matplotlib.pyplot as plt

# Define data values
y1 = [0.0000025, 0.000039, 0.0031344, 0.327767]
y2 = [0.000001, 0.0000474, 0.0043709, 1.14602]
x = [10,100,1000,10000]
plt.title("First and Second loop Comparation")
plt.xlabel("Size of MAX")
plt.ylabel("Time/Seconds")
# Plot a simple line chart
plt.plot(x, y1,'g', label='First loop')

# Plot another line on the same chart/graph
plt.plot(x, y2,'r', label='Second loop')
plt.legend()
plt.grid()
plt.show()
