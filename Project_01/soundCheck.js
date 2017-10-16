var soundValue = msg.payload;
if (soundValue > 600) {
    return { payload: soundValue };
}
else {
    return null;
}