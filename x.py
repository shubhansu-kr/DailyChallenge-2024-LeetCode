import time
import keyboard

def auto_type(text_to_type, delay=0.1):
    # Wait for a few seconds before typing starts
    time.sleep(5)

    # Type each character in the text
    for char in text_to_type:
        # Type one character
        keyboard.press(char)
        # Wait for the specified delay
        time.sleep(delay)
        # Release the key
        keyboard.release(char)

if __name__ == "__main__":
    # Set the constant string to type
    const_text_to_type = '''
    Reducing delay, The first packet of a multi packet message can be forwarded before the second
one has completely arrived.
Probability
I. Probability that the frame has no error, P=(1-p)20P=(1-p)z
II. Probability of 1-bit errors, P=(201)p(1-p)19
Data layer & Transport layer
 Two features that the data link layer and transport layer have in common
 Both layers offer recovery from transmission errors.
 Provides flow control.
 Two features that the data link layer and transport layer differs :
 Data layer can be used for transmission of data while transport layer is not used for data
transmission.
 Data layer has only 2 layers while the transport layer consists of 4 layers.
OSI layers
A. Network layer
B. Transport layer
C. Transport layer

Network layer
 Connection oriented service is related to the telephone system. It includes the
connection establishment and connection termination. In connection-oriented service,
the Handshake method is used to establish the connection between sender and
receiver.
 Connection-less service is related to the postal system. It does not include any
connection establishment and connection termination. Connection less Service does not
give the guarantee of reliability. In this, Packets do not follow the same path to reach
their destination.
    '''

    # Specify the delay between keystrokes
    const_delay = 0.05

    # Call the auto_type function with the constant multi-line string and delay
    auto_type(const_text_to_type, const_delay)
