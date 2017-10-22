from integriot import *

init("192.168.12.1")

def gas_cb(msg):
	if int(msg) <	900:
		buzzer.publish("set", "off")
	else:
		buzzer.publish("set", "on")

def button_cb(msg):
	if msg == "pressed":
		rgb_led.publish("set", "red")
	else:
		rgb_led.publish("set", "green")


gas_sensor = sensor("gas/gas1")
gas_sensor.add_callback_change(callback=gas_cb)

humidity_sensor = sensor("temperature/dht11/humidity")

temperature_sensor = sensor("temperature/dht11/temperature")

sound_sensor = sensor("sound/sound")

button = sensor("sound/button1")
button.add_callback_change(callback=button_cb)

buzzer = actor("gas/buzzer1")
rgb_led = actor("sound/rgb1")

run()
