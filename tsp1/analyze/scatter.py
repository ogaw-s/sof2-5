import csv
import matplotlib.pyplot as plt

csv_file = 'result-cities20seed1.csv' #seed10と100も調べる
x_data = []
y_data = []

with open(csv_file, mode='r', encoding='utf-8') as file:
    reader = csv.reader(file)
    for row in reader:
        x_data.append(float(row[0]))
        y_data.append(float(row[1]))

plt.scatter(x_data, y_data, color='blue', alpha=0.7)
plt.title('cities20seed1.csv') #適宜変更
plt.xlabel('number of trials')
plt.ylabel('possibility')
plt.grid(True)
plt.show()
