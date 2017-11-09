var dist = 200;

if(msg.topic === "lighttemp/door1") {
    context.door = msg.payload;
    if(msg.payload === "closed") {
        context.detected = false;
    }
    else if(msg.payload=="open")
    {
        context.lightstate="on";
    }
    //return msg;
} else if (msg.topic === "pirmodule/distance1") {
    context.distance = msg.payload;
     if(context.door==="closed"&&context.detected===false&&(context.distance<=dist&&context.distance>=0))
    {
        context.detected=true;
        context.delay=Date.now();
        context.lightstate="on";
        return msg;
    }
    else if(context.door==="closed"&&context.detected===false&&(context.distance>dist||context.distance<0))
    {
        msg.payload = "off";
        return msg;
    }
    else if(context.door==="closed"&&context.detected===true&&(context.distance<dist&&context.distance>0))
    {
        if(context.lightstate==="off")
        {
            context.lightstate="on";
        }
        context.delay=Date.now();
    }
    else if(context.door==="closed"&&Date.now()-context.delay>10000&&(context.distance>dist||context.distance<0))
    {
        context.lightstate="off";
    }
}
msg.payload = context.lightstate;
return msg;