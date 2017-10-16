package fh.mc.mqtt;

import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttMessage;

public class TemperatureSimulator extends Thread {
    private int minTemp, maxTemp;

    public void run() {
        minTemp = 50;
        maxTemp = 100;
        int temperature = minTemp;
        try {
            MqttClient client = new MqttClient("tcp://192.168.12.1:1883", "MQTT_TemperatureSensor1");

            while(true) {
                if(temperature > maxTemp) {
                    temperature = minTemp;
                }

                System.out.println(temperature);
                client.connect();
                String temperatureStr = String.valueOf(temperature);
                MqttMessage message = new MqttMessage(temperatureStr.getBytes());
                client.publish("heater/temperature1", message);

                client.disconnect();

                temperature += 10;

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
