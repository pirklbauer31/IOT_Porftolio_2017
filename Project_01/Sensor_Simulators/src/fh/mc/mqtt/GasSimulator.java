package fh.mc.mqtt;


import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttMessage;

public class GasSimulator extends Thread {

    public void run() {
        boolean gaswarning = true;
        try {
            MqttClient client = new MqttClient("tcp://192.168.12.1:1883", "MQTT_GasSensor");

            while(true) {
                client.connect();

                if (gaswarning) {
                    MqttMessage message = new MqttMessage("on".getBytes());
                    client.publish("heater/gaswarning", message);
                    gaswarning = false;
                }

                else {
                    MqttMessage message = new MqttMessage("off".getBytes());
                    client.publish("heater/gaswarning", message);
                    gaswarning = true;
                }

                client.disconnect();

                try {
                    Thread.sleep(10000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

        } catch (MqttException e) {
            e.printStackTrace();
        }


    }
}
