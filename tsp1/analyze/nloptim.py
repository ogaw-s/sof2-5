import numpy as np
import pandas as pd
from scipy.optimize import curve_fit
import matplotlib.pyplot as plt

def model(x, a, b):
    return a * (1 - np.exp(b * x))

csv_file = 'result-cities20seed1.csv'
data = pd.read_csv(csv_file)

x_data = data['x'].values
y_data = data['y'].values

initial_guess = [1.0, -0.1]
params, covariance = curve_fit(model, x_data, y_data, p0=initial_guess)

a, b = params
print(f"Fitted parameters: a = {a}, b = {b}")

plt.figure(figsize=(8, 6))
plt.scatter(x_data, y_data, label="Data", color="blue")
plt.plot(x_data, model(x_data, a, b), label=f"Fit: a(1-e^(bx))", color="red")
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.title(f"seed1 regression a=1.020, b=-0.035")
plt.grid()
plt.show()
