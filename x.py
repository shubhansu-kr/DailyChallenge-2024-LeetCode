import pyautogui
import time

# Function to switch to the next tab using Alt + Tab
def switch_tab():
    pyautogui.hotkey('alt', 'tab')
    time.sleep(1)  # Adjust the sleep time as needed to ensure proper tab switching

# Function to type a message and hit Enter
def send_message(message):
    pyautogui.typewrite(message)
    pyautogui.press('enter')
    time.sleep(1)  # Adjust the sleep time as needed between sending messages

# Number of messages to send
num_messages = 1000

# Message to send
message_to_send = "Your message here"

# Switch to the target application/tab
switch_tab()

# Loop to send messages
for i in range(num_messages):
    send_message(message_to_send)
