# Scaling and Testing

## Scaling Issues

- Large number of devices make it hard to oversee
- Server capacity needs to be increased
- Configuration is harder with large number of devices
- network limitations (becomes unstable with more devices)
- The more devices, the more interconnectivity, increasing cost, maintenance and reliability.

## Testing

- Simulations für single devices (unit testing)
- Automated testing scenarios
- Hardware tests

## What role will play:

- Simulator(-component)s: Faster development, limits real world scenarios, important for testing
- MQTT: 
	- Makes it easy to exchange simulators with real devices
	- Makes it possible to exchange data between simulators and real devices
- Stories:
	- Keeps track of real world while creating scenarios
	- Makes it easier for customers to understand the connection of devices / the workflow of the system
	
# IoT Frameworks

## Node-RED

- Title:
- Is Open Source, available on GitHub
- Easy to install
- Good documentation, cookbook examples, userguide, api description, blogposts
- Devices / Operating Systems (wherever Node.js runs)
	- Raspberry Pi
	- BeagleBone Black
	- Arduino
	- Android
	- IBM Bluemix
	- SenseTecnic FRED
	- Amazon Web Services
	- Microsoft Azure
- Mass deployment/maintainance: 
- Security/privacy: No standard security, needs to be implemented (there are examples in the cookbook)