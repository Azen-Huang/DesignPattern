package tw.waterballsa.designpattern.c1m1h1;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * @author - johnny850807@gmail.com (Waterball)
 */
public class Hand implements Iterable<Card> {
    private final List<Card> cards = new ArrayList<>();

    public void addCard(Card card) {
        if (cards.size() >= 13) {
            throw new IllegalStateException("The hand's size must not exceed 13.");
        }
        cards.add(card);
    }

    public Card get(int index) {
        return cards.get(index);
    }

    public Card show(int index) {
        return cards.remove(index);
    }

    public int size() {
        return cards.size();
    }

    @Override
    public Iterator<Card> iterator() {
        return cards.iterator();
    }
}
