import org.junit.Test;
import static org.junit.Assert.*;

public class YatzyTest {

    @Test
    public void chance_scores_sum_of_all_dice() {
        int expected = 15;
        int actual = new Yatzy(2, 3, 4, 5, 1).ScorePerCategory().get("Chance");
        assertEquals(expected, actual);
        assertEquals(16, (int) new Yatzy(3, 3, 4, 5, 1).ScorePerCategory().get("Chance"));
    }

    @Test
    public void yatzy_scores_50() {
        int expected = 50;
        int actual = new Yatzy(4, 4, 4, 4, 4).ScorePerCategory().get("Yatzy");
        assertEquals(expected, actual);
        assertEquals(50, (int) new Yatzy(6, 6, 6, 6, 6).ScorePerCategory().get("Yatzy"));
        assertEquals(0, (int) new Yatzy(6, 6, 6, 6, 3).ScorePerCategory().get("Yatzy"));
    }

    @Test
    public void test_1s() {
        assertTrue((int) new Yatzy(1, 2, 3, 4, 5).ScorePerCategory().get("Ones") == 1);
        assertEquals(2, (int) new Yatzy(1, 2, 1, 4, 5).ScorePerCategory().get("Ones"));
        assertEquals(0, (int) new Yatzy(6, 2, 2, 4, 5).ScorePerCategory().get("Ones"));
        assertEquals(4, (int) new Yatzy(1, 2, 1, 1, 1).ScorePerCategory().get("Ones"));
    }

    @Test
    public void test_2s() {
        assertEquals(4, (int) new Yatzy(1, 2, 3, 2, 6).ScorePerCategory().get("Twos"));
        assertEquals(10, (int) new Yatzy(2, 2, 2, 2, 2).ScorePerCategory().get("Twos"));
    }

    @Test
    public void test_threes() {
        assertEquals(6, (int) new Yatzy(1, 2, 3, 2, 3).ScorePerCategory().get("Threes"));
        assertEquals(12, (int) new Yatzy(2, 3, 3, 3, 3).ScorePerCategory().get("Threes"));
    }

    @Test
    public void fours_test() {
        assertEquals(12, (int) new Yatzy(4, 4, 4, 5, 5).ScorePerCategory().get("Fours"));
        assertEquals(8, (int) new Yatzy(4, 4, 5, 5, 5).ScorePerCategory().get("Fours"));
        assertEquals(4, (int) new Yatzy(4, 5, 5, 5, 5).ScorePerCategory().get("Fours"));
    }

    @Test
    public void fives() {
        assertEquals(10, (int) new Yatzy(4, 4, 4, 5, 5).ScorePerCategory().get("Fives"));
        assertEquals(15, (int) new Yatzy(4, 4, 5, 5, 5).ScorePerCategory().get("Fives"));
        assertEquals(20, (int) new Yatzy(4, 5, 5, 5, 5).ScorePerCategory().get("Fives"));
    }

    @Test
    public void sixes_test() {
        assertEquals(0, (int) new Yatzy(4, 4, 4, 5, 5).ScorePerCategory().get("Sixes"));
        assertEquals(6, (int) new Yatzy(4, 4, 6, 5, 5).ScorePerCategory().get("Sixes"));
        assertEquals(18, (int) new Yatzy(6, 5, 6, 6, 5).ScorePerCategory().get("Sixes"));
    }

    @Test
    public void one_pair() {
        assertEquals(6, (int) new Yatzy(3, 4, 3, 5, 6).ScorePerCategory().get("Pair"));
        assertEquals(10, (int) new Yatzy(5, 3, 3, 3, 5).ScorePerCategory().get("Pair"));
        assertEquals(12, (int) new Yatzy(5, 3, 6, 6, 5).ScorePerCategory().get("Pair"));
    }

    @Test
    public void two_Pair() {
        assertEquals(16, (int) new Yatzy(3, 3, 5, 4, 5).ScorePerCategory().get("TwoPair"));
        assertEquals(16, (int) new Yatzy(3, 3, 5, 5, 5).ScorePerCategory().get("TwoPair"));
    }

    @Test
    public void three_of_a_kind() {
        assertEquals(9, (int) new Yatzy(3, 3, 3, 4, 5).ScorePerCategory().get("ThreeOfAKind"));
        assertEquals(15, (int) new Yatzy(5, 3, 5, 4, 5).ScorePerCategory().get("ThreeOfAKind"));
        assertEquals(9, (int) new Yatzy(3, 3, 3, 3, 5).ScorePerCategory().get("ThreeOfAKind"));
    }

    @Test
    public void four_of_a_knd() {
        assertEquals(12, (int) new Yatzy(3, 3, 3, 3, 5).ScorePerCategory().get("FourOfAKind"));
        assertEquals(20, (int) new Yatzy(5, 5, 5, 4, 5).ScorePerCategory().get("FourOfAKind"));
        assertEquals(9, (int) new Yatzy(3, 3, 3, 3, 3).ScorePerCategory().get("ThreeOfAKind"));
    }

    @Test
    public void smallStraight() {
        assertEquals(15, (int) new Yatzy(1, 2, 3, 4, 5).ScorePerCategory().get("SmallStraight"));
        assertEquals(15, (int) new Yatzy(2, 3, 4, 5, 1).ScorePerCategory().get("SmallStraight"));
        assertEquals(0, (int) new Yatzy(1, 2, 2, 4, 5).ScorePerCategory().get("SmallStraight"));
    }

    @Test
    public void largeStraight() {
        assertEquals(20, (int) new Yatzy(6, 2, 3, 4, 5).ScorePerCategory().get("LargeStraight"));
        assertEquals(20, (int) new Yatzy(2, 3, 4, 5, 6).ScorePerCategory().get("LargeStraight"));
        assertEquals(0, (int) new Yatzy(1, 2, 2, 4, 5).ScorePerCategory().get("LargeStraight"));
    }

    @Test
    public void fullHouse() {
        assertEquals(18, (int) new Yatzy(6, 2, 2, 2, 6).ScorePerCategory().get("FullHouse"));
        assertEquals(0, (int) new Yatzy(2, 3, 4, 5, 6).ScorePerCategory().get("FullHouse"));
    }
}
