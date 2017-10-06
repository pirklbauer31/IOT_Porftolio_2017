# Who am I?

- Name: Kevin Pirklbauer
- From: Freistadt
- Programming experience
	- Java, C#, C++, C, Android, Perl, a bit of IOS development
- Micro controllers:
	- Some experience with micro controller programming, mostly from my school time at HTL
	- Arduino Atmega 2560, Foxboard, 8051 Microcontroller, Luminary micro
- Single board computers:
	- No experience.
- Part of maker community?
	- No.
- What I already know about IOT:
	- Microcontroller programming is part of it
	- Connection of different devices
- What my expectations from this class are:
	- Creating IOT systems
	- Microcontroller programming

# IOT (Slide 14)
Systems, Connectivity, Data

- Domains
	- Smart home technology
	- Transportation
	- Wearables / Mobile Computing
	- Agriculture
	- E-commerce
	- Health care
	- Logistics
	- Interior design
	- Smart cities
	- Ubiquitous/Pervasive Computing
	- Embedded Computing
	- M2m Communication (Machine 2 Machine)
	- Hacking / Making
	- Manufactoring

- Data protocols
	- Bluetooth
	- NFC
	- COAP (based on REST, for embedded devices)
- Typical devices
	- Smart home products (door locks, Bluetooth trackers)
	- Wearables (smart watches for example)
- Benefits of IOT
	- Interconnection of devices (connect everything)
	- Knowledge is power
	- Improvement of healthcare system
	- Easier tracking of products
	- Data has value
	- Improved marketing
	- Monitor multiple different devices from one point
- Challenges of IOT
	- Very complex
	- Security is an issu (sometimes of life and death)
	- Communication across devices (multiple standards, industries)
	- Migration to newer communication networks (to LTE for example)
	- Battery life
	- People don't want multiple companies for one solution
	- Who pays for IOT?
	- Developing difficult (predicting network of cities in the future hard/impossible)
	- Growth bigger than progress
- Worked with
	- Magdalena Hametner
	- Johannes Lugstein
	
# Lab Exercise 01
Setting up the Raspberry Pi.

- Edit ulnoiot.conf file on the SD card to clone
	- Change username and password (password needs at least 8 characters)
		- username: hainberger_pirklbauer
		- pw: password
	- Change IP-Adress, if not set
- Insert SD card in raspberry PI and connect via WLAN
- Start ssh tunnel via GitBash
	- ssh pi@192.168.12.1 -L 5901:localhost:5901
	- password for ssh: ulnoiot
- choose system 2
- switch to directory of clone script 
	- cd src/rpi-clone
- run clone script
	- sudo ./rpi-clone -v sda
- when prompted for a name, insert "rootfs"
- Insert cloned ssd

- Open VNC viewer (connect via gitbash before that to tunnel)
- Connect via localhost:5901
- type ssh password
- you are now connected

# Blinking

- Start Arduino IDE
- Choose Tool->Board->Wemos D1 R2 & mini
- Choose Tool->Port->usb0
- Choose File->Examples->01Basics->Blinking
- Click Upload Button

File Permission Problem occured here!

- Change permission via ssh with
	- sudo chmod -R 755 /home/pi/apps/arduino
	
# WebServer on Arduino
- Changed WiFi Webserver Example (ssid and password)

Now you can change LED status via Browser:
- to switch on: http://192.168.12.248/gpio/0
- to switch off: http://192.168.12.248/gpio/1

We first tried using the aREST API but it didn't workt out.

- Worked with: Luis Hainberger