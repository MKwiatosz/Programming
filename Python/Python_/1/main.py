import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.datasets import make_moons, make_circles, make_classification
from sklearn.neural_network import MLPClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn.gaussian_process import GaussianProcessClassifier
from sklearn.gaussian_process.kernels import RBF
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier, AdaBoostClassifier
from sklearn.naive_bayes import GaussianNB
from sklearn.discriminant_analysis import QuadraticDiscriminantAnalysis
from sklearn.metrics import accuracy_score

# [height,weight, shoe size]

X = [ [180,60,43],
      [160,50,38],
      [174,60,37],
      [165,55,36],
      [180,90,44],
      [190,100,44],
      [179,60,39],
      [167,69,39],
      [160,71,40],
      [173,63,38],
      [167,70,42],
      [169,56,41]
      ]

Y = ['male',
     'female',
     'female',
     'female',
     'male',
     'male',
     'male',
     'female',
     'female',
     'male',
     'female',
     'female'
     ]

# Different classifiers:

clf_0 = KNeighborsClassifier(3)
clf_1 = SVC(kernel="linear", C=0.025)
clf_2 = SVC(gamma=2, C=1)
clf_3 = GaussianProcessClassifier()
clf_4 = DecisionTreeClassifier()
clf_5 = RandomForestClassifier(max_depth=5, n_estimators=10, max_features=1)
clf_6 = MLPClassifier(alpha=1)
clf_7 = AdaBoostClassifier()
clf_8 = GaussianNB()
clf_9 = QuadraticDiscriminantAnalysis()

clf_0 = clf_0.fit(X,Y)
clf_1 = clf_1.fit(X,Y)
clf_2 = clf_2.fit(X,Y)
clf_3 = clf_3.fit(X,Y)
clf_4 = clf_4.fit(X,Y)
clf_5 = clf_5.fit(X,Y)
clf_6 = clf_6.fit(X,Y)
clf_7 = clf_7.fit(X,Y)
clf_8 = clf_8.fit(X,Y)
clf_9 = clf_9.fit(X,Y)

prediction_KNeighborsClassifier             = clf_0.predict(X)
prediction_SVC_1                            = clf_1.predict(X)
prediction_SVC_2                            = clf_2.predict(X)
prediction_GaussianProcessClassifier        = clf_3.predict(X)
prediction_DecisionTreeClassifier           = clf_4.predict(X)
prediction_RandomForestClassifier           = clf_5.predict(X)
prediction_MLPClassifier                    = clf_6.predict(X)
prediction_AdaBoostClassifier               = clf_7.predict(X)
prediction_GaussianNB                       = clf_8.predict(X)
prediction_QuadraticDiscriminantAnalysis    = clf_9.predict(X)

print ("\nPrediction_KNeighborsClassifier = ", prediction_KNeighborsClassifier)
print ("Prediction_SVC_1 = ",prediction_SVC_1)
print ("Prediction_SVC_2 = ",prediction_SVC_2)
print ("Prediction_DecisionTreeClassifier = ",prediction_DecisionTreeClassifier)
print ("Prediction_GaussianProcessClassifier = ",prediction_GaussianProcessClassifier)
print ("Prediction_RandomForestClassifier = ", prediction_RandomForestClassifier)
print ("Prediction_MLPClassifier = ",prediction_MLPClassifier)
print ("Prediction_AdaBoostClassifier = ", prediction_AdaBoostClassifier)
print ("Prediction_GaussianNB = ", prediction_GaussianNB)
print ("Prediction_QuadraticDiscriminantAnalysis = ",prediction_QuadraticDiscriminantAnalysis)

acc_KN = accuracy_score(Y, prediction_KNeighborsClassifier) * 100
print('\nAccuracy for KNeighbors: {}'.format(acc_KN))
acc_SVC1 = accuracy_score(Y, prediction_SVC_1) * 100
print('Accuracy for SVC_1: {}'.format(acc_SVC1))
acc_SVC2 = accuracy_score(Y, prediction_SVC_2) * 100
print('Accuracy for SVC_2: {}'.format(acc_SVC2))
acc_tree = accuracy_score(Y, prediction_DecisionTreeClassifier) * 100
print('Accuracy for DecisionTree: {}'.format(acc_tree))
acc_Gaussian = accuracy_score(Y, prediction_GaussianProcessClassifier) * 100
print('Accuracy for GaussianProcess: {}'.format(acc_Gaussian))
acc_Forest = accuracy_score(Y, prediction_RandomForestClassifier) * 100
print('Accuracy for RandomForest: {}'.format(acc_Forest))
acc_MLP = accuracy_score(Y,prediction_MLPClassifier) * 100
print('Accuracy for MLP: {}'.format(acc_MLP))
acc_AdaBoos = accuracy_score(Y, prediction_AdaBoostClassifier) * 100
print('Accuracy for AdaBoost: {}'.format(acc_AdaBoos))
acc_GaussianNB = accuracy_score(Y, prediction_GaussianNB) * 100
print('Accuracy for GaussianNB: {}'.format(acc_GaussianNB))
acc_QuadraticDiscriminantAnalysis = accuracy_score(Y, prediction_QuadraticDiscriminantAnalysis) * 100
print('Accuracy for QuadraticDiscriminantAnalysis: {}'.format(acc_QuadraticDiscriminantAnalysis))

index = np.argmax([acc_KN, acc_SVC1, acc_SVC2, acc_tree, acc_Gaussian, acc_Forest, acc_MLP, acc_AdaBoos, acc_GaussianNB, acc_QuadraticDiscriminantAnalysis])
classifiers = {0: 'KN', 1: 'SVC_1', 2: 'SVC_2', 3: 'Tree', 4: 'Gaussian', 5: 'Forest', 6: 'MLP', 7: 'AdaBoos', 8: 'GaussianNB', 9: 'QuadraticDiscriminantAnalysi'}
print('\nBest gender classifier is {}'.format(classifiers[index]))
