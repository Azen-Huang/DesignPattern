package tw.waterballsa.designpattern.c1m1h1;

import java.util.Optional;

/**
 * @author - johnny850807@gmail.com (Waterball)
 */
@SuppressWarnings("OptionalUsedAsFieldOrParameterType")
public class TurnMove {
    private final Player player;
    private final Optional<ExchangeHands> exchangeHands;
    private final Card showCard;

    public TurnMove(Player player, Optional<ExchangeHands> exchangeHands, Card showCard) {
        this.player = player;
        this.exchangeHands = exchangeHands;
        this.showCard = showCard;
    }

    public Optional<ExchangeHands> getExchangeHands() {
        return exchangeHands;
    }

    public Player getPlayer() {
        return player;
    }

    public Card getShowCard() {
        return showCard;
    }
}
