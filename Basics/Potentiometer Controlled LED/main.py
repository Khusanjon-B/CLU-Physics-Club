from machine import Pin, ADC, PWM
import time

# Initialize ADC pin
pot = ADC(Pin(26))

# Initialize PWM on LED pin (default frequency 1000 Hz)
led = PWM(Pin(15))
led.freq(1000)

while True:
    # Read 16-bit ADC value (0 to 65535)
    pot_value = pot.read_u16()

    # Apply directly to 16-bit PWM duty cycle
    led.duty_u16(pot_value)

    # Debug output
    print(f"Raw: {pot_value} \t Duty: {pot_value}")

    time.sleep_ms(50)  # Small stability pause