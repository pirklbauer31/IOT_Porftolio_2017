package fh.mc.mqtt;

import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttMessage;

public class SoundSimulator extends Thread {
    private int minSound, maxSound;

    public void run() {
        minSound = 0;
        maxSound = 700;
        int sound = minSound;
        try {
            MqttClient client = new MqttClient("tcp://192.168.12.1:1883", "MQTT_SoundSensor1");

            while(true) {
                if(sound > maxSound) {
                    sound = minSound;
                }

                System.out.println(sound);
                client.connect();
                String soundStr = String.valueOf(sound);
                MqttMessage message = new MqttMessage(soundStr.getBytes());
                client.publish("heater/sound1", message);

                client.disconnect();

                sound += 50;

                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

        } catch (MqttException e) {
            e.printStackTrace();
        }


    }

}
