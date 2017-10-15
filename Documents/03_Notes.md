# Exchange Formats in IOT

## XML
Extensible Markup Language.
Keys always known for Values.

- Readability: Easiliy human readable, machine readable
- Speed: Fast at certain uses
- User-friendliness: Easy to use

- Example:
	```xml
	<?xml version="1.0"?>
	<catalog>
	   <book id="bk101">
		  <author>Gambardella, Matthew</author>
		  <title>XML Developer's Guide</title>
		  <genre>Computer</genre>
		  <price>44.95</price>
		  <publish_date>2000-10-01</publish_date>
		  <description>An in-depth look at creating applications 
		  with XML.</description>
	   </book>
	</catalog>
	```
		
## JSON
Similar to XML.

- Readability: Easiliy human readable, machine readable
- Speed: Depends on the use case
- User-friendliness: Easy to use

- Examples:
	```json
	{
	  "squadName": "Super hero squad",
	  "homeTown": "Metro City",
	  "formed": 2016,
	  "secretBase": "Super tower",
	  "active": true,
	  "members": [
		{
		  "name": "Molecule Man",
		  "age": 29,
		  "secretIdentity": "Dan Jukes",
		  "powers": [
			"Radiation resistance",
			"Turning tiny",
			"Radiation blast"
		  ]
		},
		{
		  "name": "Madame Uppercut",
		  "age": 39,
		  "secretIdentity": "Jane Wilson",
		  "powers": [
			"Million tonne punch",
			"Damage resistance",
			"Superhuman reflexes"
		  ]
		},
		{
		  "name": "Eternal Flame",
		  "age": 1000000,
		  "secretIdentity": "Unknown",
		  "powers": [
			"Immortality",
			"Heat Immunity",
			"Inferno",
			"Teleportation",
			"Interdimensional travel"
		  ]
		}
	  ]
	}
	```
	
## Rest of Formats	

# Consortiums / Foundations / Alliances

## OCF
- Title: Open Connectivity Foundation
- Notable Members:
	- Intel (founder)
	- Microsoft
	- LG
	- Samsung (founder)
	- Qualcomm
- Purpose: Develops standards for IoT, Product certfications
- Cost / access to consortium (for becoming a member):
	- Basic (annual 0$) - Diamond (annual 350.000$)
	
## AllSeen Alliance
- Title: AllJoyn is an open source software framework that makes it easy for devices and apps to discover and communicate with each other.
- Notable Members:
	- Microsoft
	- LG
	- Qualcomm
- Purpose: The AllSeen Alliance is dedicated to the widespread adoption of products, systems and services that support the Internet of Things with AllJoyn®, a universal development framework.

## ThreadGroup
- Notable Members:
	- ARM (founder)
	- Samsung (founder)
	- Nest (founder)
- Purpose: 
	- Connect and control IoT devices at home.
	- Providing a Thread which connects all devices at home.
- Cost: 0$ - 100.000$
- Features:
	- Simple for consumers to use
	- Always secure
	- Power-efficient
	- An open protocol that carries IPv6 natively
	- Based on a robust mesh network with no single point of failure
	- Runs over standard 802.15.4 radios
	- Designed to support a wide variety of products for the home: appliances, access control, climate control, energy management, lighting, safety, and security
	

## IIC

- Title: Industrial Internet Consortium
- Notable Members: Intel, IBM, GE, Cisco, AT&T (founded in 2014) and Bosch, Huawei, SAP
- Purpose: setting the architectural framework for industrial IoT - making it easier to adopt interconnected machines and intelligent analysis.
- Cost: from $2500 to $150.000 in six levels of membership

# Protocols

## CoAP
REST over UDP

- Example:
- Purpose: Latency lower than HTTP
- Software support: