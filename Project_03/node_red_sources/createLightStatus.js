var light = msg.payload;

if (light < 300) {
    msg.payload = "ON";
    //return { payload: "ON" };
    return msg;
} else {
    msg.payload = "OFF";
    return msg;
    //return { payload: "OFF" };
}