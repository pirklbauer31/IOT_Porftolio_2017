var temperature = msg.payload;
if (temperature == 5) {
    return { payload: "On" };
}
else if (temperature == 10) {
     return { payload: "Off" };
}
else {
    return null;
}