from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import TimeoutException, NoSuchElementException
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
import time
from datetime import datetime
import pytz  # You may need to install the pytz library
# URL of the page
url = 'https://www.thaiticketmajor.com/concert/the-1st-blue-dragon-music-awards.html'
# url = 'https://www.thaiticketmajor.com/concert/the-golden-melody-concert.html'

# Your login credentials
email = "kullanan.ruggitwanitkull@gmail.com"
password = "Jib26112541"
attempt = 0

# Path to Brave browser executable
brave_path = "/Applications/Brave Browser.app/Contents/MacOS/Brave Browser/brave.exe"  # Replace with the actual path

options = Options()
options.binary_location = brave_path
service = Service(executable_path="path/to/chromedriver")  # chromedriver path

# Initialize the WebDriver with the options
driver = webdriver.Chrome(service=service, options=options)
# Setting up the WebDriver (Chrome in this example)
driver = webdriver.Chrome()

# Open the URL
driver.get(url)

# Define the number of attempts for clicking the date button
max_attempts = 10000

# Define the desired time zone (GMT+7)
desired_timezone = pytz.timezone('Asia/Bangkok')

# Function to check if it's 11:00 in the desired time zone
def is_11_in_desired_timezone():
    current_time = datetime.now(pytz.utc)  # Get current time in UTC
    current_time = current_time.astimezone(desired_timezone)  # Convert to desired timezone
    return current_time.hour == 11

try:
    # Click the login button to open the login form
    login_button = WebDriverWait(driver, 10).until(
        EC.element_to_be_clickable((By.CLASS_NAME, "btn-signin"))
    )
    login_button.click()
    
    # Wait for the email input field to be visible
    email_field = WebDriverWait(driver, 10).until(
        EC.visibility_of_element_located((By.NAME, "username"))
    )
    # Fill in the email
    email_field.send_keys(email)
    
    # Wait for the password input field to be visible
    password_field = WebDriverWait(driver, 10).until(
        EC.visibility_of_element_located((By.NAME, "password"))
    )
    # Fill in the password
    password_field.send_keys(password)
    
    # Find and click the submit button
    submit_button = WebDriverWait(driver, 10).until(
        EC.element_to_be_clickable((By.CSS_SELECTOR, "button.btn-red.btn-signin"))
    )
    submit_button.click()
    
    # Wait for a successful login here, this might include a redirect or a dynamic content load

except Exception as e:
    print(f"Login error: {e}")
    driver.quit()
    exit()

# Attempt to click the button with the specific date text multiple times
while True:
    try:
        attempt+=1
        print(attempt)
        
        
        # Check if it's 11:00 in Bangkok timezone and refresh the browser if true
        if is_11_in_desired_timezone():
            driver.refresh()
            print("Refreshed the browser at 11:00 in Bangkok timezone.")
        
        # Re-locate the button on each attempt to avoid stale element reference
        date_button_text = "18:00"
        date_button = WebDriverWait(driver, 0.01).until(
            EC.element_to_be_clickable((By.CSS_SELECTOR, "span.item-show"))
        )

        date_button.click()

        # Wait for a unique element that indicates the new page has loaded.
        # Replace 'unique_element_css_selector' with the actual CSS selector.
        WebDriverWait(driver,0.01).until(
            EC.presence_of_element_located((By.CSS_SELECTOR, 'unique_element_css_selector'))
        )
        
        print("Navigation to new page was successful.")
        break  # If click is successful and new page is detected, break out of the loop

    except TimeoutException:
        print(f"Attempt {attempt + 1} failed: Either button not clickable or new page did not load. Retrying...")
        # Delay between attempts, if needed
    except Exception as e:
        print(f"Error during clicking the date button or waiting for new page: {e}")
        # Delay or exit strategy, if needed

# After the loop, you can proceed with further actions or close the browser
# driver.quit()
