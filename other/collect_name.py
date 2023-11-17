import os
import re
# pip install natsort
from natsort import natsorted
# Specify the folder path
folder_path = "question"

# Get a list of file names in the folder and sort them
file_names = natsorted(os.listdir(folder_path))

# Loop through all files in the sorted list
for filename in file_names:
    if filename.endswith(".txt"):
        file_path = os.path.join(folder_path, filename)

        with open(file_path, "r", encoding="utf-8") as file:
            text = file.read()

        # Use regular expression to find names between "From" and "To"
        matches = re.findall(r"From (.*?) To", text, re.MULTILINE)

        # Print the file name
        print("File:", filename)

        # Print the extracted names
        for name in matches:
            if name != "SUTASINEE THOVUTTIKUL":
                print("Name:", name)