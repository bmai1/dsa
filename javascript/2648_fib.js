/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    // yield 0;
    // yield 1;
    // yield 1;
    // const fib = [0, 1, 1];
    // let i = 3;
    // while (true) {
    //     let n = fib[i - 1] + fib[i - 2];
    //     fib.push(n), ++i;
    //     yield n;
    // }
    let a = 0, b = 1;
    while (true) {
        yield a;
        // [a, b] = [b, a + b];
        b = a + b;
        a = b - a;
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */
