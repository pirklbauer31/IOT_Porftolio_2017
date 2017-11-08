# IoT Maintenance

## Predictive Maintenance

- What is it?
	- Predictive maintenance (PdM) techniques are designed to help determine the condition of in-service equipment in order to predict when maintenance should be performed. 
- What problems does it solve?
	- Tries to eliminiate "unplanned stops" to replace with "planned stops"
	- Tries to reduce maintenance costs
- How is it related to the IoT?
	- For Predictive Maintenance, equipment condition is constanly monitored, this meshes well with IoT (multiple devices need monitoring).
- Examples:
	- Industrial Manufacturing
	- Conumer Packages & Goods
	- Healthcare
- Which role does data analytics play?
	- Failure Data helps in predictive monitoring

## Heartbeat Monitoring of Network Nodes

- How does a heartbeat monitor in a network work?
	- It pings a device and expects a response ("heartbeat"). 
- What can it be used for?
	- To check if a sensor / device is still active
- What can be secured in an IoT system with this type of monitoring?
	- That inactive sensors can immediatly be found
- What feature in ulnoiot already supports hearbeats?
	- MQTT can be used to realize heartbeats
- Is this predictive maintenance (or what would need to be added)
	- No, since it only sees, if a system is still active and does not predict anything
	- Use backup nodes, when node fails