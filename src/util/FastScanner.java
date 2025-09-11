package util;

import java.io.*;

public class FastScanner {
    private final BufferedInputStream in = new BufferedInputStream(System.in);
    private final byte[] buffer = new byte[1 << 16];
    private int ptr = 0, len = 0;

    private int read() throws IOException {
        if (ptr >= len) {
            len = in.read(buffer);
            ptr = 0;
            if (len <= 0) return -1;
        }
        return buffer[ptr++];
    }

    public int nextInt() throws IOException {
        int c, s = 1, x = 0;
        do c = read(); while (c <= 32);
        if (c == '-') { s = -1; c = read(); }
        while (c > 32) { x = x * 10 + (c - '0'); c = read(); }
        return x * s;
    }

    public String next() throws IOException {
        int c;
        StringBuilder sb = new StringBuilder();
        do c = read(); while (c <= 32);
        while (c > 32) { sb.append((char)c); c = read(); }
        return sb.toString();
    }
}