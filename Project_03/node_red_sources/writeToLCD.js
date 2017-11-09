//writeToLCD
var message = msg.payload;

if (message !== null) {
   msg.payload = "&&clear Temp: " + message; 
   return msg;
} else {
    return null;
}



