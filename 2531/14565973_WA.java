import java.util.Scanner;

public class Main {
    static int[][] arr;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int size = scanner.nextInt();
            arr = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    arr[i][j] = scanner.nextInt();
                }
            }

            int max = (int) Math.pow(2, size) / 2;
            int mSum = 0;
            for (int n = 1; n < max; n++) {
                int value = value(n, size);
                mSum = mSum < value ? value : mSum;
            }
            System.out.println(mSum);
        }
    }

    private static int value(int n, int size) {
        int mask = 1;
//        StringBuilder builder = new StringBuilder();
        int sum = 0;
        int tmsk;
        for (int i = 0; i < size; i++) {
            if ((n & mask) != 0) {
                tmsk = mask << 1;
                for (int j = 0; j < size; j++) {
                    if ((n & tmsk) == 0) {
                        sum += arr[i][j];
                    }
                    tmsk=tmsk<<1;
                }
            }
//            builder.append((n&mask)==0?0:1).append(" ");
            mask = mask << 1;
        }
//        builder.append("sum=").append(sum);
//        System.out.println(builder.toString());
        return sum;
    }


}
