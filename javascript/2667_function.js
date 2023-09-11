/**
 * @return {Function}
 */

const createHelloWorld = () => () => "Hello World"; 

function syntax
var createHelloWorld = function() {
    return function() {
        return "Hello World";
    }
};

//  arrow syntax
// var createHelloWorld = function() {
//     return () => "Hello World";
// };

// const f = () => {
//     const res = (...args) => "Hello World";
// }

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */
