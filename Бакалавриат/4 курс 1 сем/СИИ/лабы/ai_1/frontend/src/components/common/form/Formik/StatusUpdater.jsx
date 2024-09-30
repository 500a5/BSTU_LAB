import React from 'react';
import {useFormikContext} from 'formik';

const StatusUpdater = ({isLoading, children}) => {
	const {setStatus} = useFormikContext();

	React.useEffect(
		() => setStatus({isLoading: Boolean(isLoading)}),
		[isLoading]
	);

	return children;
};

export default StatusUpdater;
