from machine import Pin
import time

button = Pin(2, Pin.IN, Pin.PULL_UP)  # LOW when pressed, HIGH when released
led = Pin(13, Pin.OUT)

led_state = False
last_button_state = 1

while True:
    current_reading = button.value()

    # Detect falling edge (transition from unpressed 1 to pressed 0)
    if last_button_state == 1 and current_reading == 0:
        led_state = not led_state       # Toggle state
        led.value(led_state)
        time.sleep_ms(50)               # Simple software debounce delay

    last_button_state = current_reading