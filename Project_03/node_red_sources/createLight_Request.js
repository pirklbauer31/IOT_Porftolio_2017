var light = msg.payload;

var light_last  = context.get('light_last')||0;

if (light_last === light) {
    return null;
} else {
    msg.post = light;
    context.set('light_last',light);
    return msg;
}