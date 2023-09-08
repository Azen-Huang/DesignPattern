package tw.waterballsa.designpattern.c1m1h1;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

import static java.util.Collections.max;
import static java.util.Comparator.comparing;
import static java.util.Comparator.comparingInt;
import static java.util.stream.Collectors.joining;
import static tw.waterballsa.designpattern.c1m1h1.Utils.print;
import static tw.waterballsa.designpattern.c1m1h1.Utils.println;
import static tw.waterballsa.designpattern.c1m1h1.Utils.printf;

/**
 * @author - johnny850807@gmail.com (Waterball)
 */
public class Showdown {
    public static final int NUM_OF_ROUNDS = 13;
    private final Deck deck;
    private final List<Player> players;
    private final List<TurnMove> turnMoves = new ArrayList<>();

    public Showdown(Deck deck, List<Player> players) {
        this.deck = deck;
        this.players = players;
        players.forEach(p -> p.setShowdown(this));
    }

    public void start() {
        nameThemselves();
        deck.shuffle();
        drawHands();
        playRounds();
        gameOver();
    }

    private void nameThemselves() {
        for (int i = 0; i < players.size(); i++) {
            players.get(i).nameSelf(i + 1);
        }
    }

    private void drawHands() {
        int deckSize = deck.size();
        for (int i = 0; i < deckSize; i++) {
            Card card = deck.draw();
            players.get(i % players.size()).addHandCard(card);
        }
    }

    private void playRounds() {
        for (int i = 0; i < NUM_OF_ROUNDS; i++) {
            players.forEach(this::takeTurn);
            showdown();
            turnMoves.clear();
        }
    }

    private void takeTurn(Player player) {
        printf("It's %s's turn.\n", player.getName());
        TurnMove turnMove = player.takeTurn();
        turnMoves.add(turnMove);
    }

    private void showdown() {
        printShowCards();
        TurnMove winnerTurnMove = max(turnMoves, comparing(TurnMove::getShowCard));
        Player winner = winnerTurnMove.getPlayer();
        winner.gainPoint();
        printf("%s wins this round.\n", winner.getName());
    }

    private void printShowCards() {
        print("Show cards: ");
        println(turnMoves.stream()
                .map(TurnMove::getShowCard)
                .map(Objects::toString).collect(joining(" ")));
    }

    private void gameOver() {
        Player winner = max(players, comparingInt(Player::getPoint));
        printf("The winner is %s.\n", winner.getName());
    }

    public List<Player> getPlayers() {
        return players;
    }
}
