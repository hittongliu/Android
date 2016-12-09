/**
 * Created by liutong on 16/11/26.
 */
public class TvController {

    public static class poweronState implements TvState{
        public void turnUp() {
            System.out.printf("调高音量\n");
        }
        public void powerOn() {
            System.out.printf("现在打开电视机\n");

        }
        public void nextChannel() {
            System.out.printf("切换到下一个频道\n");
        }
    }

    public static class poweroffState implements TvState{
        public void turnUp() {
            System.out.printf("电视机关闭，请打开\n");
        }
        public void powerOn() {
            System.out.printf("打开电视机\n");
        }
        public void nextChannel() {
        }
    }

    private TvState mState = new poweroffState();

    public void setState(TvState tvState) {
        mState = tvState;
    }

    public void turnUp() {
        mState.turnUp();
    }

    public void powerOn() {
        mState = new poweronState();
        mState.powerOn();
    }

    public void nextChannel() {
        mState.nextChannel();
    }

    public static void main(String[] args) {
        TvController tvController = new TvController();
        tvController.turnUp();
        tvController.powerOn();
        tvController.turnUp();
        tvController.nextChannel();
    }
}
