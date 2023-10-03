import React from 'react';
import {Space, Button} from 'antd';
import {useFormikContext} from 'formik';

const SubmitReset = ({submitLabel, resetLabel = 'Сброс', children}) => {
	const {handleSubmit, handleReset, isSubmitting, status} = useFormikContext();

	return (
		<div className="d-flex justify-content-between">
			<div>{children}</div>
			<Space className="">
				<Button
					type="default"
					onClick={handleReset}
					disabled={(status && status.isLoading) || isSubmitting}
					htmlType="reset"
				>
					{resetLabel}
				</Button>
				<Button
					type="primary"
					onClick={handleSubmit}
					disabled={status && status.isLoading}
					loading={isSubmitting}
					htmlType="submit"
				>
					{submitLabel}
				</Button>
			</Space>
		</div>
	);
};

export default SubmitReset;
