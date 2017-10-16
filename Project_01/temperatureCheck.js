var temperature = msg.payload;
if (temperature >= 100) {
    return { payload: temperature };
}
else {
    return null;
}