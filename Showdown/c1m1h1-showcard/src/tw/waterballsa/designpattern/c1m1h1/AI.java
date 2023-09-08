package tw.waterballsa.designpattern.c1m1h1;

import java.util.List;
import java.util.Optional;
import java.util.Random;

import static java.lang.String.format;
import static java.util.Optional.empty;
import static java.util.Optional.of;

/**
 * @author - johnny850807@gmail.com (Waterball)
 */
public class AI extends Player {
    private static final Random random = new Random();

    @Override
    public void nameSelf(int order) {
        setName(format("AI-%d", order));
    }

    @Override
    protected Optional<ExchangeHands> makeExchangeHandsDecision() {
        if (hasUsedExchangeHands()) {
            return empty();
        }
        return random.nextBoolean() ? empty() : of(randomlyExchangeHands());
    }

    private ExchangeHands randomlyExchangeHands() {
        List<Player> players = showdown.getPlayers();
        return new ExchangeHands(this, players.get(random.nextInt(players.size())));
    }

    @Override
    protected Card showCard() {
        if (getHand().size() == 1) {
            return getHand().get(0);
        }
        return getHand().show(random.nextInt(getHand().size()));
    }

    public void setShowdown(Showdown showdown) {
        this.showdown = showdown;
    }
}
