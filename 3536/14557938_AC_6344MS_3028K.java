import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int a = scanner.nextInt();
            int l = 1, w = 1, h = a;
            for (int i = (int) Math.pow(a, 1 / 3f); i > 0; i--) {
                if (a % i == 0) {
                    int tmp = a / i;
                    for (int j = (int) Math.sqrt(tmp); j > 0; j--) {
                        if (tmp % j == 0) {
                            int c = tmp/j;
                            if (i * j + i * c + j*c < l * w + l * h + w * h) {
                                w=i;
                                h=j;
                                l=c;
                            }
                        }
                    }
                }
            }
            System.out.println(w+" "+h+" "+l);
        }
    }
}
