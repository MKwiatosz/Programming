from tpot import TPOTClassifier
from sklearn.model_selection import train_test_split
import pandas as pd
import numpy as np

# Load data
telescope = pd.read_csv('MAGIC Gamma Telescope Data.csv')

# Clean the data
telescope_shuffle=telescope.iloc[np.random.permutation(len(telescope))]
tele=telescope_shuffle.reset_index(drop=True)

# Store 2 classes
tele['Class']=tele['Class'].map({'g':0,'h':1})
tele_class=tele['Class'].values

# Split training, testing and validation data
training_indicies, validation_indicies = training_indicies, training_indicies = train_test_split(tele.index,stratify= tele_class, train_size=0.75, test_size=0.25)

# Let Genetic Programming find best ML model and hyperparameters
tpot = TPOTClassifier(generations=5, verbosity=2)
tpot.fit(tele.drop('Class', axis=1).loc[training_indicies].values, tele.loc[training_indicies, 'Class'].values)

# Score the accuracy
tpot.score(tele.drop('Class', axis=1).loc[validation_indicies].values, tele.loc('Class').loc[validation_indicies].values)

# Export
tpot.export('pipeline.py')
