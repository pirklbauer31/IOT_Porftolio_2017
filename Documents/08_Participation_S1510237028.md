# LORA
Low Power Wide Area Network = LPWAN

- What is the relation bandwidth/range/power?
	- High bandwidth for more devices and lower required power
	- Low bandwidth mostly means higher range
- What is the Link budget?
	- Budget for Connection between Sender and Receiver
	- Dependand on distance, obstacles, reflections
	- Can be amplified by amplifiers or different antennas
	- If budget is used up, only noise is created
- What is the community approach?
	- The things Network
	- Comunity builds LORA Gateways all over the world
	-"Everyone" can build his own Gateway and add it
- What are benefits with LORA?
	- High range
	- High link budget
	- Low Power consumption
- what are problems with LORA?
	- Very low bandwidth
	- If there's no community gateway near, you need a commercial one or build your own
	
## LORA (After Movie)

Google link budget again:
- what is it exactly , find examples
	- is a type of wireless telecommunication wide area network designed to allow long range communications at a low bit rate among things (connected objects), such as sensors operated on a battery.
	- https://www.hackster.io/idreams/getting-started-with-lora-fd69d1
	- https://docs.mbed.com/docs/lora-with-mbed/en/latest/intro-to-lora/
- Google "radio link budget calculator"
	- Lora: 1500km, 0 dBi Antenna Gain, 0.8 GHz, 40 mm/h Rainrate = -162.6 dBm Received Power
	- Lora: 4000km, 20 dBi Antenna Gain, 0.8 GHz, 40 mm/h Rainrate = -142.6 dBm Received Power
- Google: LORA in Austria and Linz.
	– There's a "The Things Network Vienna"
		- 7 Gateways
		- 22 Contributors
		- Established 10/16
	- LoRaWAN, developed by kapsch, Microtonics and ORS comm
- Discuss with neighbor:
	- What is Lora good for, what might it be bad at?
		- Transfering sensor data that is not needed in real time. E.g. hydration value of fields for farmers
	- Advantages
		- Low Power
		- High Range
	- Disadvantages
		- Low Bandwidth
	- How does it fit into IoT?
		- We need Low power and long range in IoT
	
## TTN
