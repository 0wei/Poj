import java.util.Scanner;

/**
 * Created by Luo on 2016/1/31.
 * poj - 1979
 */
public class Main {
    public static int TOP = 1;
    public static int DOWN = 2;
    public static int LEFT = 3;
    public static int RIGHT = 4;

    public static char[][] maps = new char[20][20];
    private static int w;
    private static int h;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while ((w = scanner.nextInt()) != 0 && (h = scanner.nextInt()) != 0) {
            int xx = 0;
            int yy = 0;
            for (int y = 0; y < h; y++) {
                String next = scanner.next();
                for (int x = 0; x < w; x++) {
                    maps[y][x] = next.charAt(x);
                    if (maps[y][x] == '@') {
                        xx = x;
                        yy = y;
                    }
                }

            }
            System.out.println("" + point(xx, yy/*, -1*/));

        }
    }


    static int point(int x, int y/*, int from*/) {
        if ((x < 0 || x >= w) || (y < 0 || y >= h) /*|| maps[y].charAt(x) == '#'*/) return 0;
        char c = maps[y][x];
        if (c == '#') return 0;
        maps[y][x]='#';
        return 1+point(x-1,y)+point(x+1,y)+point(x,y-1)+point(x,y+1);
//        int right = from == LEFT ? 0 : point(x + 1, y, RIGHT);
//        int left = from == RIGHT ? 0 : point(x - 1, y, LEFT);
//        int top = from == DOWN ? 0 : point(x, y - 1, TOP);
//        int down = from == TOP ? 0 : point(x, y + 1, DOWN);
//        int i = 1 + right + top + left + down;
//        return i;
    }
}
