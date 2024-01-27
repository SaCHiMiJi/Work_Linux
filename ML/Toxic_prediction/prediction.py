
import joblib
import pandas as pd
import re
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

# Load the saved model
model = joblib.load('./model/logistic_regression_model.joblib')

# Load your new data for prediction
data_new = pd.read_csv('./data/test.csv')
data_new['comment_text'] = data_new['comment_text'].apply(clean_text)  # Clean the text in the new data

# Assuming that data_new contains a column 'id' and 'comment_text'
# And you need to add a column 'predicted_class'

# Load or recreate your original training data here for the TF-IDF Vectorizer
data_original = pd.read_csv('./data/train.csv')
data_original['comment_text'] = data_original['comment_text'].apply(clean_text)  # Clean the text in the original data
tfidf = TfidfVectorizer(max_features=5000)
tfidf.fit(data_original['comment_text'])

# Transform the new data using the fitted TF-IDF Vectorizer
X_new = tfidf.transform(data_new['comment_text'])

# Making predictions
predictions = model.predict(X_new)

# Adding predictions to the DataFrame
data_new['predicted_class'] = predictions

# Saving the predictions in the format of the sample submission
data_new[['id', 'predicted_class']].to_csv('./predictions.csv', index=False)
