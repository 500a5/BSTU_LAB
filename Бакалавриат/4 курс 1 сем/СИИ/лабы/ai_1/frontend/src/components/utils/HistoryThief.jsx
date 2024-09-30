import React from 'react';
import {useHistory} from 'react-router-dom';
import historyRef from '../../utils/history';

const HistoryThief = () => {
	const history = useHistory();

	React.useEffect(
		() => {
			historyRef.history = history;
		},
		[history]
	);

	return null;
};

export default HistoryThief;
