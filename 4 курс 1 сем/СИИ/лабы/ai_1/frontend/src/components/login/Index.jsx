import React from 'react';
import * as Yup from 'yup';
import {Modal, Input, Row, Col, notification} from 'antd';
import {useHistory} from 'react-router-dom';
import {useFormikContext} from 'formik';
import ky from 'ky';
import {Formik, Form, Fog, FormItem, SubmitReset} from '../common/form';

const Login = () => {
	const history = useHistory();
	const host = process.env.REACT_APP_URL || 'http://127.0.0.1:8000'
	return (
		<Formik
			initialValues={{
				username: '',
				password: ''
			}}
			validationSchema={Yup.object().shape({
				username: Yup.string().required('Введите имя пользователя'),
				password: Yup.string().required('Введите пароль')
			})}
			onSubmit={async (values) => {
				try {
					const response = await ky
						.post(`${host}/auth/jwt/login`, {
							body: new URLSearchParams(values), timeout: 2 * 60 * 1000,
							credentials: 'include',
						});
					if (response.ok){
						history.push('/');
					} else {
						notification.error({
							message: 'Ошибка аутентификации',
							description: response.statusText
						})
					}
				} catch (err) {
					notification.error({
						message: 'Ошибка аутентификации',
						description: err.message
					});
				}
			}}
		>
			<FormContent />
		</Formik>
	);
};

const FormContent = () => {
	const {submitForm} = useFormikContext();

	return (
		<Modal
			visible
			closable={false}
			centered
			title="Авторизация"
			width="min(90vw, 1000px)"
			footer={<SubmitReset submitLabel="Войти" />}
		>
			<Fog>
				<Form layout="vertical">
					<Row gutter={16}>
						<Col xs={24} md={12}>
							<FormItem
								Component={Input}
								name="username"
								label="Имя пользователя"
								required
							/>
						</Col>
						<Col xs={24} md={12}>
							<FormItem
								Component={Input.Password}
								name="password"
								label="Пароль"
								required
							/>
						</Col>
					</Row>
				</Form>
			</Fog>
		</Modal>
	);
};

export default Login;
