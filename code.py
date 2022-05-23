# This will add LED functionality to the V5 brain
# An Adafruit Gemma M0 is required, along with any neopixel lights you desire
# Gemma M0 runs off of 5V power, not 12V
# According to the game manual, page C5, section VUR10, neopixel lights are allowed on the robot

# Save this file as "code.py" on the Gemma M0
# Install Circuitpython library in VSCode
# This file does not need to be added to the V5, only to the Gemma

# Only standard Neopixel lights will work with this setup
# Once you have selected a light strip, change your num_pix to the number of LED lights you have
# Connect DOut to DOut, D1 to D1, and Vcc to VIn
# You can use either the JST connector or the USB connector for power

from ast import AsyncFunctionDef
import board
import neopixel

try:
    import urandom as random  # for v1.0 API support
except ImportError:
    import random

num_pix = 17  # Number of NeoPixels
pix_pin = board.D1  # Pin where NeoPixels are connected
strip = neopixel.NeoPixel(pix_pin, num_pix)

min_alpha = 0.1  # Minimum brightness
max_alpha = 0.4  # Maximum brightness, change up to 1.0 if you want it brighter
alpha = (min_alpha + max_alpha) / 2  # Start in middle
alpha_delta = 0.01  # Amount to change brightness each time through loop
alpha_up = True  # If True, brightness increasing, else decreasing

strip.fill([0, 0, 255])  # Fill blue, or change to R,G,B of your liking

while True:  # Loop forever...
    if random.randint(1, 5) == 5:  # 1-in-5 random chance
        alpha_up = not alpha_up  # reverse direction
    if alpha_up:  # Increasing brightness
        alpha += alpha_delta  # Add some amount
        if alpha >= max_alpha:  # At or above max
            alpha = max_alpha  # Limit to max
            alpha_up = False  # and switch direction
    else:  # Else decreasing brightness
        alpha -= alpha_delta  # Subtract some amount
        if alpha <= min_alpha:  # At or below min
            alpha = min_alpha  # Limit to min
            alpha_up = True  # and switch direction

    strip.brightness = alpha  # Set brightness to 0.0 to 1.0
    strip.write()  # issue data to LED strip