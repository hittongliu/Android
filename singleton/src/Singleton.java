/**
 * Created by liutong on 16/11/5.
 */
public class Singleton {
    private static  Singleton instance;

    private Singleton(int a) {}

    public static synchronized Singleton getInstance(int a) {
        if (instance == null) {
            instance = new Singleton(a);
        }
        return instance;
    }

    public static void main(String args[]) {
        System.out.println("hello world!");
    }
}
