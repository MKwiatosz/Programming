# Dependencies
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LogisticRegression, LinearRegression
from sklearn.ensemble import RandomForestClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn.model_selection import train_test_split
from sklearn.model_selection import GridSearchCV
from sklearn.metrics import accuracy_score

# Loading data
url = "https://raw.githubusercontent.com/callxpert/datasets/master/iris.data.txt"
names = ['sepal-length', 'sepal-width', 'petal-length', 'petal-width', 'class']
dataset = pd.read_csv(url, names=names)

# Data details
print('Data shape: ', dataset.shape)
print('------------------------------------------------------------------------------')
print('Data first 10:\n ', dataset.head(10))
print('------------------------------------------------------------------------------')
print('Data stats:\n ', dataset.describe())
print('------------------------------------------------------------------------------')

# Class distribution HOW MANY OBJECT HAVE DIFFERENT FLOWER
print('How many objects have different flower:\n', dataset.groupby('class').size())
print('------------------------------------------------------------------------------')

# Box and whisker plots
dataset.plot(kind='box', subplots=True, layout=(2,2), sharex=False, sharey=False)
#plt.show()

# Histogram
dataset.hist()
plt.show()

# Scatter plot matrix IMPORTANT FEATURES WITH RESPECT TO OTHER
pd.plotting.scatter_matrix(dataset, alpha=0.5, figsize=(8, 8), diagonal='kde')
plt.show()

# Splitting the data
array = dataset.values
X = array[:,0:4]
Y = array[:,4]
features_train, features_test, labels_train, labels_test = train_test_split(X, Y, test_size=0.2, random_state=7)

# Parameters for GridSearch for different algorithms
param_SVC = {'kernel':('linear','rbf','poly'), 'C':[1,10,100,1000], 'gamma':[0.0001,0.001,0.01,0.1,1], 'degree':[0,1,2,3]}
param_KN = {'n_neighbors':[1,2,3,4,5], 'algorithm':('auto', 'ball_tree', 'kd_tree'), 'leaf_size':[10,20,30]}
param_RF = {'n_estimators':[2,3,4,5,6,7,8,10,12,14], 'min_samples_split':[2,3,4,5,6], 'min_samples_leaf':[1,2,3,4]}
# param_LogisticR = {'penalty':('l1','12')}

# Making a models and fit the data
clf_SVC = GridSearchCV(SVC(),param_SVC)
clf_SVC.fit(features_train,labels_train)

clf_KN = GridSearchCV(KNeighborsClassifier(), param_KN)
clf_KN.fit(features_train,labels_train)

clf_RF = GridSearchCV(RandomForestClassifier(), param_RF)
clf_RF.fit(features_train,labels_train)

clf_LogisticR = LogisticRegression()
clf_LogisticR.fit(features_train,labels_train)

# Prediction with help of different models
pred_SVC = clf_SVC.predict(features_test)
pred_KN = clf_KN.predict(features_test)
pred_RF = clf_RF.predict(features_test)
pred_LogisticR = clf_LogisticR.predict(features_test)

# Printing the score
print('SVC score: ', accuracy_score(labels_test, pred_SVC))
print('KN score: ', accuracy_score(labels_test, pred_KN))
print('RF score: ', accuracy_score(labels_test, pred_RF))
print('Logistic score: ', accuracy_score(labels_test, pred_LogisticR))

