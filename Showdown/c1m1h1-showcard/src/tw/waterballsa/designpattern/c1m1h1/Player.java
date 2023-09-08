package tw.waterballsa.designpattern.c1m1h1;

import java.util.Optional;

import static java.util.Objects.requireNonNull;
import static java.util.Optional.empty;
import static java.util.Optional.ofNullable;

/**
 * @author - johnny850807@gmail.com (Waterball)
 */
public abstract class Player {
    protected int point;
    protected Showdown showdown;
    private String name;
    private Hand hand = new Hand();
    private ExchangeHands exchangeHands;

    protected TurnMove takeTurn() {
        TurnMove turnMove = new TurnMove(this, hasUsedExchangeHands() ?
                empty() : makeExchangeHandsDecision(), showCard());
        turnMove.getExchangeHands().ifPresent(this::setExchangeHands);
        getExchangeHands().ifPresent(ExchangeHands::countdown);
        return turnMove;
    }

    public abstract void nameSelf(int order);

    protected abstract Optional<ExchangeHands> makeExchangeHandsDecision();

    protected abstract Card showCard();

    public void setShowdown(Showdown showdown) {
        this.showdown = showdown;
    }

    public void addHandCard(Card card) {
        hand.addCard(card);
    }

    public void setName(String name) {
        this.name = requireNonNull(name);
    }

    public void gainPoint() {
        point++;
    }

    public void setExchangeHands(ExchangeHands exchangeHands) {
        this.exchangeHands = exchangeHands;
    }

    public boolean hasUsedExchangeHands() {
        return exchangeHands != null;
    }

    public Optional<ExchangeHands> getExchangeHands() {
        return ofNullable(exchangeHands);
    }

    public Hand getHand() {
        return hand;
    }

    public String getName() {
        return name;
    }

    public void setHand(Hand hand) {
        this.hand = requireNonNull(hand);
    }

    public int getPoint() {
        return point;
    }
}