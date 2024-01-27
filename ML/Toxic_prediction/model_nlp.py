# Importing necessary libraries
import pandas as pd
import re
import nltk
from nltk.corpus import stopwords
from nltk.stem import WordNetLemmatizer
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Dropout
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.model_selection import train_test_split
from imblearn.over_sampling import SMOTE
import joblib

# Load your dataset
data = pd.read_csv('./data/train.csv')

# Data Preprocessing
nltk.download('stopwords')
nltk.download('wordnet')
def clean_text(text):
    if isinstance(text, str):
        text = text.lower()
        text = re.sub(r'[^\w\s]', '', text)  
        text = re.sub(r'\d+', '', text) 
        stop_words = set(stopwords.words('english'))
        text = ' '.join([word for word in text.split() if word not in stop_words])
        lemmatizer = WordNetLemmatizer()
        text = ' '.join([lemmatizer.lemmatize(word) for word in text.split()])
        return text
    else:
        return ""

# Apply text cleaning and handle NaN values in 'comment_text'
data['comment_text'] = data['comment_text'].fillna('').apply(clean_text)

# Convert NaN values in 'toxic' to 0 and remove rows with '??'
data['toxic'] = data['toxic'].fillna(0)
data = data[data['toxic'] != '??']
data['toxic'] = data['toxic'].astype(int)

# TF-IDF Vectorization
tfidf = TfidfVectorizer(max_features=5000)
X = tfidf.fit_transform(data['comment_text']).toarray()
y = data['toxic']

# Handling Imbalanced Data
smote = SMOTE()
X_res, y_res = smote.fit_resample(X, y)

# Train-test Split
X_train, X_test, y_train, y_test = train_test_split(X_res, y_res, test_size=0.2, random_state=42)

# Neural Network Model
model = Sequential()
model.add(Dense(256, activation='relu', input_dim=X_train.shape[1]))
model.add(Dropout(0.5))
model.add(Dense(128, activation='relu'))
model.add(Dropout(0.4))
model.add(Dense(64, activation='relu'))
model.add(Dropout(0.3))
model.add(Dense(32, activation='relu'))
model.add(Dropout(0.2))
model.add(Dense(1, activation='sigmoid'))

model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

# Train the model
model.fit(X_train, y_train, epochs=100, batch_size=64, validation_data=(X_test, y_test))

# Save the TF-IDF Vectorizer and the Model
joblib.dump(tfidf, './model/tfidf_vectorizer.joblib')
model.save('./model/neural_network_model.keras')  

# Evaluate the model
loss, accuracy = model.evaluate(X_test, y_test)
print(f'Accuracy: {accuracy}')
