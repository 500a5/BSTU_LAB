import React from 'react';
import {Spin} from 'antd';
import {observer} from 'mobx-react-lite';
import collections from '../../state/collections';
import dictionaries from '../../state/dictionaries';

function WithDictionaries({names, children}) {
    React.useEffect(
        () => {
            names.map(name => dictionaries[name].fetch({}));
        },
        [
            names.map(name => collections[name].mtime)
        ]
    );

    return names.some(name => dictionaries[name].loading) ?
        (
            <div className="w-100 my-5 text-center">
                <Spin size="large" tip="Загрузка связанных сущностей" />
            </div>
        ) :
        children;
}

export default observer(WithDictionaries);
