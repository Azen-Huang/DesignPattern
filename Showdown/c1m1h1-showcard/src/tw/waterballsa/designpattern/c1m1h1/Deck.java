package tw.waterballsa.designpattern.c1m1h1;

import java.util.Collections;
import java.util.Stack;

/**
 * @author - johnny850807@gmail.com (Waterball)
 */
public class Deck {
    private final Stack<Card> cardStack = new Stack<>();

    public static Deck standard52Cards() {
        Deck deck = new Deck();
        Card.Suit[] suits = Card.Suit.values();
        Card.Rank[] ranks = Card.Rank.values();
        for (Card.Suit suit : suits) {
            for (Card.Rank rank : ranks) {
                deck.push(new Card(suit, rank));
            }
        }
        return deck;
    }

    public void push(Card card) {
        cardStack.push(card);
    }

    public Card draw() {
        return cardStack.pop();
    }

    public void shuffle() {
        Collections.shuffle(cardStack);
    }

    public int size() {
        return cardStack.size();
    }
}
