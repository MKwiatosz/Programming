# Dependencies
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.metrics import accuracy_score
from sklearn.linear_model import LinearRegression, LogisticRegression
from sklearn.svm import SVC
from sklearn.ensemble import RandomForestClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier, export_graphviz
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import GridSearchCV

print('0')
# Load the data
url = "https://raw.githubusercontent.com/callxpert/datasets/master/Loan-applicant-details.csv"
names = ['Loan_ID','Gender','Married','Dependents','Education','Self_Employed','ApplicantIncome','CoapplicantIncome','LoanAmount','Loan_Amount_Term','Credit_History','Property_Area','Loan_Status']
dataset = pd.read_csv(url, names=names)
print('1')
# Label Encoder ENCODING NON NUMERICAL VALUES TO BE NUMERIC.   SKLEARN REQUIRES ALL INPUTS TO BE NUMERIC
########################################################################################################
#
#                                   train = ["paris", "paris", "tokyo", "amsterdam"]
#                                   test = ["tokyo", "tokyo", "paris"]
#                                   le.fit(train).transform(test)
#                                   array([2, 2, 1]...)
# tokyo is train[2] --> 2 , paris is train[1] --> 1
########################################################################################################
var_mod = ['Gender','Married','Dependents','Education','Self_Employed','Property_Area','Loan_Status']
le = LabelEncoder()
for i in var_mod:
    dataset[i] = le.fit_transform(dataset[i])
print('2')
# Splitting the data
array = dataset.values
X = array[:,6:11]
y = array[:,12]
y=y.astype('int')
features_train, features_test, labels_train, labels_test = train_test_split(X, y, test_size=0.2, random_state=7)
print('3')
# Search of well suited parameters of model
param_SVC = {'kernel':('linear','rbf','poly'), 'C':[1,10,100,1000], 'gamma':[0.0001,0.001,0.01,0.1,1], 'degree':[0,1,2,3]}
param_KN = {'n_neighbors':[1,2,3,4,5], 'algorithm':('auto', 'ball_tree', 'kd_tree'), 'leaf_size':[10,20,30]}
param_RF = {'n_estimators':[2,3,4,5,6,7,8,10,12,14], 'min_samples_split':[2,3,4,5,6], 'min_samples_leaf':[1,2,3,4]}
param_DT = {'criterion':('gini', 'entropy'), 'min_samples_leaf':[1,2,3]}

# Making a models and fit the data
##############SVC######################
# clf_SVC = GridSearchCV(SVC(),param_SVC)
# clf_SVC.fit(features_train,labels_train)
# print('SVC fit DONE')
# ##############KN#######################
# clf_KN = GridSearchCV(KNeighborsClassifier(), param_KN)
# clf_KN.fit(features_train,labels_train)
# print('KN fit DONE')
##############RF#######################
clf_RF = GridSearchCV(RandomForestClassifier(), param_RF)
clf_RF.fit(features_train,labels_train)
print('RF fit DONE')
##############LogisticR################
clf_LogisticR = LogisticRegression()
clf_LogisticR.fit(features_train,labels_train)
print('LogisticR fit DONE')
##############DT#######################
clf_DT = GridSearchCV(DecisionTreeClassifier(),param_DT)
clf_DT.fit(features_train,labels_train)
print('DT fit DONE')
# Prediction with help of different models
# pred_SVC = clf_SVC.predict(features_test)
# pred_KN = clf_KN.predict(features_test)
pred_RF = clf_RF.predict(features_test)
pred_LogisticR = clf_LogisticR.predict(features_test)
pred_DT = clf_DT.predict(features_test)

# Printing the score
# print('SVC score: ', accuracy_score(labels_test, pred_SVC))
# print('KN score: ', accuracy_score(labels_test, pred_KN))
print('RF score: ', accuracy_score(labels_test, pred_RF))
print('Logistic score: ', accuracy_score(labels_test, pred_LogisticR))
print('DecissionTree score: ', accuracy_score(labels_test, pred_DT))
