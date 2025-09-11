package playground;

public class TestCode {
    
}

public int fn (int n) {
    int r = n;
    for (int i = 0; i < n; i++) {
        while(n > 1)
            n /= 2;
        n = r;
    }
    return r;
}