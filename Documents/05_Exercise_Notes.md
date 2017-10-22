# Exercise 5

- connect via SSH
- cd ulnoiot
- git pull
- fix_bin
- ulnoiot upgrade
- copy lib/system_template to folder (for example: ~/Projects/Project_01)
	- cp -r lib/system_template ~/Projects/Project_01
	
- copy node_template for new node
	- cp -r node_template display
- cd display
- remove key.hex
- initialize
- console_serial
- help
- help(display44780)
- d=display44780("display1", d3,d4)
- now you can issue commands: (if there's text on the display)
	- d.clear() (delete Display Text)
	- d.print("Hello") (write Text)
- exit with STRG+ALTGR+]

- Temperature_Sensor dht11
- copy node_template
- initialize
- console_serial
- t=dht11("dht11", d3, on_change="None")

# Project 1 Update

- update Wifi configs in Project_01/system.conf

- connect WEMOS with Temperature_Sensor
- flash with initialize
- open autostart.py in /files
- add device 
	- dht11("dht11",d3,on_change="None")
- uncomment run()
- deploy changes
	- call deploy in node folder
- after that, the sensor should publish (check wiht mqtt_all in other terminal)

- analog("sound", precision=10, threshold=None)

- config rest of the sensors:
- pink cable:
	- humidity sensor
- orange cable:
	- sound sensor
	- button
	- rgb led
- grey cable:
	- gas sensor
	- buzzer
- Program integrator with integriot (run.py - file)
- run the integrator
	python3 run.py
	
Configurations can be found in the autostart.py files of the nodes.

