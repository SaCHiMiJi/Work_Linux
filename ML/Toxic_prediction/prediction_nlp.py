import pandas as pd
import re
import joblib
import tensorflow as tf
from nltk.corpus import stopwords
from nltk.stem import WordNetLemmatizer
from sklearn.feature_extraction.text import TfidfVectorizer

# Function for cleaning text
def clean_text(text):
    if isinstance(text, str):
        text = text.lower()
        text = re.sub(r'\W', ' ', text)  # Remove all non-word characters
        text = re.sub(r'\s+', ' ', text, flags=re.I)  # Replace multiple spaces with a single space
        lemmatizer = WordNetLemmatizer()
        stop_words = set(stopwords.words('english'))
        text = ' '.join([lemmatizer.lemmatize(word) for word in text.split() if word not in stop_words])
        return text
    else:
        return ""

# Load the saved neural network model
model = tf.keras.models.load_model('./model/neural_network_model.keras')

# Load your new data for prediction
data_new = pd.read_csv('./data/test.csv')
data_new['comment_text'] = data_new['comment_text'].apply(clean_text)  # Clean the text in the new data

# Load the saved TF-IDF Vectorizer
tfidf = joblib.load('./model/tfidf_vectorizer.joblib')

# Transform the new data using the fitted TF-IDF Vectorizer
X_new = tfidf.transform(data_new['comment_text']).toarray()

# Making predictions
predictions = model.predict(X_new)
# Convert predictions to binary labels (0 or 1)
predictions = (predictions >= 0.5).astype(int).flatten()

# Adding predictions to the DataFrame
data_new['predicted_class'] = predictions

# Saving the predictions in the format of the sample submission
data_new[['id', 'predicted_class']].to_csv('./predictions_nlp.csv', index=False)
