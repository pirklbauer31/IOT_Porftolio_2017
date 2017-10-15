package mqtt;

import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttMessage;

/**
 * Created by Pirklbauer on 10.10.2017.
 */
public class TemperatureSimulator extends Thread {
    private int minTemp, maxTemp;

    public void run() {
        minTemp = 0;
        maxTemp = 10;
        int temperature = minTemp;
        try {
            MqttClient client = new MqttClient("tcp://192.168.12.1:1883", "MQTT_TemperatureSensor");

            while(true) {
                if(temperature > maxTemp) {
                    temperature = minTemp;
                }

                System.out.println(temperature);
                client.connect();
                String temperatureStr = String.valueOf(temperature);
                MqttMessage message = new MqttMessage(temperatureStr.getBytes());
                client.publish("mqtt_test/temperature1", message);

                client.disconnect();

                temperature++;

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
