package mqtt;

/**
 * Created by Pirklbauer on 11.10.2017.
 */
public class main {
    public static void main(String[] args) {
        (new TemperatureSimulator()).start();
        (new SwitchSimulator()).start();
        //(new Integrator()).start();
    }
}
