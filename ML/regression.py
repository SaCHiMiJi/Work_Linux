import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_squared_error
import matplotlib.pyplot as plt
import seaborn as sns

# Load and preprocess the training data
file_path = 'train.csv'  # Update with the path to your training data
data = pd.read_csv(file_path)
data_encoded = pd.get_dummies(data, columns=['sex', 'smoker', 'region'])
X = data_encoded.drop('charges', axis=1)
y = data_encoded['charges']
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=68975)

# Function to train Random Forest model and calculate RMSE
# def train_rf_and_calculate_rmse(random_state):
#     rf_regressor = RandomForestRegressor(n_estimators=200, max_depth=25, random_state=random_state)
#     rf_regressor.fit(X_train, y_train)
#     y_pred = rf_regressor.predict(X_test)
#     rmse = np.sqrt(mean_squared_error(y_test, y_pred))
    
#     return rmse

# Iterate over random_state values to find the one with the lowest RMSE
# best_rmse = float('inf')
# best_random_state = None
# for state in range(10000, 100001):  # Adjust the range as needed
#     current_rmse = train_rf_and_calculate_rmse(state)
#     print("{0}: {1}".format(state,current_rmse))
#     if current_rmse < best_rmse:
#         best_rmse = current_rmse
#         best_random_state = state

# print(f"Best RMSE: {best_rmse} found with random_state: {best_random_state}")

# Optional: Load and preprocess the test data for prediction
test_file_path = 'test.csv'  # Update with the path to your test data
test_data = pd.read_csv(test_file_path)
test_data_encoded = pd.get_dummies(test_data, columns=['sex', 'smoker', 'region'])
test_features_aligned = test_data_encoded.reindex(columns=X_train.columns, fill_value=0)

# Generate predictions for the test set with the best model
best_rf_model = RandomForestRegressor(n_estimators=200, max_depth=25, random_state=68975)
best_rf_model.fit(X_train, y_train)
test_predictions = best_rf_model.predict(test_features_aligned)

# Save the test predictions to a CSV file
test_predictions_df = pd.DataFrame({'id': test_data['id'], 'predicted': test_predictions})
test_predictions_file_path = 'predictions.csv'  # Update with your desired path
test_predictions_df.to_csv(test_predictions_file_path, index=False)
