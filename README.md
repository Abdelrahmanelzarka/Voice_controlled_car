# Voice_controlled_car

### Hardware-components
### A small car kit with two large wheels and one free wheel - Arduino UNO - a small breadboard - HC05 bluetooth module - 2 ultrasonic sensor modules - MPU6050 Gyro accelerator sensor - H-bridge motor driver 

We controlled a car by speaking into microphone and say some commands like "Forward", "Backward", "Left", "Right", "Stop"
We used **Speech_recongintion_model** which is connecting to **google API** to understand what we say and print it on laptop "speech to text"
After that we send signal to **"HC-05" Bluetooth module** connected to **Arduino UNO and H-bridge motor driver** to control the speed of wheels.
also we used **two ultra-sonic sensor modules** to measure the distances front and behind the car to make it slow down the speed at distance < 80 and stop at distance <20
we also use **MPU6050 Gyro-accelerator sensor** to measure the angle of speed and detect if car rotate left or right which helps us to develop a **PID algorithem** to make the car correct itself and go forward smothely.

#how to test code
clone this repo into your machine
makesure to connect wires into thier corresponding pins at arduino
upload ardunio code to the arduino
run the program.py code on your machine and make sure the connection of HC05 is right to make it discoverable to laptop
after connect with laptop try to say some commands and enjoy your car being your  **obedient_robot**
