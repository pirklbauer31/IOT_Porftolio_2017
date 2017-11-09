var temperature = Math.round(msg.payload*10)/10;
var curr_time = Date.now();

// initialise the counter to 0 if it doesn't exist already
var temperature_last  = context.get('temp_last')||0;
var temp_diff = temperature - temperature_last;
var time_last = context.get('time_last')||0;

if(temp_diff > 0.5||temp_diff<-0.5||curr_time-time_last > 30000) {
    // store the value back
    context.set('temp_last',temperature);
    context.set('time_last',curr_time)
    msg.post = temperature;
    msg.payload = temperature;
    
    return msg;
}  else {
    //msg.post=curr_time-time_last;
    //return msg;
    return null;
}