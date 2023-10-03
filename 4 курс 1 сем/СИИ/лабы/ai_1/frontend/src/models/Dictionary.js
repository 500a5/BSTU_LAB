import * as mobx from 'mobx';
import _ from 'lodash';
import List from './List';

class Dictionary extends List
{
    constructor(...args)
    {
        super(...args);

        mobx.makeObservable(this, {
            map: mobx.computed
        })
    }

    get map()
    {
        return _.keyBy(this.data, 'id');
    }

    filter = (func) => {
        if (this.data !== null) {
            let a = [...this.data]
            a = a.filter((item) => func(item))
            return a
        }
        return null
    }
}

export default Dictionary;
