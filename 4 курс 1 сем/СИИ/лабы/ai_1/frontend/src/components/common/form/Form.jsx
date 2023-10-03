import React from 'react';
import {useFormikContext} from 'formik';
import {Form as AntdForm} from 'antd';

const Form = ({children, ...props}, ref) => {
	const {handleReset, handleSubmit} = useFormikContext();

	return (
		<AntdForm ref={ref} onSubmit={handleSubmit} onReset={handleReset} action="#" {...props}>
			{children}
		</AntdForm>
	);
};

export default React.forwardRef(Form);
