/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    // const obj = class {
    //     constructor() { this.val = init; }
    //     increment() { return ++this.val; }
    //     decrement() { return --this.val; }
    //     reset() { 
    //         this.val = init;
    //         return this.val; 
    //     }
    // };
    // return new obj;

    const obj = {
        val: init,
        increment: function() { return ++this.val; },
        decrement: function() { return --this.val; },
        reset: function() { return this.val = init }
    }
    return obj;
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
