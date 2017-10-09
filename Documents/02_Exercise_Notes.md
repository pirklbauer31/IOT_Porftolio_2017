# Exercise 2
## Set up IFTTT

- Download IFTT Appllication 
- create a IFTT Webhook 
- define a event and its explaination
 (url to call created Webhook in Webhook settings)
## HTTPrequest template:
- change SSID
- change password
- change host String to maker.iftt.com
- change url String to:"/trigger/button_pressed/with/key/mfVYP1moOYQ7FaHecVCjc07785SLkHjn4GIsf9GQG8b";
- delete client.verify 7
- create a button 
## Button setup
- button pin = 14
- set pinMode to input
- digital read to read button state
- low(0) is pressed button 
## LCD setup
- download liquidchrystal i2c library
- vcc = 5V
- define sda = GPIO4, scl = GPIO5
## Teammembers
- Luis Hainberger
- Kevin Pirklbauer

# IOT-Stories
## Story 1:  (Luis Hainberger)
### The Internet of Kitchen-Things 
Steakbert McStarcook ist ein aufstrebender Sternekoch aus Hagenberg im Mühlviertel. Seit zwei Jahren betreibt er in Linz das Lokal „Fressn“, welches Platz für 70 Gäste bietet. Da er mittlerweile international als Geheimtipp unter den Gourmets gilt, benötigt Steakbert bei einem vollen Haus 40 Mitarbeiter, um den hohen Ansprüchen seines Gästekreises gerecht werden zu können.  Vor zwei Wochen hat Steakbert ein weiteres Lokal in Wien eröffnet. Das Lokal heißt „Fressn_2“ und hat die selben Dimensionen wie das „Fressn“ in Linz.  Steakbert arbeitet derzeit zwei Tage die Woche in Linz und vier Tage in Wien. Da er jedoch beide Lokale ganzwöchig betreibt und trotz des erfahrenen Küchenteams zu jederzeit an beiden Standorten präsent sein muss, bedient er sich der Küchen-komplett-Lösung „CoKit-Solution“. Jede der beiden Küchen ist in kleinere Abteilungen aufgeteilt. Die Abteilungen bestehen aus jeweils fünf Personen. An ihren Arbeitsflächen ist ein Monitor installiert, über den es Steakbert jederzeit möglich ist, per Video-Übertragung mit den jeweiligen Abteilungsleitern in Kontakt zu treten. Alle Öfen und Gargeräte in Steakberts Küchen sind mit Garraumkameras und unzähligen Sensoren ausgestattet, die ihre Daten in Echtzeit an die CoKit-Solution-App senden, von der aus Steakbert alle Gargeräte nach Belieben aus der Ferne steuern kann. Zur Arbeitsausrüstung von jedem Angestellten gehört eine Smartwatch. Die Angestellten wurden im Vorhinein von Steakbert in Kategorien eingeteilt. Jeder Posten (Abteilung) hat einen Mitarbeiter der Kategorie A, der als Abteilungsleiter agiert und jeweils zwei Mitarbeiter der Kategorien B und C. Gelangt nun eine Bestellung in der Küche ein, wird diese vom CoKit-Solution-System in ihre einzelnen Komponenten zerlegt und an die jeweiligen verantwortlichen Abteilungen gesendet. Jede dieser gesendeten Anweisungen enthält Arbeiten der Kategorie A, B und C. Jedes Postenmitglied bekommt nun eine Aufgabe, seiner Kategorie entsprechend, automatisch vom System zugewiesen. Dies geschieht über die Smartwatch, auf der die Aufgabe und die zur Verfügung stehende Zeit empfangen wird. Da ein Gericht meist aus mehreren Komponenten besteht und diese in verschiedenen Abteilungen zubereitet werden, wird die zeitliche Abhängigkeit zwischen den Abteilungen vom CoKit-Solution-System verwaltet. Wird beispielsweise ein Steak mit Beilagen und Salat bestellt, sendet das System zuerst eine Anweisung an die Fleisch-Zubereitungsabteilung und erst nach Ablauf der halben Garzeit die Anweisungen an die für Beilagen und den Salat zuständigen Abteilungen. Wenn an einem Posten eine dringende Arbeit erledigt werden muss, aber jedes Postenmitglied mit einer Aufgabe gleicher oder höherer Priorität belegt ist, teilt das System die dringende Aufgabe einem leerstehenden Mitarbeiter einer anderen Abteilung zu.  Die einzelnen Zubereitungsschritte eines Gerichtes werden dem CoKit-Solution-System von Steakbert in Form eines Zubereitungsprotokolls übergeben. In der Mitte der Küche verläuft ein Förderband, auf dem der Teller, auf dem das Gericht angerichtet wird, nach Ablauf der Vorbereitungszeit an den jeweiligen Abteilungen vorbeifährt. Dabei können die Abteilungsleiter ihre produzierten Komponenten auf dem Teller platzieren.  Am Ende des Förderbands werden die fertigen Gerichte unter eine Wärmebrücke gestellt, wo sie nach ihrer Freigabe durch Steakbert vom Service Personal zu den Gästen gebracht werden. In der Wärmebrücke ist eine hochauflösende Kamera integriert, die es Steakbert ermöglicht, vor dem Hinausschicken eines fertigen Gerichtes, noch einmal einen Blick darauf werfen zu können. Die in der Kamera integrierten Filter bieten ihm zudem eine bessere Möglichkeit, Verunreinigungen auf den Tellern zu erkennen. Ist ein Teller verschmutzt, sendet Steakbert eine Reinigungsanweisung für den betroffenen Teller an das System, welches die Anweisung an ein zur Verfügung stehendes Mitglied der Anrichte-Abteilung vermittelt.

## Story 2: (Kevin Pirklbauer)
Das Versandunternehmen "SpeedDelivery" möchte die Paketverfolgung seiner Produkte
verbessern. Dafür werden die Lieferfahrzeuge mit GPS fähigen Geräten ausgestattet. 
Lieferanten sollen mit diesen Geräten spezielle Codes der Pakete scannen um sie 
für das Lieferfahrzeug zu registrieren. 

Das Unternehmen hat nun die Möglichkeit, über eine bereitgestellte Software die 
aktuellen Positionen der Lieferfahrzeuge und außerdem die registrierten Pakete
zu erfassen. Für Kunden steht eine Mobile App zur Vefügung, über die sie die aktuelle
Position ihrer Bestellung erfassen können. Abhängig von dieser Position lässt sich noch
die voraussichtliche verbleibende Lieferzeit bestimmen.

Falls ein Wechsel des Lieferfahrzeuges während der Lieferung geplant ist und es sich dabei
um ein Unternehmensfremdes Fahrzeug (Schiff, Flugzeug) handelt, werden die Pakete zusätzlich
mit GPS Trackern ausgestattet. Ein Wechsel des Lieferfahrzeuges wird als Meilenstein
in der Lieferung festgelegt. Wird nun einer dieser Meilensteine erreicht, wird der Benutzer
in seiner App benachrichtigt und die aktuell berechnete Restlieferzeit mitgeteilt.
Sollte nur mit Unternehmens-Lieferfarhzeugen geliefert werden, wird der Benutzer stattdessen an mehreren
Punkten des erreichten Wegs benachrichtigt (z.B. 50%, 80% des Weges zurückgelegt).

Zusätzlich werden die Pakete mit Sensoren ausgestattet, um festzustellen, ob das Paket noch unbeschädigt ist.
Wird das Paket nun beschädigt, wird das Unternehmen benachrichtigt, um entsprechende Schritte zu unternehmen
und festzustellen, wer vermutlich für die Beschädigung des Paketes verantwortlich ist.

Bei Erhalt des Paketes, kann der Benutzer in der Mobile App bewerten, wie zufrieden er mit dem Lieferprozess war.