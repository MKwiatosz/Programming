import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.metrics import r2_score
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression

# Load dataset
url = "https://raw.githubusercontent.com/callxpert/datasets/master/data-scientist-salaries.cc"
names = ['Years-experience', 'salary']
dataset = pd.read_csv(url, names=names)

# Data shape
print (dataset)
print ("Data shape: ", dataset.shape)

# Data statistics
print(dataset.describe())

# Data visualization
dataset.plot()
plt.show()

#######################################
# Splitting the data
X = dataset[['Years-experience']]
y = dataset[['salary']]
features_train, features_test, labels_train, labels_test = train_test_split(X, y, test_size=0.3, random_state= 101)

clf = LinearRegression()
clf.fit(features_train, labels_train)

pred = clf.predict(features_test)

print("Accuracy: ", r2_score(labels_test, pred))
