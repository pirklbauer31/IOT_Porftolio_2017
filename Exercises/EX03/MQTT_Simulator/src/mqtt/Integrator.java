package mqtt;

import org.eclipse.paho.client.mqttv3.*;

/**
 * Created by Pirklbauer on 11.10.2017.
 */
public class Integrator extends Thread {

    @Override
    public void run() {
        MqttClient client;
        try {
            client = new MqttClient(
                    "tcp://192.168.12.1:1883", "MQTT_Integrator");
            client.setCallback(new MqttCallback() {
                @Override
                public void connectionLost(Throwable throwable) {
                }

                @Override
                public void messageArrived(String t, MqttMessage m) throws Exception {
                    String tempMessage = (new String(m.getPayload()));
                    int temperature = Integer.parseInt(tempMessage);

                    if(temperature == 5) {
                        MqttMessage message = new MqttMessage("switch".getBytes());
                        client.publish("mqtt_test/switch1", message);
                    }
                }

                @Override
                public void deliveryComplete(IMqttDeliveryToken t) {
                }
            });

            client.connect();

            client.subscribe("mqtt_test/temperature1");

        } catch (MqttException e) {
            e.printStackTrace();

        }
    }
}
