import React from 'react';
import {useFormikContext} from 'formik';
import {Form as AntdForm, Switch} from 'antd';

const FormItem = ({name, label, nonNative, disabled=false, ...props}, ref) => {
	const {
		getFieldMeta,
		getFieldProps,
		getFieldHelpers,
		status,
		isSubmitting,
		isValidating
	} = useFormikContext();

	const meta = getFieldMeta(name);
	const {onBlur, value} = getFieldProps(name);
	const {setValue} = getFieldHelpers(name);

	const error = meta.touched && meta.error;

	return (
		<AntdForm.Item
			hasFeedback={!!error || isValidating}
			help={error}
			label={label}
			required={props.required}
		>
			<Switch
				name={name}
				onBlur={onBlur}
				onChange={() => setValue(!value)}
				checked={value}
				disabled={isSubmitting || (status && status.isLoading) || disabled}
				ref={ref}
				{...props}
			/>
		</AntdForm.Item>
	);
};

export default React.forwardRef(FormItem);
