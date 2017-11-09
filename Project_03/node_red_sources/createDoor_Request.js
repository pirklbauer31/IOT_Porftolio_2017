var door = msg.payload;

var door_last  = context.get('door_last')||0;

if (door_last === door) {
    return null;
} else {
    msg.post = door;
    context.set('door_last',door);
    return msg;
}