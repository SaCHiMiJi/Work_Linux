from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time

# URL of the page
url = 'https://www.thaiticketmajor.com/concert/the-1st-blue-dragon-music-awards.html'

# Setting up the WebDriver (Chrome in this example)
driver = webdriver.Chrome(executable_path='path_to_your_chromedriver')

# Open the URL
driver.get(url)

try:
    # Wait until the Sign In button is visible and clickable
    signin_button = WebDriverWait(driver, 10).until(
        EC.element_to_be_clickable((By.CSS_SELECTOR, ".btn-signin.item"))
    )
    
    # Click the Sign In button
    signin_button.click()
    
    # Additional code to handle sign-in can be added here (e.g., filling credentials)

    # Attempt to click the other button up to 10 times with a 10-minute delay between attempts
    for attempt in range(10):
        try:
            # Wait until the other button is available to be clicked (max 10 seconds)
            other_button = WebDriverWait(driver, 10).until(
                EC.element_to_be_clickable((By.CSS_SELECTOR, ".btn-item .btn:not([disabled])"))
            )
            
            # Click the other button
            other_button.click()

            # If click is successful, break out of the loop
            print("Click successful.")
            break

        except Exception as e:
            print(f"Attempt {attempt + 1} failed: {e}")
            # Wait for 10 minutes before the next attempt
            time.sleep(600)  # 600 seconds = 10 minutes

except Exception as e:
    print(f"Error: {e}")
finally:
    # Close the browser
    driver.quit()
