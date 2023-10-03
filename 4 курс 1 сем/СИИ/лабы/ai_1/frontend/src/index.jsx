import React from 'react';
import ReactDOM from 'react-dom';
import Screens from './screens';
import ErrorBoundary from './components/utils/ErrorBoundary';

import './styles/index.less';

ReactDOM.render(
	<React.StrictMode>
		<ErrorBoundary>
			<Screens />
		</ErrorBoundary>
	</React.StrictMode>,
	document.getElementById('root')
);

