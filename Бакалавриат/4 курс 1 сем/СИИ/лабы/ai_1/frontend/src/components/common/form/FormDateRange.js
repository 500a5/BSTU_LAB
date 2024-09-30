import React from 'react';
import {useFormikContext} from 'formik';
import {Form as AntdForm, DatePicker} from 'antd';
import locale from 'antd/es/date-picker/locale/ru_RU'


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
	const {onBlur, onChange, value} = getFieldProps(name);
	const {setValue} = getFieldHelpers(name);

	const error = meta.touched && meta.error;

	const { RangePicker } = DatePicker;

	return (
		<AntdForm.Item
			hasFeedback={!!error || isValidating}
			label={label}
			required={props.required}
			validateStatus={isValidating ? 'validating' : (error ) ? 'error' : ''}
		>
			<RangePicker
				locale={locale}
				onChange={(m1, m2) => {
					if (m2[0] === "" || m2[1] === "")
						setValue(null)
					else
						setValue(m2)
				}}
				disabled={isSubmitting || (status && status.isLoading) || disabled}
				ref={ref}
				{...props}
			/>
		</AntdForm.Item>
	);
};

export default React.forwardRef(FormItem);
