package mqtt;

import org.eclipse.paho.client.mqttv3.*;

/**
 * Created by Pirklbauer on 11.10.2017.
 */
public class SwitchSimulator extends Thread {

    public void run() {
        MqttClient client;
        try {
            client = new MqttClient(
                    "tcp://192.168.12.1:1883", "MQTT_Switch");
        client.setCallback(new MqttCallback() {
            @Override
            public void connectionLost(Throwable throwable) { }

            @Override
            public void messageArrived(String t, MqttMessage m) throws Exception {
                System.out.println(new String(m.getPayload()));
            }

            @Override
            public void deliveryComplete(IMqttDeliveryToken t) { }
        });

        client.connect();

        client.subscribe("mqtt_test/switch1");

        } catch (MqttException e) {
            e.printStackTrace();
        }
    }

}
