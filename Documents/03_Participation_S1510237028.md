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
	

# Protocols

## MQTT
publish-subscribe-based "lightweight" messaging protocol for use on top of the TCP/IP protocol.

- Example:
	- A message has a topic and a payload, like the subject and the content of an e-mail.
	- Publish example: client.publish("topic/test", "Hello world!");

![text](https://www.hivemq.com/wp-content/uploads/Screen-Shot-2014-10-22-at-12.21.07.png "MQTT Example")

- Purpose: It is designed for connections with remote locations where a "small code footprint" is required or the network bandwidth is limited.

