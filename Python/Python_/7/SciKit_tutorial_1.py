import matplotlib.pyplot as plt
from sklearn import datasets
from sklearn import svm

digits = datasets.load_digits()


clf = svm.SVC(gamma=0.001, C=1000)

print(len(digits.data))

X,y = digits.data[:-1], digits.target[:-1]
clf.fit(X,y)

print('Prediction: ', clf.predict(digits.data)[-5])

plt.imshow(digits.images[-15], cmap=plt.cm.gray_r, interpolation='nearest')
plt.show()
