package javaapplication4;

/**
 *
 * @author abdulsmapara
 */
public class GreenTea {
    private double caffeine;
    private String blend;
    public double totalCaffeine;
    public GreenTea(int code) {
        if(code == 25) {
            blend = "Dragonwell";
            caffeine = 42.58;
        }
        if(code == 30) {
            blend = "Zen";
            caffeine = 29.5;
        }
    }
    public double getCaffeine() {
        return caffeine;
    }
    public String getClend() {
        return blend;
    }
    public void setCaffeine(double caffeine) {
        this.caffeine = caffeine;
    }
    public void setBlend(String blend) {
        this.blend = blend;
    }
    public void calcValues(double oz) {
        totalCaffeine = oz * caffeine;
        System.out.println("Total caffeine = " + totalCaffeine);
    }
}    
