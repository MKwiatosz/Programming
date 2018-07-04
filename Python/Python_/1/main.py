from sklearn import tree

# [height,weight, shoe size]

X = [ [180,60,43], [160,50,38], [174,60,37], [165,55,36], [180,90,44],
      [190,100,44]]

Y = ['male', 'female', 'female', 'female', 'male', 'male']

clf = tree.DecisionTreeClassifier()

clf = clf.fit(X,Y)

prediction = clf.predict([[190,65,43]])

print (prediction)
