package tw.waterballsa.designpattern.c1m1h1;

import java.util.InputMismatchException;
import java.util.List;
import java.util.Optional;
import java.util.Scanner;

import static java.lang.String.format;
import static java.util.Optional.empty;
import static java.util.Optional.of;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;
import static java.util.stream.IntStream.range;
import static tw.waterballsa.designpattern.c1m1h1.Utils.*;

/**
 * @author - johnny850807@gmail.com (Waterball)
 */
public class HumanPlayer extends Player {
    private final static Scanner in = new Scanner(System.in);

    @Override
    public void nameSelf(int order) {
        printf("Input your name (P%d): ", order);
        String name = in.next();
        if (name.isEmpty()) {
            nameSelf(order);
        } else {
            setName(name);
        }
    }

    @Override
    protected Optional<ExchangeHands> makeExchangeHandsDecision() {
        print("Would you like to perform hands exchange? (y/n): ");
        String answer = in.next().toLowerCase().trim();
        if (answer.equals("y")) {
            List<Player> players = showdown.getPlayers().stream().filter(p -> p != this).collect(toList());
            return of(selectExchangeHandsTarget(players));
        } else {
            return empty();
        }
    }

    private ExchangeHands selectExchangeHandsTarget(List<Player> players) {
        printPlayerChoices(players);
        int targetIndex = in.nextInt();
        if (targetIndex >= players.size() || targetIndex < 0) {
            return selectExchangeHandsTarget(players);
        }
        return new ExchangeHands(this, players.get(targetIndex));
    }

    private void printPlayerChoices(List<Player> players) {
        printf("Select the target %s:",
                range(0, players.size()).mapToObj(i -> format("(%d) %s", i, players.get(i).getName()))
                        .collect(joining(" ")));
    }

    @Override
    protected Card showCard() {
        printCardSelections();
        try {
            int choice = in.nextInt();
            if (choice < 0 || choice >= getHand().size()) {
                return showCard();
            }
            return getHand().show(choice);
        } catch (InputMismatchException e) {
            return showCard();
        }
    }

    private void printCardSelections() {
        println("Select the card to play (y/n): ");
        StringBuilder numbers = new StringBuilder();
        StringBuilder cards = new StringBuilder();
        for (int i = 0; i < getHand().size(); i++) {
            String cardRepresentation = getHand().get(i).toString();
            numbers.append(String.format("%"+(-cardRepresentation.length())+"s", i)).append(" ");
            cards.append(cardRepresentation).append(" ");
        }

        println(numbers.toString().stripTrailing());
        println(cards.toString().stripTrailing());
    }
}
