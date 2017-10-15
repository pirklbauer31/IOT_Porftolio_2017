# Scaling and Testing

## Scaling Issues

- Large number of devices make it hard to oversee
- Server capacity needs to be increased
- Configuration is harder with large number of devices
- network limitations (becomes unstable with more devices)
- The more devices, the more interconnectivity, increasing cost, maintenance and reliability.
- Predictive maintenance
- Windmills start vibrating, integrating a vibration sensor can predict, before one is actually failing depending on the vibrations its emitting.
- Too small subnets in combination with a Client-Server pattern might lead to too few IP addresses in an old IPv4 Network to supply every member in a network with an IP address
- Continuous integration would be "nice".

## Testing

- Simulations für single devices (unit testing)
- Automated testing scenarios
- Hardware tests
- Multiple simulators for data stress testing
- latency testing (publisher, subscriber) with timestamping
- device stress testing (lifespan test)
- corner case testing (defined by stories)

## What role will play:

- Simulator(-component)s: Faster development, limits real world scenarios, important for testing
- MQTT: 
	- Makes it easy to exchange simulators with real devices
	- Makes it possible to exchange data between simulators and real devices
- Stories:
	- Keeps track of real world while creating scenarios
	- Makes it easier for customers to understand the connection of devices / the workflow of the system
	
# Node-RED

- Start node-RED
- connect in Browser via Shown IP Address
- Create MQTT Output and Doubleclick, input Raspberry Pi address and port
- define Topic (button/b1)
- Add debug output node and connect
- Press deploy

- mqtt_send button/b1 pressed

- add output-topic
- add node change between input and flash led output topic
	- search for depressed replace with off
	- search for pressed replace with on
