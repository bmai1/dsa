Array.prototype.last = function() {
    // return this.length ? this[this.length - 1] : -1;
    return this[this.length - 1] ?? -1; // nullish coalescing operator
    // if (this === undefined || this.length == 0 ) { return -1; }
    // return this.slice(-1);
    // return this[this.length - 1];
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */
