package fh.mc.mqtt;

public class main {

    public static void main(String[] args) {
        (new TemperatureSimulator()).start();
        (new GasSimulator()).start();
        (new SoundSimulator()).start();
    }
}
