#requires micropython-servo library
import time
from servo import Servo

# Create our Servo object, assigning the
# GPIO pin connected the PWM wire of the servo
my_servo = Servo(pin_id=16)

for i in range(5):
    
    my_servo.write(180)  # Set the Servo to the right most position
    time.sleep_ms(1000)  # Wait for 1 second 
    
    my_servo.write(80)  # Set the Servo to the left most position
    time.sleep_ms(1000)  # Wait for 1 second
    