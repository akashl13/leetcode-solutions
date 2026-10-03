var checkIfInstanceOf = function(obj, classFunction) {
    if (obj === null || obj === undefined) {
        return false;
    }

    if (typeof classFunction !== "function") {
        return false;
    }

    // Primitive values like 5 need to be converted
    // to their wrapper objects: Number, String, Boolean, etc.
    let current = Object(obj);

    while (current !== null) {
        if (current.constructor === classFunction) {
            return true;
        }

        current = Object.getPrototypeOf(current);
    }

    return false;
};