import React from 'react';
import StatusUpdater from './StatusUpdater';
import {Formik} from 'formik';

const FormFormik = ({isLoading, children, ...props}) => {
	return (
		<Formik {...props}>
			<StatusUpdater isLoading={isLoading}>
            	{children}
			</StatusUpdater>
		</Formik>
	);
};

export default FormFormik;
