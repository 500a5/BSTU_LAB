import React from 'react';
import {useFormikContext} from 'formik';
import {Spin} from 'antd';

const Fog = ({children}) => {
	const {isSubmitting, status} = useFormikContext();

	return (
		<Spin size="large" spinning={!!(isSubmitting || (status && status.isLoading))}>
			{children}
		</Spin>
	);
};

export default Fog;
