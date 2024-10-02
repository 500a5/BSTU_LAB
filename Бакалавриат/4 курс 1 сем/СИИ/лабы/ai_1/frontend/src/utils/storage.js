export const get = (key) => {
    try {
        return JSON.parse(window.localStorage.getItem(key));
    } catch (err) {
        return null;
    }
}

export const set = (key, value) => {
    window.localStorage.setItem(key, JSON.stringify(value));
}

export const remove = (key) => {
    window.localStorage.removeItem(key);
}

export const clear = () => {
    window.localStorage.clear();
}
