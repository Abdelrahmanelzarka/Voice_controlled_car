# Voice_controlled_car

### Hardware-components
### ( A small car kit with two large wheels and one free wheel - Arduino UNO - a small breadboard - HC05 Bluetooth module - 2 ultrasonic sensor modules - MPU6050 Gyro accelerator sensor - H-bridge motor driver ) 
********************
We controlled the car by speaking into a microphone and saying some commands like "Forward", "Backward", "Left", "Right", "Stop"

We used **Speech_recongintion_model** which is connecting to **Google API** to understand what we say and print it on a laptop "speech to text"

After that, we send a signal to **"HC-05" Bluetooth module** connected to **Arduino UNO and H-bridge motor driver** to control the speed of the wheels.

also, we used **two ultra-sonic sensor modules** to measure the distances (front and behind) of the car to make it slow down the speed at distance < 80 and stop at distance <20

we also use an **MPU6050 Gyro-accelerator sensor** to measure the angle of speed and detect if the car rotates left or right which helps us to develop a **PID algorithm** to make the car correct itself and go forward smoothly.
*****************************
## How to test code
1- Clone this repo into your machine

2- Make sure to connect wires to thier corresponding pins at Arduino

3- Upload Arduino code to the Arduino

4- Make sure to install speech_recognition and pybluez with VS code and to download wire and software serial library with Arduino

5- Run the program.py code on your machine and make sure the connection of HC05 is right to make it discoverable on laptop

6- After connecting with laptop try to say some commands and enjoy your car being your  **obedient_robot**


### Watch the trial video here : 
https://www.linkedin.com/posts/abdelrahman-elzarka-software-engineer_github-project-technology-activity-7070367502941233153-amHx?utm_source=share&utm_medium=member_desktop
