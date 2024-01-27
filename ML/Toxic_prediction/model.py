
# Importing necessary libraries
import pandas as pd
import numpy as np
import re
import nltk
from nltk.corpus import stopwords
from nltk.stem import WordNetLemmatizer
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from imblearn.over_sampling import SMOTE
import joblib  # Library for saving the model

# Load your dataset
data = pd.read_csv('./data/train.csv')

# Data Preprocessing
nltk.download('stopwords')
nltk.download('wordnet')
lemmatizer = WordNetLemmatizer()
stop_words = set(stopwords.words('english'))

def clean_text(text):
    if isinstance(text, str):
        text = text.lower()
        text = re.sub(r'\W', ' ', text)  # Remove all non-word characters
        text = re.sub(r'\s+', ' ', text, flags=re.I)  # Replace multiple spaces with a single space
        text = ' '.join([lemmatizer.lemmatize(word) for word in text.split() if word not in stop_words])
        return text
    else:
        return ""

# Clean 'comment_text' and handle 'toxic' column
data['comment_text'] = data['comment_text'].apply(clean_text)
data['toxic'] = data['toxic'].fillna('0')  # Convert NaN to '0'
data = data[data['toxic'] != '1']  # Remove rows with 'toxic' as '??'
y = data['toxic'].astype(int)  # Convert 'toxic' to integer

# TF-IDF Vectorization
tfidf = TfidfVectorizer(max_features=5000)
X = tfidf.fit_transform(data['comment_text'])

# Handling Imbalanced Data
smote = SMOTE()
X_res, y_res = smote.fit_resample(X, y)

# Train-test Split
X_train, X_test, y_train, y_test = train_test_split(X_res, y_res, test_size=0.2, random_state=42)

# Building and Training Logistic Regression Model
model = LogisticRegression()
model.fit(X_train, y_train)

# Saving the Model
joblib.dump(model, './model/logistic_regression_model.joblib')

# Model Evaluation
accuracy = model.score(X_test, y_test)
print(f'Accuracy: {accuracy}')
