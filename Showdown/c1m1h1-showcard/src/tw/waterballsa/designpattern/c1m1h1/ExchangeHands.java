package tw.waterballsa.designpattern.c1m1h1;

import static tw.waterballsa.designpattern.c1m1h1.Utils.printf;

/**
 * @author - johnny850807@gmail.com (Waterball)
 */
public class ExchangeHands {
    private int countdown = 3;
    private final Player exchanger;
    private final Player exchangee;

    public ExchangeHands(Player exchanger, Player exchangee) {
        this.exchanger = exchanger;
        this.exchangee = exchangee;
        exchange();
    }

    private void exchange() {
        Hand hand = exchanger.getHand();
        exchanger.setHand(exchangee.getHand());
        exchangee.setHand(hand);
        printf("You have exchanged your hand with the player %s.\n", exchangee.getName());
    }

    public void countdown() {
        countdown--;
        if (countdown == 0) {
            exchange(); // exchange back when it's dead
        }
    }
}
