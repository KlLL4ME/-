public class BinaryStrings {
    public static void generateBinaryStrings(int n, String current) {
        // Базовый случай
        if (current.length() == n) {
            System.out.println(current);
            return;
        }
        // Рекурсивный случай
        generateBinaryStrings(n, current + "0");
        generateBinaryStrings(n, current + "1");
    }

    public static void main(String[] args) {
        int n = 3;
        System.out.println("Все бинарные строки длины " + n + ":");
        generateBinaryStrings(n, "");
    }
}
