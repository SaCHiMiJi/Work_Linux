import os
import re
from natsort import natsorted
import csv

# Specify the folder path
folder_path = "question"

# Get a list of file names in the folder and sort them naturally
file_names = natsorted(os.listdir(folder_path))

# Create a dictionary to store the mapping of names to file names and their counts
name_to_files = {}

# Loop through all files in the sorted list
for filename in file_names:
    if filename.endswith(".txt"):
        file_path = os.path.join(folder_path, filename)

        with open(file_path, "r", encoding="utf-8") as file:
            text = file.read()

        # Use regular expression to find names between "From" and "To"
        matches = re.findall(r"From (.*?) To", text, re.MULTILINE)

        for name in matches:
            if name != "SUTASINEE THOVUTTIKUL":
                if name not in name_to_files:
                    name_to_files[name] = {"files": set(), "count": 0}
                name_to_files[name]["files"].add(filename)
                name_to_files[name]["count"] += 1

# Sort the data by "Name"
sorted_data = sorted(name_to_files.items(), key=lambda item: item[0])

# Specify the CSV file name
csv_file = str(input("input file name : "))+".csv"

# Write the reversed dictionary into a CSV file
with open(csv_file, "w", newline="", encoding="utf-8") as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(["Name", "File Count", "Files"])
    for name, data in sorted_data:
        # Convert the set of file names to a list and remove the ".txt" extension
        formatted_files = [file.replace(".txt", "") for file in list(data["files"])]
        writer.writerow([name, data["count"], ", ".join(formatted_files)])

print(f"File has been written to {csv_file}.")
